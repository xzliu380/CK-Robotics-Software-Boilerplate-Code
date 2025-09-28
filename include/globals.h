#pragma once
#include "main.h"


extern pros::Motor leftMotor1;
extern pros::Controller controller;
extern pros::MotorGroup leftDrive;
extern pros::MotorGroup rightDrive;

extern pros::Motor intakeMotor1;
extern pros::Motor intakeMotor2;

extern pros::Rotation odom;
extern pros::Imu inertial;

extern pros::ADIDigitalOut intakePneumatic;
extern pros::ADIDigitalOut backPneumatic;
extern pros::ADIDigitalOut scorePneumatic;
extern pros::ADIDigitalOut preventScorePneumatic;

extern lemlib::Chassis chassis;

extern pros::Optical optical;

extern bool teamRed;
extern bool scoringLow;