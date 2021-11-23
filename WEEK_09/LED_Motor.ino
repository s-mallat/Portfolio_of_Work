#include <Adafruit_NeoPixel.h>

    int pin_MOTOR = A0; //Note: Connecting motor to analog pin to vary vibration output
    bool T_F = 0;

    int redColor = 0;
    int greenColor = 0;
    int blueColor = 0;
    int delayval = 200;

#define PIN 3   // input pin Neopixel is attached to
// the PWM pin the LED is attached to

#define NUMPIXELS      5 // number of neopixels in Ring

#define BRIGHTNESS 50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
      pixels.begin(); // Initializes the NeoPixel library.
      pixels.show();
      pixels.setBrightness(BRIGHTNESS);
      
      pinMode(pin_MOTOR, OUTPUT);
      analogWrite(pin_MOTOR, 0);
}

void loop() {
       pixels.clear();
  // put your main code here, to run repeatedly:
if (T_F == 0) {
      
      analogWrite(pin_MOTOR, 255);

      pixels.setPixelColor(0, pixels.Color(150,0,0));
      pixels.setPixelColor(1, pixels.Color(150,0,0));
      pixels.setPixelColor(2, pixels.Color(150,0,0));
      pixels.setPixelColor(3, pixels.Color(150,0,0)); 
      pixels.setPixelColor(4, pixels.Color(150,0,0));
      pixels.show();
      pixels.clear();
      
      delay(500);
      
      analogWrite(pin_MOTOR, 0);

      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.setPixelColor(1, pixels.Color(0,0,0));
      pixels.setPixelColor(2, pixels.Color(0,0,0));
      pixels.setPixelColor(3, pixels.Color(0,0,0));
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.show();
      pixels.clear();
      
      delay(500);
      
      analogWrite(pin_MOTOR, 255);

      pixels.setPixelColor(0, pixels.Color(150,0,0));
      pixels.setPixelColor(1, pixels.Color(150,0,0));
      pixels.setPixelColor(2, pixels.Color(150,0,0));
      pixels.setPixelColor(3, pixels.Color(150,0,0));
      pixels.setPixelColor(4, pixels.Color(150,0,0)); 
      pixels.show();
      pixels.clear();
      
      delay(500);
      
      analogWrite(pin_MOTOR, 0);
      
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.setPixelColor(1, pixels.Color(0,0,0));
      pixels.setPixelColor(2, pixels.Color(0,0,0));
      pixels.setPixelColor(3, pixels.Color(0,0,0));
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.show();
      pixels.clear();
      
      delay(500);
      
      analogWrite(pin_MOTOR, 255);
      
      pixels.setPixelColor(0, pixels.Color(150,0,0));
      pixels.setPixelColor(1, pixels.Color(150,0,0));
      pixels.setPixelColor(2, pixels.Color(150,0,0));
      pixels.setPixelColor(3, pixels.Color(150,0,0));
      pixels.setPixelColor(4, pixels.Color(150,0,0)); 
      pixels.show();
      pixels.clear();
      
      delay(500);
      
      analogWrite(pin_MOTOR, 0);
      
      pixels.setPixelColor(0, pixels.Color(0,0,0));
      pixels.setPixelColor(1, pixels.Color(0,0,0));
      pixels.setPixelColor(2, pixels.Color(0,0,0));
      pixels.setPixelColor(3, pixels.Color(0,0,0));
      pixels.setPixelColor(4, pixels.Color(0,0,0)); 
      pixels.show();
      pixels.clear();

      T_F = 1; //To make sure this runs only once!
      
      }

     delay(2000);
     //setColor(); 
     
//     for(int i = 0; i < NUMPIXELS; i++) {
//      
//     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//     pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // Moderately bright green color.
//      
//     pixels.show(); // This sends the updated pixel color to the hardware.
//      
//     delay(delayval); // Delay for a period of time (in milliseconds).
//                    
//                if (i == NUMPIXELS){
//                    i = 0; // start all over again!
//                    setColor();
//                }
//          
//
//     } delay(2000);
  colorWipe(pixels.Color(255,   0,   0)     , 50); // Red
  colorWipe(pixels.Color(  0, 255,   0)     , 50); // Green
  colorWipe(pixels.Color(  0,   0, 255)     , 50); // Blue
  colorWipe(pixels.Color(  0,   0,   0, 255), 50); // True white (not RGB white)

  delay(2000);

  for(int j = 255; j >= 0; j--) { // Ramp down from 255 to 0
    pixels.fill(pixels.Color(0, pixels.gamma8(j), 0));
    pixels.show();
    delay(10);
  }
  delay(100);
  for(int j = 255; j >= 0; j--) { // Ramp down from 255 to 0
    pixels.fill(pixels.Color(pixels.gamma8(j), pixels.gamma8(j), pixels.gamma8(j)));
    pixels.show();
    delay(10);
  }
  delay(100);
  for(int j = 255; j >= 0; j--) { // Ramp down from 255 to 0
    pixels.fill(pixels.Color(pixels.gamma8(j), 0, pixels.gamma8(j)));
    pixels.show();
    delay(10);
  }

}



void setColor() {
  
    redColor = random(0, 150);
    greenColor = random(0,150);
    blueColor = random(0, 150);
}


void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel in strip...
    pixels.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    pixels.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void pulseWhite(uint8_t wait) {
  for(int j=0; j<256; j++) { // Ramp up from 0 to 255
    // Fill entire strip with white at gamma-corrected brightness level 'j':
    pixels.fill(pixels.Color(0, 0, 0, pixels.gamma8(j)));
    pixels.show();
    delay(wait);
  }

  for(int j = 255; j >= 0; j--) { // Ramp down from 255 to 0
    pixels.fill(pixels.Color(0, 0, 0, pixels.gamma8(j)));
    pixels.show();
    delay(wait);
  }
}
