# 🚪 Smart Entrance Monitoring System

![IoT](https://img.shields.io/badge/IoT-Project-blue)
![ESP32](https://img.shields.io/badge/Platform-ESP32-green)
![Blynk](https://img.shields.io/badge/Cloud-Blynk-purple)
![License](https://img.shields.io/badge/License-MIT-yellow)

An IoT-based smart entrance system that detects approaching visitors using an HC-SR04 ultrasonic sensor, displays real-time welcome messages on an LCD, provides visual feedback through an LED indicator, and enables remote monitoring via the Blynk platform.

---

## 📋 Project Overview

The **Smart Entrance Monitoring System** is designed to improve visitor interaction at entrance points through Internet of Things (IoT) technology. The system utilizes an HC-SR04 ultrasonic sensor to detect approaching individuals and processes the sensor data using an ESP32 microcontroller.

When a visitor is detected within a predefined distance, the system automatically displays a welcome message on the LCD, activates an LED indicator, and sends monitoring data to the Blynk platform. This project demonstrates the integration of embedded systems, sensors, wireless communication, and cloud-based monitoring in a practical real-world application.

---

## ✨ Features

* 📏 Visitor detection using HC-SR04 ultrasonic sensor
* 💬 Automatic welcome message displayed on LCD
* 💡 Visual feedback through LED indicators
* 📡 Wi-Fi connectivity powered by ESP32
* 📱 Real-time monitoring with Blynk
* ⚡ Lightweight and efficient IoT implementation

---

## 🧠 Concept

This project simulates a smart entrance system:

> When a person approaches the entrance → the system detects their presence → displays a greeting message → updates the monitoring dashboard.

### 💬 Example Output

```bash
$ system.detect()
> Hello!
> Welcome 👋
```

---

## 🏗️ System Architecture

```text
      ┌─────────────┐
      │   HC-SR04   │
      └──────┬──────┘
             │
             ▼
      ┌─────────────┐
      │    ESP32    │
      └──────┬──────┘
         ┌───┼───┐
         ▼   ▼   ▼
      LCD   LED Blynk
```

---

## 🔧 Hardware Components

| Component                 | Description                                           |
| ------------------------- | ----------------------------------------------------- |
| ESP32 Development Board   | Main microcontroller with built-in Wi-Fi connectivity |
| ESP32 Expansion Board     | Simplifies wiring and power distribution              |
| HC-SR04 Ultrasonic Sensor | Detects visitor distance                              |
| LCD I2C 16x2              | Displays welcome messages                             |
| LED Indicator             | Provides visual status feedback                       |
| Jumper Wires              | Hardware connections                                  |
| USB Cable                 | Programming and power supply                          |
| Blynk Platform            | IoT monitoring dashboard                              |

---

## ⚙️ System Workflow

1. The HC-SR04 continuously measures the distance in front of the entrance.
2. The ESP32 processes the sensor readings.
3. When a visitor is detected within the configured threshold:

   * The LCD displays a welcome message.
   * The LED indicator turns on.
   * Monitoring data is sent to Blynk.
4. The system returns to standby mode and waits for the next detection.

---

## 🚀 Getting Started

### 🔧 Requirements

* ESP32 Development Board
* ESP32 Expansion Board
* HC-SR04 Ultrasonic Sensor
* LCD I2C 16x2
* LED Indicator
* Jumper Wires
* USB Cable
* Arduino IDE or PlatformIO
* Blynk Account (Optional)

### 📥 Installation

```bash
git clone https://github.com/yourusername/smart-entrance-monitoring.git
```

### 🔌 Setup

1. Open the project using Arduino IDE or PlatformIO.
2. Configure your Wi-Fi SSID and password.
3. Add your Blynk Authentication Token.
4. Connect all hardware components according to the circuit design.
5. Upload the code to the ESP32.
6. Power the system and begin monitoring.

---

## 🎯 Objectives

* Automate visitor detection at entrance points.
* Provide real-time visual interaction through LCD and LED indicators.
* Enable IoT monitoring through cloud connectivity.
* Demonstrate practical implementation of embedded systems and IoT technologies.

---

## 💡 Use Cases

* 🏪 Retail Stores
* 🏢 Office Entrances
* 🏠 Smart Home Systems
* 🎪 Exhibition Booths
* 🏫 Educational IoT Demonstrations

---

## 📈 Future Improvements

* Visitor counting system
* Mobile push notifications
* Data logging and analytics
* Face recognition integration
* Voice greeting system

---

## 📷 Project Demo

### Hardware Prototype

Add images of the assembled hardware prototype here.

```text
docs/prototype.jpg
```

### Blynk Dashboard

Add screenshots of the Blynk monitoring dashboard here.

```text
docs/blynk-dashboard.png
```

### System Demonstration

Add a short demonstration video or GIF showcasing the system operation.

```text
docs/demo-video.mp4
```

---

## 👥 Contributors

| Name       | Contribution                                                                                                                                |
| ---------- | ------------------------------------------------------------------------------------------------------------------------------------------- |
| **Fakhri** | Designed and assembled the hardware circuit, configured the ESP32 Expansion Board, and developed the initial Arduino IDE project framework. |
| **Ivan**   | Implemented the core system logic in Arduino IDE, including ultrasonic sensor processing, LED control, and LCD interaction.                 |
| **Ivy**    | Integrated the system with the Blynk IoT platform, configured the monitoring dashboard, and validated real-time data transmission.          |

---

## 🙏 Acknowledgements

We would like to express our sincere gratitude to our lecturers, laboratory assistants, and all team members who provided guidance and support throughout the development of this project.

---

## 📜 License

This project is licensed under the **MIT License**.

---

## 🌟 Developed For

**Final Project – Bachelor of Telecommunication Engineering**

**Smart Entrance Monitoring System Using Internet of Things (IoT) Technology**
