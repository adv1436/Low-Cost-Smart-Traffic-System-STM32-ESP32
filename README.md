# Low-Cost Smart Traffic System using STM32 and ESP32

## Overview

This project presents a low-cost intelligent urban traffic safety and predictive collision warning system designed for highly congested and accident-prone urban environments.

The system uses an STM32 Blue Pill as the main real-time traffic controller and an ESP32 as a smart monitoring and logging unit.

The project focuses on:
- Wrong-side vehicle detection
- Predictive collision warning
- Adaptive traffic signal control
- Emergency vehicle priority
- Intelligent traffic density monitoring
- UART-based dual-controller architecture

Unlike expensive AI-camera-based systems, this solution provides a low-cost embedded systems alternative suitable for smart city traffic applications.

---

# Features

- 4-Junction Traffic Signal Control
- Wrong-Side Vehicle Detection
- Predictive Collision Warning System
- Adaptive Traffic Density Control
- Emergency Vehicle Priority System
- Dual Buzzer Alert Mechanism
- UART Communication between STM32 and ESP32
- Real-Time Traffic Monitoring
- Smart Traffic Analytics through ESP32 Serial Monitor
- Low-Cost Smart City Traffic Architecture

---

# System Architecture

## STM32 Blue Pill (Main Controller)

Handles:
- Traffic signal sequencing
- IR sensor processing
- Wrong-side detection
- Collision warning logic
- Traffic density analysis
- Emergency signal priority
- Keypad input processing
- Buzzer alert generation

## ESP32 (Monitoring Controller)

Handles:
- Serial monitoring
- Traffic event logging
- Smart analytics display
- Future IoT expansion support

---

# Hardware Components

| Component | Quantity |
|---|---|
| STM32 Blue Pill | 1 |
| ESP32 DevKit V1 | 1 |
| IR Sensors | 2 |
| Red LEDs | 4 |
| Yellow LEDs | 4 |
| Green LEDs | 4 |
| Active Buzzers | 2 |
| 4×4 Matrix Keypad | 1 |
| Breadboard | 1 |
| 220Ω Resistors | 12 |
| Jumper Wires | Multiple |

---

# Pin Connections

## Traffic LEDs

| Junction | LED | STM32 Pin |
|---|---|---|
| J1 | Red | PB0 |
| J1 | Yellow | PB1 |
| J1 | Green | PB12 |
| J2 | Red | PB13 |
| J2 | Yellow | PB14 |
| J2 | Green | PB15 |
| J3 | Red | PA0 |
| J3 | Yellow | PA1 |
| J3 | Green | PA4 |
| J4 | Red | PA5 |
| J4 | Yellow | PA6 |
| J4 | Green | PA7 |

---

## Keypad Connections

| Keypad Pin | STM32 Pin |
|---|---|
| R1 | PB3 |
| R2 | PB4 |
| R3 | PB5 |
| R4 | PB8 |
| C1 | PB9 |
| C2 | PA8 |
| C3 | PA15 |
| C4 | PB6 |

---

## IR Sensors

| Sensor | STM32 Pin |
|---|---|
| IR1 | PA11 |
| IR2 | PA12 |

---

## Buzzers

| Buzzer | STM32 Pin |
|---|---|
| Buzzer 1 | PB7 |
| Buzzer 2 | PC13 |

---

## UART Communication

| STM32 | ESP32 |
|---|---|
| PA9 (TX) | GPIO16 (RX2) |
| PA10 (RX) | GPIO17 (TX2) |
| GND | GND |

---

# Working Principle

## Normal Traffic Operation
The system continuously performs normal 4-junction traffic signal sequencing.

## Wrong-Side Detection
Vehicle direction is identified using two IR sensors:
- IR1 → IR2 = Correct direction
- IR2 → IR1 = Wrong-side violation

## Predictive Collision Warning
The STM32 calculates the time difference between IR sensor activations to estimate vehicle movement speed and classify collision risk levels:
- Low Risk
- Medium Risk
- High Risk

## Adaptive Traffic Density Control
If prolonged vehicle presence is detected, the STM32 automatically extends green signal timing to reduce congestion.

## Emergency Vehicle Priority
Using the keypad:
- A → Emergency Road 1
- B → Emergency Road 2
- C → Emergency Road 3
- D → Emergency Road 4

The selected junction receives immediate green priority while all other roads remain red.

---

# Results

## Emergency Vehicle Priority

- Emergency priority activated for Road 1
- Emergency priority activated for Road 2
- Emergency priority activated for Road 3
- Emergency priority activated for Road 4

## Traffic Density Detection

- High traffic density successfully detected
- Automatic green time extension performed

## Wrong-Side Vehicle Detection

- Low-risk wrong-side detection
- High-risk collision warning detection

---

# Demo Video

Add your demo video link here:

```text
Demo Video: [Paste YouTube or Google Drive Link]
```

---

# Future Enhancements

- IoT Cloud Connectivity
- AI Camera-Based Vehicle Detection
- FPGA/VLSI Traffic Acceleration
- Distributed Smart Junction Communication
- GSM Emergency Notification System
- Real-Time Smart City Traffic Analytics

---

# Applications

- Smart Cities
- Urban Traffic Management
- Accident Prevention Systems
- Intelligent Transportation Systems
- Embedded Smart Infrastructure

---

# Author

Developed using STM32 and ESP32 embedded systems architecture for low-cost intelligent urban traffic management applications.

---

# License

This project is licensed under the MIT License.
