# LEDStatusBar

The LED status bar is a simple electronics project for/with Arduino type of micro controllers.

It consists of a piece of hardware that uses 8 LEDs to show a status or progress. 

Imagine you want to show the remaining capacity of a battery or a battery load status.
You can use the LED status bar to visualize it.

- show the red light when the load level is too low. 
- use the 6 blue lights to visualize load percentage
- use the green light to visualize that the battery is just *full enough*.

## How to connect the bar
To connect the LED bar to you Arduino/MCU, you may want to plug it into your bread board. 

So please rotate the bar in a way that the PINs point downwards. :-)

Looking at the LED bar this way, 

- PIN1: VCC (5V), 
- PIN2: GND (ground),
- PIN3: digital input 1
- PIN4: digital input 2
- PIN5: digital input 3

If you want to understand exactly what the pins are used for, or if you want to directly control the underlying shift register, you need to know how the LED bar's pins are connected:

- PIN3 is SHCP, 
- PIN4 STCP and 
- PIN5 is DS (SER).

## How to use the bar
without caring about shift registers?

If you don't want to care about shift registers and how to turn on which of the LEDs, there is some code that helps you out.

### ProgressBar library
You can use the ProgressBar library for a very simple and intuitive way to show status/progress on the LED status bar.

```
/*
 *    This sketch uses the ProgressBar library/class    
 *    to visualize percentages from 0 to 100 
 *    on the 6-blue LED progress bar.
 *    
 *    As long as percentage is below limit (16%),   
 *    the red light will be on.   
 *    After reaching the "full" state (96%),   
 *    the green light will be turned on.
 */

#include <ProgressBar.h>

// digital pins of Arduino   
// connected to pins 3 to 5 of LED bar
int pin3 = 5;
int pin4 = 4;
int pin5 = 2;

// instantiate object of type ProgressBar
ProgressBar progress(pin3, pin4, pin5);

// start with 0 percent
int percentage = 0;

void setup() {
  // setup serial connection
  Serial.begin(9600);
}

// The loop will just count up by 1% each 250ms.
// The ProgressBar object is updated with   
// current percentage and the LED bar will show   
// the lights accordingly.
void loop () {
  // stop doing this when 100% was reached
  if (percentage < 100) {
    percentage += 1;
    
    // write percentage to serial
    Serial.print("We are now at "); 
    Serial.print(percentage);
    Serial.println("%.");
  
    // set percentage on progress LED bar
    progress.setPercentage(percentage);
  }

  delay(250);  
}
```

For a more complex example, please have a look into the examples folder.