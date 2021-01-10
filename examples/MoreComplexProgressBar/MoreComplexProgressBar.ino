/*
 *    This sketch shows all methods of ProgressBar library/class in action.
 */

#include <ProgressBar.h>

// digital pins of Arduino connected to pins 3to 5 of LED bar
int pin3 = 5;
int pin4 = 4;
int pin5 = 2;

// instantiate object of type ProgressBar
ProgressBar progress(pin3, pin4, pin5);

void setup() {
  // setup serial connection so you can monitor percentage numbers
  // and check behaviour of the LED bar
  Serial.begin(9600);

  // count upwards, show percentage, all defaults
  countUpwards();
  delay(1000);

  // still count upwards, but reverse order of LEDs.
  // green LED will "become red led" and vice versa
  // could be used to say "if it's full, you have to do something"
  // like "you have to empty your offee grounds container"
  progress.reverseOrder();  
  countUpwards();
  delay(1000);

  // back to normal
  progress.normalOrder();  

  // redefine limits for red and green
  // Let's say: half empty water tank in coffee machine 
  // is already RED
  progress.setRedLimit(50);
  countDownwards();
  delay(1000);

  // maybe, it's GREEN as long as it's not RED?
  progress.setGreenLimit(50);
  countDownwards();
  delay(1000);

  // redefine the percentage "bounds" for blue lights
  // let's imagine: everything below 50% is not enough,
  // so we only visualize the top 50% 
  int newBounds[6] = {50, 60, 70, 80, 90, 100};
  progress.setLEDValueBounds(newBounds);
  countUpwards();
  delay(1000);
}

// empty loop this time, want to show samples only once
void loop () {
}

void countUpwards() {
  // count percentage up from 0 to 100
  for (int i = 0; i <= 100; i++) {
    // write percentage to serial
    Serial.print("We are now at "); 
    Serial.print(i);
    Serial.println("%.");
  
    // set percentage on progress LED bar
    progress.setPercentage(i);

    // wait a bit
    delay(100);
  }  
}

void countDownwards() {
  // count percentage down from 100 to 50
  for (int i = 100; i > 0; i--) {
    // write percentage to serial
    Serial.print("We are now at "); 
    Serial.print(i);
    Serial.println("%.");
  
    // set percentage on progress LED bar
    progress.setPercentage(i);

    // wait a bit
    delay(100);
  }  
}
