# ESP32-Based Robotic Strawberry-Picking Rover

A multi-controller robotic rover designed for strawberry-picking applications, integrating an ESP32-based mobile rover, a 4-DOF robotic arm, glove-based gesture control, ESP-NOW wireless communication, Wi-Fi control, ESP32-CAM visual monitoring, and Raspberry Pi serial communication.

The project focuses on combining embedded systems, robotics, wireless communication, sensor integration, and real-time control into a single robotic platform.

---

## Project Overview

The ESP32-Based Robotic Strawberry-Picking Rover is a remotely controlled robotic system designed to assist with agricultural applications such as strawberry harvesting.

The system consists of multiple microcontrollers, each responsible for a specific subsystem:

- A **Glove ESP32** reads finger movements using flex/FSR sensors.
- An **Arm ESP32** receives the sensor data through ESP-NOW and converts it into servo movements.
- A **Rover ESP32** controls the rover's motors and provides Wi-Fi-based movement commands.
- An **ESP32-CAM** provides wireless camera functionality for visual monitoring.
- A **Raspberry Pi** is integrated for serial communication and system-level robotic arm feedback.
- A **4-DOF Waveshare RoArm M2 Pro** provides the robotic manipulation capability.

The architecture separates rover control, robotic-arm control, and visual monitoring across multiple embedded controllers.

---

# System Architecture

```text
                         ┌─────────────────────────┐
                         │     GLOVE CONTROLLER    │
                         │          ESP32          │
                         │                         │
                         │  Flex Sensors / FSRs    │
                         │  Finger Movement Input  │
                         └────────────┬────────────┘
                                      │
                                      │ ESP-NOW
                                      │
                                      ▼
                         ┌─────────────────────────┐
                         │      ARM CONTROLLER     │
                         │          ESP32          │
                         │                         │
                         │  Receive Sensor Data    │
                         │  Map Sensor → Servo     │
                         └────────────┬────────────┘
                                      │
                                      ▼
                         ┌─────────────────────────┐
                         │    4-DOF ROBOTIC ARM   │
                         │  Waveshare RoArm M2 Pro │
                         └─────────────────────────┘


       ┌────────────────────────────────────────────────────┐
       │                                                    │
       │                      WI-FI                         │
       │                                                    │
       ▼                                                    ▼

┌─────────────────────┐                         ┌─────────────────────┐
│     ROVER ESP32     │                         │     ESP32-CAM       │
│                     │                         │                     │
│  Motor Controller   │                         │  Camera Controller  │
│  Web Control        │                         │  JPEG Capture       │
└──────────┬──────────┘                         └─────────────────────┘
           │
           ▼
   ┌───────────────┐
   │ Rover Motors  │
   └───────────────┘


                    ┌──────────────────┐
                    │   Raspberry Pi   │
                    │                  │
                    │ Serial Interface │
                    │ Arm Feedback     │
                    └──────────────────┘

```

# Hardware Components

ESP32 - Main embedded controllers
ESP32-CAM - Wireless camera and image capture
Raspberry Pi - Serial communication and system integration
Waveshare RoArm M2 Pro - 4-DOF robotic arm
Flex Sensors - Finger movement detection
FSR Sensors - Pressure/finger input
BNO085 IMU - Motion/orientation sensing
DC Motors - Rover movement
Motor Driver - Motor direction and control
Servo Motors - Robotic arm movement
Rover Chassis - Mobile platform

# Technologies Used

Programming
* C
* C++

Embedded Platforms
* ESP32
* ESP32-CAM
* Raspberry Pi
* Arduino

Communication
* ESP-NOW
* Wi-Fi
* Serial / USB
* I²C

Embedded Libraries
* WiFi.h
* esp_now.h
* WebServer.h
* esp_camera.h
* ESP32Servo.h

Development Tools
* Arduino IDE
* Serial Monitor
* Git
* GitHub

# Project Structure

The repository contains the firmware for the different subsystems.

```text

ESP32-Based-Robotic-Strawberry-Picking-Rover/
│
├── Glove ESP32
│   └── FSR + ESP-NOW transmitter
│
├── Arm ESP32
│   ├── ESP-NOW receiver
│   └── Servo control
│
├── Rover ESP32
│   ├── Basic motor control
│   └── Wi-Fi web control
│
├── ESP32-CAM
│   └── Wi-Fi camera
│
└── README.md

```
# Setup & Installation

1. Install Arduino IDE

Install the Arduino IDE: https://www.arduino.cc/en/software
Configure the ESP32 board package through the Arduino IDE’s Board Manager.

⸻

2. Install Required Libraries

The project uses ESP32 libraries including WiFi, ESP-NOW, WebServer, ESP Camera and ESP32Servo

⸻
3. Configure Wi-Fi

For the Wi-Fi-enabled ESP32 controllers, configure:
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";

Replace these values with your local network credentials when running the firmware.

⸻

# Uploading the Firmware

For each ESP32 controller:

1. Connect the ESP32 to your computer through USB.
2. Open the corresponding .ino file in Arduino IDE.
3. Select the correct ESP32 board.
4. Select the appropriate COM/USB port.
5. Compile the firmware.
6. Upload the firmware.
7. Open the Serial Monitor.
8. Set the baud rate to: 115200
9. Verify the device initializes correctly.

# Testing Procedure

The system can be tested subsystem-by-subsystem.

Step 1 — Test the Glove
Verify that sensor readings are being captured correctly.
Monitor the serial output at: 115200 baud

Step 2 — Test ESP-NOW
Verify that the arm ESP32 successfully receives the transmitted sensor structure.
The received values should appear as: thumb,index,middle,ring,pinky

Step 3 — Test Servo Control
Verify that sensor values are mapped correctly to servo angles.
Test each servo individually before operating the complete robotic arm.

Step 4 — Test Rover Motors
Verify:
F → Forward
B → Backward
L → Left
R → Right
S → Stop

Step 5 — Test Wi-Fi Control
After the rover connects to Wi-Fi, check the IP address printed by the ESP32.
Then access: http://<ROVER-IP>/forward or the other available endpoints.

Step 6 — Test ESP32-CAM
Verify:
* Camera initialization
* Wi-Fi connection
* Frame capture
* Frame information through Serial Monitor

⸻

# Engineering Challenges

The project involved several embedded systems challenges:

Multi-controller coordination : Multiple ESP32 boards were used for different subsystems, requiring clear separation of responsibilities.

Wireless communication : ESP-NOW was implemented for direct communication between the glove controller and robotic-arm controller.

Sensor-to-servo mapping : Analog sensor values needed to be converted into usable servo positions.

Embedded debugging : Hardware and software debugging included issues involving:
* ESP32 boot modes
* Camera initialization
* Wi-Fi connectivity
* Serial communication
* Peripheral integration

Hardware integration : The system required integration between:
* ESP32
* ESP32-CAM
* Raspberry Pi
* Sensors
* Motor drivers
* Servos
* Robotic arm
* Rover chassis
  
⸻
# Key Features

* Agricultural robotics application
* 4-DOF robotic arm
* Glove-based gesture control
* ESP-NOW wireless communication
* Wi-Fi rover control
* ESP32-CAM integration
* Raspberry Pi serial communication
* Multi-ESP32 controller architecture
* Sensor-to-servo mapping
* Remote rover motor control
* Embedded C/C++ development
