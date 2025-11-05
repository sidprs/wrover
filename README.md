# odyssey rover subsytem 

## Overview
Wrover is a CubeSat-inspired project designed to demonstrate a full spacecraft subsystem integration at a small scale.  
The system includes Command & Data Handling (C&DH), Electrical Power System (EPS), Communications (Radio), Payload, Structure, and a Ground Station link.  

Our payload is actively controlled using Arduino microcontrollers and stepper motors, simulating real-world actuation of instruments on a satellite.

---

## System Architecture

```text
                +------------------+
                |   Ground Station |
                +------------------+
                         ^
                         | Radio Link
                         v
   +------+        +-----------+        +----------+
   | C&DH | <----> |   Radio   | <----> | Structure|
   +------+        +-----------+        +----------+
      |                   ^
      v                   |
   +--------+             |
   | Payload|             |
   +--------+             |
      ^                   |
      |                   |
   +--------+        +-----------+
   | Battery| <----> |    EPS    |
   +--------+        +-----------+
         ^                  |
         +------------------+
```

## Subsystems
* **C&DH (Command & Data Handling)** – Coordinates commands, telemetry, and communication with the ground station.
* **EPS (Electrical Power System)** – Regulates and distributes power from the battery to all subsystems.
* **Battery** – Provides stored energy for operations.
* **Radio** – Handles communication with the ground station.
* **Payload** – Stepper-motor-driven subsystem managed by Arduino boards.
* **Structure** – Mechanical frame that integrates all subsystems.

## Features
* Arduino-controlled stepper motor actuation for payload experiments
* End-to-end simulation of satellite subsystems
* Ground station communication via radio link
* Modular design for testing C&DH, EPS, and Payload interactions

## Hardware
* Arduino Uno / Mega (for payload control)
* Stepper Motors (NEMA17 or similar) + motor drivers
* Raspberry Pi (for data handling & integration)
* LoRa / RF module (for ground station communication)
* Li-Po battery + EPS board

## Software
* Arduino IDE / PlatformIO for stepper motor and payload firmware
* Python (Raspberry Pi) for C&DH control, data logging, and communication
* EPS scripts for simulating power distribution
* Ground station client for receiving telemetry and sending commands

## Getting Started

```bash
# Clone the repository
git clone https://github.com/sidprs/wrover.git
cd wrover

# Build and upload Arduino payload firmware
cd arduino
# Open main.ino or main.py in Arduino IDE and upload

# Run C&DH scripts on Raspberry Pi
cd ../pi
python3 camera.py   # Example payload integration script

# Test stepper motors
cd ../arduino
python3 motor_test.py
```

## Future Work
* Add telemetry downlink for payload status
* Integrate camera module with C&DH
* Expand EPS to include solar charging simulation

## Team
Developed as part of the ASU Wrover CubeSat initiative, combining hardware, embedded systems, and space systems engineering principles.
# tinyds
