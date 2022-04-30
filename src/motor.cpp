#include "motor.h"
#include <analogWrite.h>

int vib_pin = 21;
int global_pwm = 255;

/*int min_value= 20;
int max_value= 50;
int actual_value= 5;*/
int avg = 0;
/*int co_eff = 0;
int factor = 0;
int turn = 0;*/

void motorSetup()
{
    pinMode(vib_pin, OUTPUT);
}

void vibration(int min_value, int max_value, int actual_value)

{
    avg = (max_value + min_value) / 2;
    // co_eff = ((global_pwm*actual_value)/avg);
    if (actual_value < 15)
    {
        analogWrite(vib_pin,0);
    }
    else if (actual_value < avg)
    {

        analogWrite(vib_pin, 255);
        delay(100);
        analogWrite(vib_pin, 0);
        delay(100);
    }
    else if ((actual_value < avg - 10) && (actual_value >= min_value))
    {

        analogWrite(vib_pin, 255);
        delay(200);
        analogWrite(vib_pin, 0);
        delay(100);
    }
    else if (avg - 10 <= actual_value && actual_value <= avg + 10)
    {
        for (int i = 0; i < 3; i++)
        {
            analogWrite(vib_pin, 230);
            // Serial.println("co_eff_2");
            delay(100);
            analogWrite(vib_pin, 0);
            delay(100);
        }
    }
    else if ((actual_value > avg + 10) && (actual_value <= max_value))
    {
        analogWrite(vib_pin, 255);
        delay(300);
        analogWrite(vib_pin, 0);
        delay(100);
    }
    else
    {
        analogWrite(vib_pin, 255);
    }
}