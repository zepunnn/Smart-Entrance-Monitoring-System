# 🚪 Smart Entrance Monitoring System

![IoT](https://img.shields.io/badge/IoT-Project-blue)
![Platform](https://img.shields.io/badge/Platform-ESP8266-green)
![License](https://img.shields.io/badge/License-MIT-yellow)
![Status](https://img.shields.io/badge/Status-Development-orange)

A lightweight IoT-based system that detects human presence and automatically displays a welcome message. Perfect for smart stores, offices, or interactive environments.

---

## ✨ Features

- 👤 Human detection using PIR sensor  
- 💬 Automatic welcome message on LCD  
- 📡 WiFi-enabled via ESP8266  
- 📱 Optional monitoring with Blynk  
- ⚡ Efficient and simple architecture  

---

## 🧠 Concept

This project simulates a **smart entrance system**:

> When a person enters → system detects → displays greeting message.

## 💬 Example Output

```bash
$ system.detect()
> Hello!
> Welcome 👋
```
---

## 🏗️ System Architecture
```text
      ┌─────────────┐
      │ PIR Sensor  │
      └──────┬──────┘
             │
             ▼
      ┌─────────────┐
      │  ESP8266    │
      └──────┬──────┘
         ┌───┴───┐
         ▼       ▼
  ┌─────────┐ ┌─────────┐
  │   LCD   │ │  Blynk  │
  └─────────┘ └─────────┘
```
---

## 🛠️ Tech Stack

- **ESP8266 (NodeMCU / Wemos D1 Mini)**  
- **PIR Motion Sensor**  
- **LCD I2C Display**  
- **Blynk IoT Platform (optional)**  

---

## 📂 Project Structure
```text
smart-entrance-monitoring/
│
├── src/
│ ├── main.ino
│ ├── config.h
│ ├── sensor.h
│ ├── sensor.cpp
│ ├── display.h
│ ├── display.cpp
│ ├── blynk_handler.h
│ └── blynk_handler.cpp
│
├── README.md
└── LICENSE
```

---

## ⚙️ How It Works

1. PIR sensor detects motion  
2. ESP8266 processes signal  
3. LCD displays message  
4. Optional: send data to Blynk  

---

## 🚀 Getting Started

### 🔧 Requirements

- ESP8266 board  
- PIR Motion Sensor  
- LCD I2C  
- Jumper wires  
- Internet connection  

### ⚡ Installation

```bash
git clone https://github.com/yourusername/smart-entrance-monitoring.git
cd smart-entrance-monitoring
```

---

## 🔌 Setup

Follow these steps to run the project:

1. Open the project using **Arduino IDE** or **PlatformIO**  
2. Configure your WiFi credentials:
   - SSID  
   - Password  
3. Add your **Blynk Auth Token** (optional)  
4. Upload the code to your **ESP8266**  

---

## 💡 Use Cases

This project can be applied in various scenarios:

- 🏪 Retail stores  
- 🏢 Office entrances  
- 🏠 Smart home systems  
- 🎪 Exhibition booths

---

## 📜 License

This project is licensed under the **MIT License**.

---

## 🤝 Contributing

This project was developed collaboratively by:

- **Fakhri Muhammad Al Hisyam**  
- **Aulia Ivy Yasmin**  
- **Ivan Febrianto Lalo**  

Contributions, issues, and feature requests are welcome.

---

## 🌟 Author

Developed as part of an IoT and Microprocessor project.
