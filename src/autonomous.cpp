#include "main.h"

auto &output = std::cout;

void Autonomous::init(){

    inertial.reset(true);
    inertial.tare();
    while (inertial.is_calibrating()){
        pros::delay(10);
    }
    chassis.calibrate();
    chassis.setPose({0,0,0});
    optical.set_led_pwm(100);
    pros::Task printPoseTask(Autonomous::constantlyPrintPose); // multithreading: constantly print position, separate from main code.
}

void Autonomous::tuneAngularPID(){
    chassis.setPose({0,0,0});
    chassis.turnToHeading(90, 2000, {}, false);
    pros::delay(1000);
    chassis.turnToHeading(180, 2000, {}, false);
    pros::delay(1000);
    chassis.turnToHeading(270, 2000, {}, false);
    pros::delay(1000);
    chassis.turnToHeading(360, 2000, {}, false);
}

void Autonomous::tuneLateralPID(){
    chassis.setPose({0,0,0});
    chassis.moveToPoint(0, 24, 20000, {}, false);
    chassis.moveToPoint(0, 0, 20000, {.forwards = false}, false);
}

void Autonomous::constantlyPrintPose(){
    while (true){
        pros::lcd::print(0, "X: %f", chassis.getPose().x); // x
        pros::lcd::print(1, "Y: %f", chassis.getPose().y); // y
        pros::lcd::print(2, "Theta: %f", chassis.getPose().theta); // heading
        pros::delay(20);
    }
}

void Autonomous::skillsAuton(){
}
