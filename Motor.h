#ifndef MOTOR_H
#define MOTOR_H

#include "mbed.h"

class Motor {

private:
float dutyCycle;
float PWMfreq;
int biDirection;
PwmOut controlPWM;
DigitalOut direction;


public:
Motor(PinName DIRECTION, PinName PWM, float DUTY_CYCLE, float FREQ = 25000.0, int isBiDirection = 1) : direction(DIRECTION), controlPWM(PWM), 
dutyCycle(DUTY_CYCLE), PWMfreq(FREQ), biDirection(isBiDirection) {
    reset();     
}

void reset();

void setDutyCycle(float DUTYCYCLE);
void setDirection(bool isBiDirection);
void setFrequency(float FREQ);

float getDutyCycle();
float getFrequency();
bool getDirection();
};

#endif