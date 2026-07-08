// ═══════════════════════════════════════════════════════════
//  SMART LAMP ESP32 - DEBUGGING VERSION
// ═══════════════════════════════════════════════════════════

#define BLYNK_TEMPLATE_ID "TMPL6ivIPOODK"
#define BLYNK_TEMPLATE_NAME "Smart Lamp"
#define BLYNK_AUTH_TOKEN "Ogg2Kka0Jw5f8ILlPzOEBvQKy5xxEWKI"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ── WiFi Credentials ───────────────────────────────────────
char ssid[] = "Ivan";
char pass[] = "Gugugaga";

// ── Pin definitions ────────────────────────────────────────
#define TRIG_PIN  27   
#define ECHO_PIN  14   
#define LED_PIN   13   

// LCD I2C: SDA=D21, SCL=D22
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ── Konstanta ──────────────────────────────────────────────
#define JARAK_THRESHOLD  15     // cm
#define LED_DURASI       3000  // ms

// ── State ──────────────────────────────────────────────────
bool          sedangAda       = false;
unsigned long lastDetect      = 0;
bool          kontrolManual   = false;
bool          ledManualState  = false;

// ── Helper: baca jarak HC-SR04 ─────────────────────────────
long bacaJarak() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long durasi = pulseIn(ECHO_PIN, HIGH, 30000);
  if (durasi == 0) return 999;
  return durasi * 0.034 / 2;
}

// ── Blynk Handler: Switch LED Manual (V0) ──────────────────
BLYNK_WRITE(V0) {
  int nilai = param.asInt();
  
  Serial.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
  Serial.print("[V0] Terima input: ");
  Serial.println(nilai);
  Serial.print("[V0] Mode manual aktif? ");
  Serial.println(kontrolManual ? "YA" : "TIDAK");
  
  ledManualState = nilai;
  
  if (kontrolManual) {
    digitalWrite(LED_PIN, ledManualState ? HIGH : LOW);
    
    // Baca balik status pin buat mastiin
    int pinState = digitalRead(LED_PIN);
    Serial.print("[V0] Pin LED setelah write: ");
    Serial.println(pinState ? "HIGH" : "LOW");
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" MODE: MANUAL   ");
    lcd.setCursor(0, 1);
    lcd.print(ledManualState ? " LED: ON        " : " LED: OFF       ");
    
    Blynk.virtualWrite(V1, ledManualState ? "LED: ON (Manual)" : "LED: OFF (Manual)");
  } else {
    Serial.println("[V0] SKIP - Mode sedang AUTO");
  }
  Serial.println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━");
}

// ── Blynk Handler: Mode Auto/Manual (V2) ───────────────────
BLYNK_WRITE(V2) {
  kontrolManual = param.asInt();
  
  Serial.println("════════════════════════════");
  Serial.print("[V2] Mode diubah ke: ");
  Serial.println(kontrolManual ? "MANUAL" : "AUTO");
  
  if (!kontrolManual) {
    // Kembali ke mode auto
    sedangAda = false;
    digitalWrite(LED_PIN, LOW);
    
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  MODE: AUTO    ");
    lcd.setCursor(0, 1);
    lcd.print(" Mendeteksi...  ");
    
    Blynk.virtualWrite(V1, "Mode: AUTO");
    Blynk.virtualWrite(V0, 0);
    
  } else {
    // Beralih ke mode manual
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(" MODE: MANUAL   ");
    lcd.setCursor(0, 1);
    lcd.print(" LED: OFF       ");
    
    digitalWrite(LED_PIN, LOW);
    ledManualState = false;
    
    Blynk.virtualWrite(V1, "Mode: MANUAL");
    Blynk.virtualWrite(V0, 0);
    
    Serial.println("[V2] Siap terima kontrol manual");
  }
  Serial.println("════════════════════════════");
}

// ══════════════════════════════════════════════════════════
void setup() {
  Serial.begin(115200);
  delay(1000);
  
  Serial.println("\n\n");
  Serial.println("╔════════════════════════════════╗");
  Serial.println("║   SMART LAMP - DEBUG MODE      ║");
  Serial.println("╚════════════════════════════════╝");

  // Setup pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(TRIG_PIN, LOW);
  digitalWrite(LED_PIN, LOW);
  
  Serial.print("[SETUP] LED Pin (");
  Serial.print(LED_PIN);
  Serial.println(") set sebagai OUTPUT");

  // Setup LCD
  Wire.begin(21, 22);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0, 0);
  lcd.print("  Menghubungkan ");
  lcd.setCursor(0, 1);
  lcd.print("   ke WiFi...   ");

  Serial.println("[SETUP] Koneksi WiFi...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  WiFi Terhubung");
  lcd.setCursor(0, 1);
  lcd.print("  Sistem Siap   ");
  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("  MODE: AUTO    ");
  lcd.setCursor(0, 1);
  lcd.print(" Mendeteksi...  ");

  Serial.println("[SETUP] Blynk Connected!");
  Serial.println("[SETUP] Threshold: " + String(JARAK_THRESHOLD) + " cm");
  
  Blynk.virtualWrite(V1, "Sistem Siap");
  Blynk.virtualWrite(V2, 0);
  Blynk.virtualWrite(V0, 0);
  
  Serial.println("[SETUP] Setup selesai!\n");
}

// ══════════════════════════════════════════════════════════
void loop() {
  Blynk.run();

  if (!kontrolManual) {
    // MODE AUTO
    long jarak = bacaJarak();

    if (jarak < JARAK_THRESHOLD) {
      lastDetect = millis();

      if (!sedangAda) {
        sedangAda = true;
        digitalWrite(LED_PIN, HIGH);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  ** WELCOME ** ");
        lcd.setCursor(0, 1);
        lcd.print(" Ada Gerakan!   ");

        Serial.println("[AUTO] Gerakan terdeteksi! LED ON");
        Blynk.virtualWrite(V1, "Gerakan Terdeteksi!");
        Blynk.virtualWrite(V0, 1);
      }

    } else {
      if (sedangAda && millis() - lastDetect >= LED_DURASI) {
        sedangAda = false;
        digitalWrite(LED_PIN, LOW);

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("  MODE: AUTO    ");
        lcd.setCursor(0, 1);
        lcd.print(" Mendeteksi...  ");

        Serial.println("[AUTO] LED OFF - Standby");
        Blynk.virtualWrite(V1, "Standby");
        Blynk.virtualWrite(V0, 0);
      }
    }
  } else {
    // MODE MANUAL - LED dikontrol penuh dari Blynk
    // Loop ga ngapa-ngapain, biar ga interfere
  }

  delay(200);
}