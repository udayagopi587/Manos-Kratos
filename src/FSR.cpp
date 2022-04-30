#include <Arduino.h>
// #include "analogWrite.h"

const int analogInPin1 = 25; // Analog input pin
const int analogInPin2 = 26;
const int analogInPin3 = 27;
const int analogInPin4 = 15;
const int analogInPin5 = 14;

int sensorValue1 = 0; // value read from the pot
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int sensorValue5 = 0;

int outputValue1 = 0; // value output to the PWM (analog out)
int outputValue2 = 0;
int outputValue3 = 0;
int outputValue4 = 0;
int outputValue5 = 0;

int actualValue;

void setupFSR()
{
    // initialize serial communications at 9600 bps:
    pinMode(analogInPin1,INPUT);
    pinMode(analogInPin2,INPUT);
    pinMode(analogInPin3,INPUT);
    pinMode(analogInPin4,INPUT);
    pinMode(analogInPin5,INPUT);
}

int loopFSR()
{
    // read the analog in value:
    sensorValue1 = analogRead(analogInPin1);
    sensorValue2 = analogRead(analogInPin2);
    sensorValue3 = analogRead(analogInPin3);
    sensorValue4 = analogRead(analogInPin4);
    sensorValue5 = analogRead(analogInPin5);
    // map it to the range of the analog out:
    outputValue1 = map(sensorValue1, 0, 4095, 0, 255);
    outputValue2 = map(sensorValue2, 0, 4095, 0, 255);
    outputValue3 = map(sensorValue3, 0, 4095, 0, 255);
    outputValue4 = map(sensorValue4, 0, 4095, 0, 255);
    outputValue5 = map(sensorValue5, 0, 4095, 0, 255);

    actualValue = outputValue1 + outputValue2 + outputValue3 + outputValue4 + outputValue5;
    // print the results to the Serial Monitor:
    // Serial.print("sensor = ");
    // Serial.print(sensorValue1);
    Serial.print("\t output1 = ");
    Serial.print(outputValue1);
    Serial.print("\t output2 = ");
    Serial.print(outputValue2);
    Serial.print("\t output3 = ");
    Serial.print(outputValue3);
    Serial.print("\t output4 = ");
    Serial.print(outputValue4);
    Serial.print("\t output5 = ");
    Serial.println(outputValue5);

    delay(20);
    return(actualValue);
}