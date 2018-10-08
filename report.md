# **PID Controller for Self Driving Car** 

---

**PID Controller Project**

The autonomous part of the self-driving cars is to steer itself and control speed based on the inputs provided.

The goal of this project is to autonomously steer the car to keep the car on th track based on the Cross-Track Error, which is provided as input from the simulator.


[//]: # (Image References)

[video1]: ./Videos/P.gif "Proportional"
[video2]: ./Videos/Working.gif "WorkingSimulation"

---
## PID Controller

**PID** stands for **Proportional-Integral-Derivative**. The **PID Controller** is a common control loop feedback mechanism which continuously calculates a control parameter to correct the error it receives as input. In our case the error is **Cross Track Error (CTE)**, which is the  distance of the car from the center of the lane line. The control parameter is calculated based on the Proportional (P), Integral (I) and Derivative (D) terms of the error.

## Choosing PID Parameters
The behavior of the PID controller depends on the coefficients of the Proportional (P), Integral (I) and Derivative (D) terms of the error. For this project, the coefficients of these terms are manually tuned one at a time by closely inspecting the performance on the simulator. Below are the observational insights on how this had been done.


### Proportional
The coefficient of Proportional term regulates the change in output for a given change in error. For this project, this coefficient had the most direct observable effect on the car driving behavior. As can be seen in the video below, it steers the car proportional to the CTE. If the car is far from the center line, it steers hard, if close it steers less. Less oscilation and smooth transition to the center lane was the visual guiding aid to tune this coefficient.

![alt text][video1]

### Integral 
The coefficient of the Integral term counteracts any systematic bias that prevents car from closing the error. The bias can be steering drift as taught in the lesson. The Integral coefficient contributes in proportional to the sum of the CTE for the elapsed time. For this project, there were ~6000 observation for the complete track, so this coefficient has to be in order of 0.0001.

### Derivative 
The coefficient of the Derivative term is the weightage of rate of change of the error. This provides stability while the car steers close to the center line and avoids overshooting the center line. For this project, the visual guiding factor to tune this coefficient was to ensure smooth transition to the center line of the car.

![alt text][video2]