# Automatic Solar Panel Tracking System with Arduino

## Project Description
This project is an automatically tracking solar panel that utilizes stepper motors to follow the sun's movement, maximizing energy production. The system detects the direction of maximum sunlight intensity using Light Dependent Resistors (LDRs) and adjusts the panel accordingly. 

## Main Components
- **Arduino** (e.g., Uno or Nano) – Controls the tracking system.
- **LDRs** (Light Dependent Resistors) – Measure light intensity from different directions to determine the sun’s position.
- **Stepper Motors** (28BYJ-48 + ULN2003 driver or NEMA 17 + A4988) – Move the panel to align with the sun.
- **Solar Panel** – Generates electrical power.
- **TP4056** – Charge controller that charges a LiPo battery.
- **MT3608** – Boost converter that supplies power to Arduino and other components.

## How It Works
1. **LDR sensors** detect the direction with the highest sunlight intensity.
2. **Arduino** processes the data and commands the stepper motors to rotate the panel towards the sun.
3. The **solar panel** generates energy, which is sent to **TP4056** to charge the **LiPo battery**.
4. **MT3608** boosts the battery voltage to power the **Arduino** and other modules.
5. The process repeats continuously, keeping the panel optimally positioned throughout the day.

## Tools & Technologies Used
- **Hardware:**
  - Solar Panel
  - Arduino (Uno/Nano)
  - Stepper Motors
  - LDR Sensors
  - TP4056 Charge Controller
  - MT3608 Boost Converter
  - Li-Po Battery
  - 3D Printed Components
- **Software:**
  - Arduino IDE
  - C++ (for Arduino programming)

## Installation & Setup
### Prerequisites
- Install **Arduino IDE**
- Ensure you have the required **Arduino libraries** (Stepper Motor, Servo, etc.)

### Circuit Setup
1. Connect the **LDR sensors** to the analog pins of the Arduino.
2. Interface the **Stepper Motor driver** with the Arduino and power supply.
3. Connect the **Solar Panel** to the TP4056 charge controller.
4. Connect the **MT3608 boost converter** to provide stable power to the Arduino.
5. Ensure proper wiring and secure connections.

### Software Upload
1. Open **Arduino IDE**.
2. Write or upload the provided **Arduino code**.
3. Compile and upload the code to the Arduino board.
4. Power on the system and observe the solar panel tracking.

## Usage Instructions
- Place the system in an open area with direct sunlight.
- Ensure the battery is charged and connected.
- Observe the panel movement as it follows the sun.
- Monitor voltage and energy output using a multimeter or serial monitor.

## Troubleshooting
- **Panel not moving?** Check the LDR sensor connections and motor wiring.
- **No power output?** Ensure the solar panel is functional and properly connected.
- **Unstable tracking?** Adjust the LDR placement for better sun detection.

## Future Improvements
- Add a **real-time monitoring system** with an IoT interface.
- Improve **energy storage capacity** for extended power supply.

## Contributors
- **Adam Mikael Bin Aris Abdillah**
- **Damilare Oyefara**
- **Ahmed Elnegmy**
- **Ylham Avliyakulyyev**

## License
This project is open-source and available for educational and non-commercial use.
