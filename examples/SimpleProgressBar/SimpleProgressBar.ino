/*
 *    This sketch uses the ProgressBar library/class to visualize percentages 
 *    from 0 to 100 on the 6-blue LED progress bar.
 *    
 *    As long as percentage is below limit (16%), the red light will
 *    be on. After reaching the "full" state (96%), the green light
 *    will be on.
 */

#include <ProgressBar.h>

// digital pins of Arduino connected to pins 3to 5 of LED bar
int pin3 = 5;
int pin4 = 4;
int pin5 = 2;

// instantiate object of type ProgressBar
ProgressBar progress(pin3, pin4, pin5);

// start with 0 percent
int percentage = 0;

void setup() {
  // setup serial connection so you can monitor percentage numbers
  // and check behaviour of the LED bar
  Serial.begin(9600);
}

// The loop will just count up by 1% each 250ms.
// The ProgressBar object is updated with current percentage
// and the LED bar will show the lights accordingly.
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
