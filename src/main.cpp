#include <Arduino.h>
#include "NFC.h"
#include "led.h"
#include "sender.h"
#include "FSR.h"
#include "motor.h"

int incomingByte = 0; // for incoming serial data
String minMax = "none";
bool first = false;
int actual_val, min_val, max_val;

void setup()
{
  Serial.begin(115200);
  setupNFC();
  LED();
  // setupSender();
  // sending();
  setupFSR();
  motorSetup();
  Serial.print("Waiting for NFC tag");
  minMax = readNFC();
  String min = minMax.substring(0, 4);
    String max = minMax.substring(5, 9);
    // Serial.println(min);
    // Serial.println(max);
    min_val = min.toInt();
    max_val = max.toInt();
}

void loop()
{
  
  if (Serial.available() > 0)
  {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial.print("I received: ");
    Serial.println(incomingByte, DEC);
    if (incomingByte == 49)
    {
      writeNFC();
    }
    else
    {
      minMax = readNFC();
      // Serial.println(minMax);
      String min = minMax.substring(0, 4);
      String max = minMax.substring(5, 9);
      Serial.println(min);
      Serial.println(max);
      min_val = min.toInt();
      max_val = max.toInt();
      // Serial.println(ptr[0]);
    }

    // say what you got:
  }
  actual_val = loopFSR();
  // Serial.println(min_val);
  // Serial.println(max_val);
  // Serial.println(actual_val);
  delay(100);
  strip_1(actual_val, min_val, max_val);
  vibration(min_val,max_val,actual_val);
  // strip_2(actual_val);
}