/*
 * 	This simple example uses the 3rd party library "Shifty"
 * 	to simply switch on and off all 8 LEDs one by one.
 *
 *  There is no special "LEDStatusBar" code involved, apart
 *  from the PIN name/configuration.
 *  The shift register that controls the LEDs is used directly
 *  via "Shifty".
 *
 *	When the LED Bar sits within the BreadBoard (so PINs point downwards),
 *  the PIN order is:
 *  * pin1: VCC, 5V
 *  * pin2: GND, Ground
 *  * pin3: connect to a digital output
 *  * pin4: connect to a digital output
 *  * pin5: connect to a digital output
 *  
 */

#include <Shifty.h>

// Declare the shift register
Shifty shift; 

// the LED bar has 8 LEDs
const int NR_OF_LEDS = 8;

// specify where you connected pins 3 to 5 to.
const int pin3 = 5;
const int pin4 = 4;
const int pin5 = 2;

// setup "Shifty"
void setup() {
  // Tell shifty that the LED bar has 8 LEDs
  shift.setBitCount(NR_OF_LEDS);

  // Tell shifty how to access the shift register
  // that is controlling the LEDs of the LED bar.
  shift.setPins(pin5, pin3, pin4); 
}

// main loop
void loop() {

  // this turns on each LED for 500ms
  // one after the other
  for (int i = 0; i < NR_OF_LEDS; i++) {
    shift.writeBit(i, HIGH);
    delay(500);
    shift.writeBit(i, LOW);
  }
}
