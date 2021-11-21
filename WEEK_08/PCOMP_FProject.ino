//INPUT 1 -- GSR GALVANIC SKIN RESPONSE
    const int GSR=A0;
    int sensorValue=0;
    int gsr_average=0;

//INPUT 2 -- MPR121 12 CAPACITIVE TOUCH SENSOR
    #include <Wire.h>
    #include "Adafruit_MPR121.h"
    
    #ifndef _BV
    #define _BV(bit) (1 << (bit)) 
    #endif

    Adafruit_MPR121 cap = Adafruit_MPR121();

    uint16_t lasttouched = 0;
    uint16_t currtouched = 0;
    
//OUTPUT 1 -- LED STRIP 
    #include <Adafruit_NeoPixel.h>
    #define PIN 2   // input pin Neopixel is attached to
    #define NUMPIXELS      14 // number of neopixels in Ring
    
    Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
    
    int delayval = 200; // timing delay
    int redColor = 0;
    int greenColor = 0;
    int blueColor = 0;

//OUTPUT 2 -- MINI VIBRATION MOTOR
    int pin_MOTOR = A0; //Note: Connecting motor to analog pin to vary vibration output
    bool T_F = 0;

// ------------------------------------------------------------------------------------ 
// ------------------------------------------------------------------------------------

void setup(){

    Serial.begin(9600);
    
// INITIALIZE NEOPIXEL LIBRARY   
    pixels.begin();

// INITIALIZE MOTOR & SET MOTOR PIN TO OFF BY DEFAULT    
    pinMode(pin_MOTOR, OUTPUT);
    analogWrite(pin_MOTOR, 0);

//DELAY ARDUINO START
    while (!Serial) {
        delay(10);
    }

//PRINT LINE IF MPR121 IS DETECTED
    Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

//CHECK WHETHER MPR121 IS WORKING CORRECTLY    
    if (!cap.begin(0x5A)) {
        Serial.println("MPR121 not found, check wiring?");
        while (1);
    }
    Serial.println("MPR121 found!");
}

// ------------------------------------------------------------------------------------ 
// ------------------------------------------------------------------------------------

void loop(){
    long sum = 0;
  
//AVERAGE THE 10 MEASUREMENTS TO REMOVE GLITCH
    for(int i = 0; i < 10; i++) {
        sensorValue = analogRead(GSR);
        sum += sensorValue;
        delay(5);
        }
        
     gsr_average = sum / 10;
     Serial.println(gsr_average);
  
     pixels.clear();

// ------------------------------------------------------------------------------------ 
// ------------------------------------------------------------------------------------ 
// CONNECTING ALL INPUTS & OUTPUTS
// ------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------ 

if (gsr_average < 230) {

//MOTOR RUNS ONCE ONLY WHEN GSR IS ACTIVATED TO GIVE USER A WARNING
      if (T_F == 0) {
      analogWrite(pin_MOTOR, 255);
      delay(500);
      analogWrite(pin_MOTOR, 0);
      delay(500);
      analogWrite(pin_MOTOR, 255);
      delay(500);
      analogWrite(pin_MOTOR, 0);
      delay(500);
      analogWrite(pin_MOTOR, 255);
      delay(500);
      analogWrite(pin_MOTOR, 0);

      T_F = 1; //To make sure this runs only once!
      
      }
      
//IF GSR ACTIVE --> ACTIVATE: LED STRIP & MPR121 & MOTOR 
      
     setColor(); 
     vibrateMPR();
     
     for(int i = 0; i < NUMPIXELS; i++) {
      
          // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
          pixels.setPixelColor(i, pixels.Color(redColor, greenColor, blueColor)); // Moderately bright green color.
      
          pixels.show(); // This sends the updated pixel color to the hardware.
      
          delay(delayval); // Delay for a period of time (in milliseconds).
                    
                if (i == NUMPIXELS){
                    i = 0; // start all over again!
                    setColor();
                }
     }
     
 }   else if (gsr_average > 230) {
            pixels.clear();
     }
}

// ------------------------------------------------------------------------------------ 
// ------------------------------------------------------------------------------------

void setColor() {
  
    redColor = random(0, 255);
    greenColor = random(0,255);
    blueColor = random(0, 255);
    
    Serial.print("red: ");
    Serial.println(redColor);
    
    Serial.print("green: ");
    Serial.println(greenColor);
    
    Serial.print("blue: ");
    Serial.println(blueColor); 
}

// ------------------------------------------------------------------------------------ 
// ------------------------------------------------------------------------------------

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
