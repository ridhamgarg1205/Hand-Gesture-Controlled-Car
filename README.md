# Hand Gesture Controlled Car

This project involves the design and implementation of a 4-wheeled differential drive robot that is controlled wirelessly via hand gestures. By using an Inertial Measurement Unit (IMU) to detect hand orientation and Radio Frequency (RF) modules for communication, the system allows for intuitive teleoperation without physical controllers.

---

## Project Overview

The system operates by mapping the tilt of a user's hand to specific movement commands for the robot. The project was developed in phases, starting with research in early 2025 and moving into full hardware integration in July 2025.

### Key Concepts
* **Gesture Mapping**: Translating the physical tilt of the hand (detected by an accelerometer) into digital signals.
* **Wireless Transception**: Sending data packets over the 2.4GHz spectrum using the nRF24L01 protocol.
* **Differential Drive**: Controlling a robot's direction by varying the speeds of the left and right wheels.

---
### System Hardware Specifications

| Component | Quantity | Technical Notes and Function |
| :--- | :--- | :--- |
| **Arduino UNO** | 1 | Primary microcontroller for the receiver/chassis side. |
| **Arduino Nano** | 1 | Compact microcontroller for the transmitter/gesture glove. |
| **nRF24L01 Module** | 2 | Handles wireless RF communication (2.4GHz) between units. |
| **MPU6050 Sensor** | 1 | 6-axis motion tracking (Accel/Gyro) for gesture detection. |
| **L298N Motor Driver** | 1 | H-Bridge driver used to control the 4 BO motors. |
| **BO Motors** | 4 | DC motors used in a differential drive configuration. |
| **2S 2800mAh LiPo** | 1 | Dedicated high-current power source for the motor driver. |
| **18650 Li-ion Cells** | 2 | Isolated power for the transmitter and receiver logic circuits. |
| **Capacitors (10µF–50µF)** | 2 | Essential for nRF24L01 power filtering and signal stability. |
| **XT60 Connectors** | 1 Pair | Used for modular and secure battery attachment. |
| **SPST Switch** | 1 | Main power isolation switch for the receiver circuit. |
| **Chassis Kit** | 1 | Includes acrylic base plates and mounting hardware. |
## Hardware Components and Functions

---
The project is split into a Transmitter (hand-mounted) and a Receiver (chassis-mounted).

### Control and Sensing
* **Arduino Nano**: Serves as the primary microcontroller for the transmitter due to its small form factor.
* **Arduino UNO**: Acts as the central processing unit for the receiver on the robot chassis.
* **MPU6050 (IMU)**: A 6-axis motion tracking device that combines a 3-axis gyroscope and a 3-axis accelerometer to detect hand gestures.

### Communication and Drive
* **nRF24L01 Transceiver**: A pair of modules used to establish a wireless link between the Nano and the UNO.
* **L298N Motor Driver**: An H-Bridge module that allows the Arduino to control the speed and direction of the DC motors.
* **BO Motors and Wheels**: Four DC motors that provide the mechanical drive for the robot.

### Power and Stability
* **2S 2800mAh LiPo Battery**: High-capacity power source dedicated to driving the motors.
* **18650 Li-ion Cells**: Used to provide separate, stable power to the microcontrollers and RF modules.
* **Capacitors (10µF–50µF)**: Component added across the nRF24L01 power pins to filter electrical noise and prevent communication drops.
* **XT60 Connectors and SPST Switch**: Used for secure battery connections and a main power cutoff for safety.

---

## Technical Challenges and Solutions

### Power Interference
During the early phase, communication was unstable due to electrical noise from the motors.
* **Solution**: The addition of decoupling capacitors and the use of separate power supplies for the logic (Arduino) and the actuators (Motors) stabilized the system.

### Structural Integrity
* **Challenge**: Ensuring the 4WD chassis remained stable during movement.
* **Solution**: Reinforced the acrylic base plates using M3x30mm brass standoffs and binding wire for added mechanical strength.

---

## Software and Resources

### Required Libraries
* **RF24**: Used for managing the nRF24L01 radio communication.
* **MPU6050 / I2Cdev**: Used for interfacing with the motion sensor via the I2C protocol.
* **Wire and SPI**: Standard Arduino libraries for hardware communication.

### Educational Resources
* HowToMechatronics: nRF24L01 Wireless Communication Tutorial.
* Instructables: DIY Hand Gesture Controlled Car Guide.

---

## Future Goals
* Implement software-based filtering (such as a Complementary Filter) to smooth gesture inputs.
* Add fail-safe logic to stop the motors if the wireless connection is interrupted.
* Integrate real-time telemetry to monitor battery voltage wirelessly.

**Author**: Ridham Garg, IIT Ropar.
