# 🚗 Smartphone-Based Vehicle Control System for Disabled People

An IoT-Based Smart Vehicle Control System Using Bluetooth and Arduino.


## 📌 Project Overview

The **Smartphone-Based Vehicle Control System for Disabled People** is an assistive technology project designed to make vehicle movement and control more accessible through a smartphone.

The system allows users to control a motorized vehicle using a Bluetooth-enabled Android smartphone instead of traditional physical controls. An Arduino microcontroller receives commands from the smartphone through a Bluetooth module and controls the vehicle's motors accordingly.

The project also incorporates an **HC-SR04 ultrasonic sensor** for obstacle detection and basic obstacle avoidance. When an obstacle is detected within a predefined distance, the system automatically stops the vehicle and performs a basic avoidance maneuver.

Additional features include front lights, rear lights, parking lights, an electronic horn, speed control, and directional movement.

This project demonstrates how embedded systems, Bluetooth communication, and sensor-based automation can be integrated to develop assistive mobility solutions.

---

## 🎯 Project Objectives

- Develop a smartphone-controlled vehicle for people with physical disabilities.
- Provide an alternative to conventional manual vehicle controls.
- Enable wireless vehicle operation through Bluetooth communication.
- Implement forward, backward, left, and right movement.
- Integrate ultrasonic sensors for obstacle detection.
- Implement basic automatic obstacle avoidance.
- Provide adjustable vehicle speed through smartphone commands.
- Integrate lighting and horn control for additional functionality.
- Explore affordable assistive mobility technology using Arduino and IoT concepts.

---

## ✨ Key Features

| Feature | Description |
|---|---|
| 📱 Smartphone Control | Control the vehicle using an Android smartphone. |
| 📡 Bluetooth Communication | Wireless communication between smartphone and Arduino. |
| ⬆️ Forward Movement | Move the vehicle forward. |
| ⬇️ Reverse Movement | Move the vehicle backward. |
| ⬅️ Left Movement | Turn the vehicle left. |
| ➡️ Right Movement | Turn the vehicle right. |
| ⚡ Speed Control | Adjust motor speed using smartphone commands. |
| 🚧 Obstacle Detection | Detect nearby obstacles using HC-SR04. |
| 🔄 Obstacle Avoidance | Perform a basic reverse-and-turn maneuver when an obstacle is detected. |
| 💡 Front Lights | Switch front headlights ON/OFF. |
| 🔴 Rear Lights | Switch rear lights ON/OFF. |
| 📢 Electronic Horn | Control the horn through the smartphone. |
| 🅿️ Parking Lights | Control parking lights through the smartphone. |

---

## 🛠️ Hardware Requirements

The following components are used to develop the prototype:

| Sl. No. | Component | Purpose |
|---|---|---|
| 1 | Arduino Uno | Main microcontroller |
| 2 | HC-05 / HC-06 Bluetooth Module | Wireless communication |
| 3 | HC-SR04 Ultrasonic Sensor | Obstacle detection |
| 4 | L298N Motor Driver | DC motor control |
| 5 | DC Gear Motors | Vehicle movement |
| 6 | Robot Car Chassis | Vehicle structure |
| 7 | Wheels | Vehicle mobility |
| 8 | LED Lights | Front, rear and parking indicators |
| 9 | Buzzer / Horn | Audio indication |
| 10 | Battery Pack | Power supply |
| 11 | Connecting Wires | Electrical connections |
| 12 | Android Smartphone | Vehicle control interface |

---

## 💻 Software Requirements

- Arduino IDE
- Arduino C/C++ Programming
- Bluetooth Terminal / Bluetooth RC Controller Android Application
- HC-05 / HC-06 Bluetooth Communication
- Embedded C Programming Concepts

---

## 🔌 Hardware Connections

### 1. Motor Driver Connections

The motor driver is connected to the Arduino to control the movement of the vehicle.

| Arduino Pin | Motor Driver Connection |
|---|---|
| D3 | IN1 |
| D5 | IN2 |
| D6 | IN3 |
| D11 | IN4 |

### 2. Bluetooth Module Connections

| Bluetooth Module | Arduino |
|---|---|
| TXD | RX (D0) |
| RXD | TX (D1) |
| VCC | 5V (as supported by module board) |
| GND | GND |

**Note:** The Bluetooth module's RX input may require voltage level shifting when connected to a 5V Arduino TX pin. Disconnect the Bluetooth serial connections while uploading code if they interfere with programming.

### 3. Ultrasonic Sensor Connections

| HC-SR04 Pin | Arduino Pin |
|---|---|
| VCC | 5V |
| GND | GND |
| TRIG | D12 |
| ECHO | D13 |

### 4. LED and Horn Connections

| Component | Arduino Pin |
|---|---|
| Front LED | D9 |
| Rear LED | D8 |
| Horn | D7 |
| Parking LED | D4 |

---

## ⚙️ Working Principle

The system works through wireless communication between an Android smartphone and an Arduino-based vehicle.

### Step 1: Smartphone Connection

The user connects their Android smartphone to the Bluetooth module installed in the vehicle.

### Step 2: Sending Commands

The smartphone application sends predefined character-based commands through Bluetooth.

### Step 3: Arduino Processing

The Arduino receives the Bluetooth commands through serial communication and processes them using a switch-case control structure.

### Step 4: Motor Control

Based on the received command, Arduino sends signals to the motor driver, which controls the DC motors to move the vehicle in the required direction.

### Step 5: Obstacle Detection

The HC-SR04 ultrasonic sensor continuously measures distance when a forward movement command is received.

If an obstacle is detected within the configured threshold of 8 cm:

1. The vehicle stops.
2. The vehicle moves backward briefly.
3. The vehicle turns right.
4. The sensor checks the distance again.
5. If an obstacle remains, a second reverse-and-left maneuver is performed.

### Step 6: Additional Controls

The user can also control the headlights, rear lights, parking lights, horn, and motor speed using the smartphone.

---

## 📱 Bluetooth Command Reference

The following commands are used by the smartphone application to control the vehicle.

### Movement Commands

| Command | Function |
|---|---|
| F | Move Forward |
| B | Move Backward |
| L | Turn Left |
| R | Turn Right |
| G | Forward Left |
| I | Forward Right |
| H | Backward Left |
| J | Backward Right |
| S | Stop |

### Lighting and Horn Commands

| Command | Function |
|---|---|
| W | Front LED ON |
| w | Front LED OFF |
| U | Rear LED ON |
| u | Rear LED OFF |
| X | Parking LED ON |
| x | Parking LED OFF |
| V | Horn ON |
| v | Horn OFF |

### Speed Control Commands

| Command | Motor Speed |
|---|---:|
| 0 | 100 |
| 1 | 140 |
| 2 | 153 |
| 3 | 165 |
| 4 | 178 |
| 5 | 191 |
| 6 | 204 |
| 7 | 216 |
| 8 | 229 |
| 9 | 242 |
| q | 255 |

*Motor speed values range from 0 to 255 using Arduino PWM control.*

---

## 🧠 Technologies Used

- **Arduino:** Controls the complete vehicle operation.
- **Bluetooth:** Establishes wireless communication between the smartphone and vehicle.
- **Ultrasonic Sensing:** Measures the distance between the vehicle and nearby obstacles.
- **Embedded C/C++:** Implements vehicle movement, sensor processing, and control logic.
- **PWM (Pulse Width Modulation):** Controls the speed of DC motors.
- **Motor Driver Technology:** Enables bidirectional motor operation.

---

## 🏗️ System Architecture

```text
       ANDROID SMARTPHONE
               |
               | Bluetooth Commands
               |
          HC-05 MODULE
               |
               |
          ARDUINO UNO
               |
       +-------+--------+
       |       |        |
       |       |        |
   MOTOR    HC-SR04   LED / HORN
   DRIVER   SENSOR     CONTROL
       |       |
       |       |
   DC MOTORS  OBSTACLE
       |      DETECTION
       |
   VEHICLE MOVEMENT
```

---

## 📂 Project Structure

```text
Smartphone-Based-Vehicle-Control-System/
│
├── Arduino_Code/
│   └── vehicle_control.ino
│
├── Circuit_Diagram/
│   └── circuit_diagram.png
│
├── Images/
│   ├── vehicle_front.jpg
│   ├── vehicle_side.jpg
│   └── project_setup.jpg
│
├── Documentation/
│   └── project_report.pdf
│
└── README.md
```

*The above is a suggested folder structure. Add the folders and files according to your actual project.*

---

## 🚀 Installation and Setup

### Step 1: Install Arduino IDE

Download and install Arduino IDE from:

https://www.arduino.cc/en/software

### Step 2: Connect Hardware

Connect the Arduino, Bluetooth module, motor driver, ultrasonic sensor, motors, LEDs, and horn according to the connection tables.

### Step 3: Upload Arduino Code

1. Open Arduino IDE.
2. Open the `vehicle_control.ino` file.
3. Select the appropriate Arduino board.
4. Select the correct COM port.
5. Upload the program.

### Step 4: Connect Smartphone

1. Enable Bluetooth on the Android smartphone.
2. Pair the smartphone with the HC-05 / HC-06 module.
3. Open a compatible Bluetooth controller application.
4. Connect to the paired Bluetooth module.

### Step 5: Control the Vehicle

Use the smartphone application to send movement, speed, lighting, and horn commands.

---

## 🔮 Future Enhancements

The project can be further improved with the following features:

- Voice-controlled vehicle operation.
- GPS-based vehicle location tracking.
- GSM-based emergency notification system.
- IoT-based remote monitoring.
- Camera-based obstacle detection.
- Advanced autonomous navigation.
- Multiple ultrasonic sensors for wider obstacle coverage.
- Emergency stop functionality.
- Joystick-based smartphone control.
- Integration with advanced assistive mobility interfaces.
- Improved fail-safe braking and obstacle detection systems.

---

## 🌍 Applications

- Assistive mobility technology research.
- Educational IoT and embedded systems projects.
- Smartphone-controlled robotic vehicles.
- Prototype development for accessible transportation.
- Research into alternative vehicle control interfaces.

---

## ⚠️ Safety Disclaimer

This project is an educational prototype demonstrating smartphone-based vehicle control and basic obstacle avoidance.

It is not a certified mobility device or a road-ready vehicle. The ultrasonic sensor provides limited obstacle detection, and the current avoidance algorithm does not guarantee collision prevention.

It should not be used to transport people or as a replacement for a wheelchair or other mobility assistance device. Any real-world assistive mobility application requires professional engineering, comprehensive safety testing, reliable emergency controls, and appropriate certification.

---

## 👨‍💻 Project Information

**Project Title:** Smartphone-Based Vehicle Control System for Disabled People

**Domain:** IoT | Embedded Systems | Assistive Technology | Robotics

**Controller:** Arduino Uno

**Communication:** Bluetooth

**Sensor:** HC-SR04 Ultrasonic Sensor

**Programming Language:** Embedded C/C++

---

## 📜 License

This project is developed for educational and research purposes. You are welcome to study the implementation and build upon the concepts with appropriate attribution.

---

## ⭐ Acknowledgement

This project represents an effort to explore how technology can contribute to accessibility and independent mobility through affordable embedded systems and smartphone-based control.

**Technology for Accessibility. Innovation for Everyone.**