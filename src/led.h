#include <Arduino.h>


#ifndef LED_H
#define LED_H



#define LED_PIN1 33
#define LED_PIN2 32
#define NUM_LEDS 9


void LED();

void strip_1(int actual_value, int min_value, int max_value);

// void strip_2(int actual_value);
#endif 