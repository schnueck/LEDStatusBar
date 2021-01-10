/*
  ProgressBar.cpp - Library for handling 8bit (6 blue, 1 red, 1 green) status bar LEDs.
  Created by Thomas Schnuecker, Jan, 2020.
  Released into the public domain.
*/

#include "Arduino.h"
#include "ProgressBar.h"

ProgressBar::ProgressBar(int pin3, int pin4, int pin5)
{
  _dataPin = pin5;
  _storePin = pin4;
  _shiftPin = pin3;
  pinMode(_dataPin, OUTPUT);
  pinMode(_storePin, OUTPUT);
  pinMode(_shiftPin, OUTPUT);
}

// Configure progress bar
void ProgressBar::setLEDValueBounds(int bounds[NR_OF_STATUS_LEDS]) {
	for (int i=0; i < NR_OF_STATUS_LEDS; i++) {
		_ledValueBounds[i] = bounds[i];
	}
}

void ProgressBar::setRedLimit(int percentage) {
	_redLimit = percentage;
}

void ProgressBar::setGreenLimit(int percentage) {
	_greenLimit = percentage;
}

// use progress bar
void ProgressBar::setPercentage(int percentage) {
	_percentage = percentage;
	byte ledValue = 0;
	
	for (int i = 0; i < NR_OF_STATUS_LEDS; i++) {
		if (_percentage >= _ledValueBounds[i]) {
			ledValue +=  1 << i+1; // work on blue LEDs (2 to 7)
		}
	}
	
	if (_percentage < _redLimit) {
		ledValue += 1 << RED_LED - 1;
	}		
	
	if (_percentage > _greenLimit) {
		ledValue += 1 << GREEN_LED - 1;
	}
	
	ProgressBar::_write(ledValue);
}

void ProgressBar::reverseOrder() {
	_reverseOrder = true;
}

void ProgressBar::normalOrder() {
	_reverseOrder = false;
}

void ProgressBar::_write(byte ledValue) {
	digitalWrite(_storePin, LOW);
	if (_reverseOrder) {
		shiftOut(_dataPin, _shiftPin, LSBFIRST, ledValue);
	} else {
		shiftOut(_dataPin, _shiftPin, MSBFIRST, ledValue);
	}
	digitalWrite(_storePin, HIGH);		
}