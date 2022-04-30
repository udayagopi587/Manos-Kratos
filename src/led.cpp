#include "led.h"
#include <FastLED.h>

// int min_value = 20;
// int max_value = 50;
// int actual_value = 25;
int led_range = 9;
int m_value = 0;
int ma_value = 100;
CRGB leds[NUM_LEDS];
CRGB leds_1[NUM_LEDS];
String color;

void LED()
{
	FastLED.addLeds<WS2812, LED_PIN1, GRB>(leds, NUM_LEDS); // Default declaration for LED setup on arduino
	FastLED.addLeds<WS2812, LED_PIN2, GRB>(leds_1, NUM_LEDS);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, 600); // Limiting the voltage and current for safe guarding the controller.
	FastLED.clear();								// clear the leds, optionally wiping the local array of data as well
	FastLED.show();
}

void strip_1(int actual_value, int min_value, int max_value)
{
	// actual_value = 0; min_value = 20; max_value = 100;
	Serial.print("Max_Value:-");
	Serial.print(max_value);
	Serial.print("	Min_Value:-");
	Serial.print(min_value);
	Serial.print("	actual_value:-");
	Serial.println(actual_value);

	int avg = (max_value + min_value) / 2;
	if (actual_value < 15)
	{
		for (int i = 0; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(0, 0, 0); // Black
			FastLED.setBrightness(6);
			delay(50);
		}
	}
	else if (actual_value < min_value)
	{
		for (int i = 0; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(255, 165, 0); // Orange
			FastLED.setBrightness(6 * i);
			delay(50);
		}
	}

	else if ((actual_value < avg - 10) && (actual_value >= min_value))
	{
		for (int i = 0; i < (NUM_LEDS - 5); i++)
		{
			leds[i] = CRGB(255, 255, 0); // Yellow
			FastLED.setBrightness(6 * i);
			delay(50);
		}
		for (int i = 4; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(0, 0, 0); // Black
			FastLED.setBrightness(6 * i);
			delay(50);
		}
	}

	else if (avg - 10 <= actual_value && actual_value <= avg + 10)
	{
		for (int i = 0; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(0, 0, 0); // Black
			FastLED.setBrightness(6 * i);
			delay(50);
		}
		leds[4] = CRGB(0, 255, 0); // Green
		FastLED.setBrightness(6 * 4);
		delay(50);
	}
	// Blue Section
	else if ((actual_value > avg + 10) && (actual_value <= max_value))
	{

		for (int i = 0; i < (NUM_LEDS - 4); i++)
		{
			leds[i] = CRGB(0, 0, 0); // Black
			FastLED.setBrightness(6 * i);
			delay(50);
		}
		for (int i = 5; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(0, 255, 255); // Sky Blue
			FastLED.setBrightness(6 * i);
			delay(50);
		}
	}

	else if (actual_value > max_value)
	{
		for (int i = 0; i < (NUM_LEDS); i++)
		{
			leds[i] = CRGB(255, 0, 0); // Red
			FastLED.setBrightness(6 * i);
			delay(50);
		}
	}
	FastLED.show();
}

// void strip_2(int actual_value)
// {
// 	//actual_value = 0;
// 	int num_leds = (actual_value * led_range) / ma_value;
// 	if (actual_value == 0 && actual_value < 5)
// 	{
// 		for (int i = 0; i < (num_leds); i++)
// 		{
// 			leds_1[i] = CRGB(0, 0, 0);
// 			FastLED.setBrightness(6);
// 			delay(50);
// 			FastLED.show();
// 		}
// 	}
// 	else
// 	{
// 		for (int i = 0; i < (num_leds); i++)
// 		{
// 			leds_1[i] = CRGB(255, 255, 0);
// 			FastLED.setBrightness(6 * 2);
// 			FastLED.show();
// 			// Serial.println(value);
// 			// Serial.println(num_led);
// 			delay(50);
// 		}
// 		FastLED.show();
// 	}
// }
