# Traffic Light System with Adjustable Timer using FSM and Timer Interrupts

## 🚦 Project Overview

This project implements a traffic light system where the light timings can be dynamically adjusted using push buttons. It uses the **Finite State Machine (FSM)** model to manage the states of the traffic lights, ensuring efficient and organized state transitions. The system is powered by **Timer Interrupts**, enabling precise timing control and responsiveness.

---

## ✨ Key Features

- **Dynamic Time Adjustment**: Modify red, yellow, and green light durations using physical buttons.
- **FSM Implementation**: Ensures smooth and predictable transitions between states (Red, Yellow, Green).
- **Timer Interrupts**: Achieves precise control over timing without busy-waiting.
- **Scalable Design**: Easily adaptable to different traffic light configurations or additional features.
- **Real-Time Responsiveness**: Button inputs are processed in real time thanks to interrupt handling.

---

## 🛠️ Technical Details

- **Microcontroller**: Compatible with popular platforms like STM32, AVR, or Arduino.
- **FSM States**:  
  - `RED`: Vehicles stop.  
  - `YELLOW`: Warning state for upcoming transition.  
  - `GREEN`: Vehicles move.  
  - `ADJUST`: Special state for adjusting light durations via buttons.  
- **Inputs**:  
  - Button 1: Increase current light duration.  
  - Button 2: Decrease current light duration.  
  - Button 3: Save adjustments and return to normal operation.  
- **Outputs**: LED indicators for each light (Red, Yellow, Green).

---

## ⚙️ How It Works

1. **Normal Operation**:
   - Lights cycle through Red → Yellow → Green based on preset durations.  
   - Timer interrupts trigger FSM transitions.

2. **Adjustment Mode**:
   - When the system enters adjustment mode, the user can modify light durations.  
   - Button presses are debounced and handled via interrupts for precision.  
   - Changes are saved to EEPROM (optional) for persistence.

---

## 🔧 Hardware Requirements

- Microcontroller (e.g., STM32, Arduino Uno, or equivalent).
- 3 LEDs (Red, Yellow, Green) with resistors.
- 3 Push Buttons for control.
- Power supply.

---
