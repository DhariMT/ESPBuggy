#include "mbed.h"
#include "Motor.h"

void Motor::reset() {
    
    direction.write(biDirection);
    controlPWM.period(1.0f/PWMfreq);
    controlPWM.write(dutyCycle);
}

void Motor::setDutyCycle(float DUTYCYCLE) {
    controlPWM.write(DUTYCYCLE);
    dutyCycle = DUTYCYCLE;
}

void Motor::setDirection(bool isBiDirection) {
    direction.write(biDirection);
    biDirection = isBiDirection;
}

void Motor::setFrequency(float FREQ) {
    controlPWM.period(1.0f/FREQ);
    PWMfreq = FREQ;
}

float Motor::getDutyCycle() {
    return dutyCycle;
}

float Motor::getFrequency() {
    return PWMfreq;
}
bool Motor::getDirection() {
    return biDirection;
}