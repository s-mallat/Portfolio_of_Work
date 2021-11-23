#include <Wire.h>
#include "Adafruit_MPR121.h"
    
    #ifndef _BV
    #define _BV(bit) (1 << (bit)) 
    #endif

Adafruit_MPR121 cap = Adafruit_MPR121();

    uint16_t lasttouched = 0;
    uint16_t currtouched = 0;

#include <Adafruit_NeoPixel.h>

    int pin_MOTOR = A0; //Note: Connecting motor to analog pin to vary vibration output
    bool T_F = 0;

    int redColor = 0;
    int greenColor = 0;
    int blueColor = 0;
    int delayval = 200;

    //INPUT 1 -- GSR GALVANIC SKIN RESPONSE
    const int GSR=A1;
    const int LED=13;
    int sensorValue;
    int gsr_average=0;

#define PIN 3   // input pin Neopixel is attached to
// the PWM pin the LED is attached to

#define NUMPIXELS      5 // number of neopixels in Ring

#define BRIGHTNESS 50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  
      Serial.begin(9600);
      pixels.begin(); // Initializes the NeoPixel library.
      pixels.show();
      pixels.setBrightness(BRIGHTNESS);
      
      pinMode(pin_MOTOR, OUTPUT);
      analogWrite(pin_MOTOR, 0);

      pinMode(LED,OUTPUT);
digitalWrite(LED,LOW);
delay(1000);


      //PRINT LINE IF MPR121 IS DETECTED
    Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

//CHECK WHETHER MPR121 IS WORKING CORRECTLY    
   // if (!cap.begin(0x5A)) {
    //    Serial.println("MPR121 not found, check wiring?");
    //    while (1);
   // }
   // Serial.println("MPR121 found!");
}


void loop() {

       long sum = 0;
       pixels.clear();

       for (int i = 0; i<10;i++) {
        sensorValue = analogRead(GSR);
        sum += sensorValue;
        delay(5);
        }

        gsr_average = sum / 10;
        Serial.println(gsr_average);
 if (399 < gsr_average < 420) {      
     alert();
     vibrateMPR();

     
}  else if (gsr_average > 420) {
    breath();
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


void vibrateMPR() {
  
// GET THE CURRENTLY TOUCHED PADS
    currtouched = cap.touched();
    
    for (uint8_t i=0; i<12; i++) {
        // it if *is* touched and *wasnt* touched before, alert!
        if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i < 5 ) {
          Serial.print(i); Serial.println(" touched");
          analogWrite(pin_MOTOR, 255);
        } 
        if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i > 5 ) {
          Serial.print(i); Serial.println(" touched");
          analogWrite(pin_MOTOR, 0);
        } 
        if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) && i > 5 ) {
          Serial.print(i); Serial.println(" released");
          analogWrite(pin_MOTOR, 0);
        }
  }
  
    // reset our state
    lasttouched = currtouched;
  
    // comment out this line for detailed data from the sensor!
    return;
    
    // debugging info, what
    Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
    Serial.print("Filt: ");
    for (uint8_t i=0; i<12; i++) {
      Serial.print(cap.filteredData(i)); Serial.print("\t");
    }
    Serial.println();
    Serial.print("Base: ");
    for (uint8_t i=0; i<12; i++) {
      Serial.print(cap.baselineData(i)); Serial.print("\t");
    }
    Serial.println();
    
    // put a delay so it isn't overwhelming
    delay(100);
}

void alert () {
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
  
  }


void breath () {
    if (T_F == 1) {
      colorWipe(pixels.Color(150,   0,   0)     , 50); // Red
      colorWipe(pixels.Color(  0, 150,   0)     , 50); // Green
      colorWipe(pixels.Color(  0,   0, 150)     , 50); // Blue
      colorWipe(pixels.Color(  0,   0,   0, 150), 50); // True white (not RGB white)
    
      delay(2000);
    
      for(int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
        pixels.fill(pixels.Color(0, pixels.gamma8(j), 0));
        pixels.show();
        delay(10);
      }
      delay(100);
      for(int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
        pixels.fill(pixels.Color(pixels.gamma8(j), pixels.gamma8(j), pixels.gamma8(j)));
        pixels.show();
        delay(10);
      }
      delay(100);
      for(int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
        pixels.fill(pixels.Color(pixels.gamma8(j), 0, pixels.gamma8(j)));
        pixels.show();
        delay(10);
      }
  T_F = 0; 
  }
  }
