//#include "mbed.h"
#include "Motor.h"
#include "QEI.h"
#include "PID.h"
#include "Pins_and_Consts.h"



typedef enum {} programState;

Serial pc(USBTX, USBRX);

QEI rightWheel(ENCODER_A1, ENCODER_B1, NC, CPR, QEI::X4_ENCODING);
QEI leftWheel(ENCODER_A2, ENCODER_B2, NC, CPR, QEI::X4_ENCODING);
Motor rightMotor(MODE_PIN1, PWM_PIN1, 25000.0f); 
Motor leftMotor(MODE_PIN2, PWM_PIN2, 25000.0f); 
PID controller(0.0f,0.0f,0.0f,0.1f);

int main()
{
    DigitalOut enable(ENABLE_PIN);
    enable = true;
    controller.setInputLimits(0.0F, 3000.0f);
    controller.setOutputLimits(0.0f, 0.5f);
    controller.setSetPoint(600.0f);


    while (true)
    {
        controller.setProcessValue(rightWheel.getVelocity()); 
        rightMotor.setDutyCycle(controller.compute());
        wait(0.1);       
    }
}
