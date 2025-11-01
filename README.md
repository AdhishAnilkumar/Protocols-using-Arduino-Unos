# Communiction Protocols-using-Arduino-Unos

**Aim**: To implement protocols such as UART,I2C and SPI using 2 Arduino Uno boards.<br>

**Components Used**: LCD module, Ultrasonic Sensor (HC-SR04) ,Servo Motor,2 Arduino Uno boards,Jumper wires,Potentiometer(to adjust LCD contrast).<br>
**Software Used** :Arduino IDE<br>

**Implementation**:<br>

**One Arduino Uno board is treated as Master and other as Slave.**

***UART***:<br>
Master send data inputted via Serial Monitor in IDE and Slave recieves the data and displays in the LCD module.
<br>
***I2C***:<br>
Master inputs data via Serial Monitor in IDE and Slave controls the movement of Servo according to command of Master and then sends back the confirmation to Master which in turn dispolays the confirmation in LCD module.
<br>
***SPI***:<br>
Master measures distance from a nearby object uisng Ultrasonic Sensor and sneds value in cm to Slave which displays the result using LCD module.
<br>

This project focuses on implementation of serial communications protocols using 2 microcontrollers as well as integration of components such as sensors and LCD module.

