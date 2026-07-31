# 🤖 Smart Medical Delivery Robot

An Embedded Systems project based on **ATmega32** that delivers food and medicine to hospital patients safely and efficiently. The robot can receive delivery requests, navigate to the patient's room, notify the patient upon arrival, open a medicine drawer automatically, and return to its starting point.

---

## 📌 Project Overview

The main objective of this project is to reduce direct contact between healthcare workers and patients while improving the efficiency of delivering food and medication inside hospitals.

The robot is capable of:

- Delivering food and medicine to patients.
- Displaying patient and medicine information.
- Measuring temperature.
- Avoiding obstacles (optional).
- Following a predefined line (optional).
- Opening and closing the medicine drawer automatically.
- Controlling the robot via Bluetooth.
- Providing visual and audio status notifications.

---

## ✨ Features

- ✅ ATmega32-based Embedded System
- ✅ LCD User Interface
- ✅ Keypad for User Input
- ✅ DC Motor Control using L298N/L293D
- ✅ Servo-Controlled Medicine Drawer
- ✅ Temperature Monitoring using LM35
- ✅ Bluetooth Control (HC-05)
- ✅ Buzzer Notification
- ✅ Status LEDs
- ✅ Emergency Stop Button
- ✅ Obstacle Detection (HC-SR04) *(Optional)*
- ✅ Line Following (IR Sensors) *(Optional)*
- ✅ RTC for Medicine Schedule *(Optional)*
- ✅ EEPROM Data Storage *(Optional)*
- ✅ Load Cell for Medicine Pickup Detection *(Optional)*

---

# 🛠 Hardware Components

| Component | Description |
|------------|-------------|
| ATmega32 | Main Microcontroller |
| L298N / L293D | Motor Driver |
| DC Gear Motors | Robot Movement |
| LCD 16x2 / 20x4 | User Interface |
| Keypad 4x4 | User Input |
| LM35 | Temperature Sensor |
| HC-SR04 | Obstacle Detection |
| IR Sensors | Line Following |
| Servo Motor | Drawer Opening |
| Limit Switch | Drawer Position Detection |
| HC-05 | Bluetooth Communication |
| Buzzer | Audio Notification |
| LEDs | Robot Status |
| RTC DS3231 | Medicine Schedule |
| Load Cell + HX711 | Detect Medicine Pickup |
| Emergency Button | Emergency Stop |

---

# 📂 Project Structure

```
Smart-Medical-Delivery-Robot/

├── Docs/
├── Firmware/
│   ├── Inc/
│   └── Src/
├── Hardware/
├── Proteus/
├── Images/
├── Videos/
└── README.md
```

---

# ⚙️ System Workflow

1. Power ON the robot.
2. Enter room number using Keypad.
3. Select medicine or food.
4. Press Start.
5. Robot begins moving.
6. Detects obstacles or follows line.
7. Measures temperature.
8. Reaches destination.
9. Sounds Buzzer.
10. Opens medicine drawer.
11. Waits until medicine is taken.
12. Closes drawer.
13. Returns to the starting point.

---

# 💻 Software Modules

- DIO Driver
- LCD Driver
- Keypad Driver
- ADC Driver
- LM35 Driver
- Motor Driver
- Servo Driver
- Bluetooth Driver
- UART Driver
- Buzzer Driver
- HC-SR04 Driver
- Timer Driver
- External Interrupt Driver

---

# 📸 Project Images

Add screenshots here.

```
Images/
├── Robot.jpg
├── Circuit.png
├── LCD.png
├── Proteus.png
```

---

# 🎥 Demo Video

Add your demonstration video inside the **Videos** folder or attach a YouTube link.

---

# 🔧 Development Environment

- Microchip Studio
- AVR-GCC
- Proteus 8
- Embedded C
- Git & GitHub

---

# 🚀 Future Improvements

- Wi-Fi Monitoring
- Mobile Application
- RFID Patient Identification
- Voice Notification
- Automatic Charging Station
- AI-Based Path Planning

---

# 👨‍💻 Author

**Mohammed Ghaleb**

Embedded Systems Engineer

---

# 📜 License

This project is developed for educational purposes.
