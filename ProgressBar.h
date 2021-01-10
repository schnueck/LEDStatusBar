/*
  ProgressBar.h - Library for 8bit LED progress bar with 6 blue status LEDs, one red an done green.
  Created by Thomas Schnuecker, Jan 2020.
  Released into the public domain.
*/


#ifndef ProgressBar_h
#define ProgressBar_h

#include "Arduino.h"

#define NR_OF_STATUS_LEDS 6
#define RED_LED 1
#define GREEN_LED 8

#define LED_1_BOUND 16
#define LED_2_BOUND 32
#define LED_3_BOUND 50
#define LED_4_BOUND 65
#define LED_5_BOUND 80
#define LED_6_BOUND 95

#define RED_LIMIT	16
#define GREEN_LIMIT	96

class ProgressBar
{
  public:
    ProgressBar(int pin3, int pin4, int pin5);
	
	// Limit of percentage for red light to be turned on
	void setRedLimit(int percentage); 
	
	// Limit of percentage for green light to show 
	void setGreenLimit(int percentage);
	
	// Percentage to be converted into n blue lights
	void setPercentage(int percentage);
	
	// Configure bounds of percentage to switch LEDs on or off_type
	void setLEDValueBounds(int bounds[NR_OF_STATUS_LEDS]);
	
	// Switch order in which lights will show up
	void reverseOrder();
	void normalOrder();
	
  private:
    int _dataPin;
    int _storePin;
    int _shiftPin;
	
	int _ledValueBounds[NR_OF_STATUS_LEDS] = 
		{LED_1_BOUND, LED_2_BOUND, LED_3_BOUND, LED_4_BOUND, LED_5_BOUND, LED_6_BOUND};
	
	int _percentage = 0;
	int _redLimit = RED_LIMIT;
	int _greenLimit = GREEN_LIMIT;
	
	bool _reverseOrder = false;
	
	void _write(byte ledValue);
};

#endif
