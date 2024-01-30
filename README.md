# Robotics

## Overview

This repository is dedicated to my studies and projects related to Robotics. Robotics with Arduino involves using Arduino microcontroller boards to build and control robots. It relies on simple software running on these boards. This README provides an overview of the contents of the repository and guidance on how to navigate through the different components.

## Table of Contents

1. [Introduction to Robotics](#Introduction-to-Robotics)
2. [Projects](#projects)


## Introduction to Robotics

Robotics with Arduino involves using Arduino microcontroller boards to build and control robots. It relies on simple software running on these boards, which can be connected to various electronic components such as motors, sensors, and lights. Arduino enables programming robots for various purposes like motion control, environmental sensing, and interacting with external elements. Its flexible programming and extensive libraries allow for easy development of a wide range of robotic applications at a low cost.

## Projects

### [Project 1: [Mobile Robot RC Car]](Mobile_Car_Code.ino)

This Arduino project controls a robotic car's movement using Bluetooth communication. The car's movements include forward, backward, left turn, right turn, and stop, which are triggered by specific characters ('F', 'B', 'R', 'L', 'S') received from a connected Bluetooth device. The project consists of defining the pins for motor control and establishing serial communication. Each movement corresponds to a specific function, which sets the motor speed and direction accordingly.

### [Project 2: [obstacle avoiding robot]](Obstacle_Avoiding_Code.ino)
 
This project is an obstacle-avoiding robot built using an Arduino board and an ultrasonic sensor. The robot is designed to navigate its environment autonomously while avoiding obstacles in its path.

### [Project 2: [Line follower Car]](Line_Follower_Code.ino)
 
This project is a basic line follower robot that uses two infrared (IR) sensors to detect and follow a black line on a white surface. The Arduino board is connected to two IR sensors and two DC motors, each controlling one side of the robot's movement.

### [Project 3: [Fire and Smoke Detection]](Fire_Smoke_With_buzzer_MQ2_IR.ino)

This project is a Fire and Smoke Detection System that utilizes gas and IR sensors to detect the presence of fire and smoke. It includes an Arduino board connected to an LCD display and a buzzer.


