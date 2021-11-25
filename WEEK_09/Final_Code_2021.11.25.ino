//________________________________ INPUT 1
//________________________________ MPR121 12 CAPACITIVE TOUCH SENSOR

#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit))
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

//________________________________ INPUT 2
//________________________________ GALVANIC SKIN RESPONSE

const int GSR = A1;
const int LED = 13;
int sensorValue;
int gsr_average = 0;

//________________________________ OUTPUT 1
//________________________________ NEOPIXEL LED STRIP

#include <Adafruit_NeoPixel.h>

#define PIN D12
#define NUMPIXELS 5
#define BRIGHTNESS 50

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//________________________________ OUTPUT 2
//________________________________ MINI VIBRATION MOTOR

int switchPin = D2;
int pin_MOTOR = A0;
int switchState = 0;

int MOSFET_Val = 0;
bool T_F = 0;

//________________________________
//________________________________

void setup() {

  //Serial.begin(9600);

  //INITIALIZD NEOPIXEL LIBRARY
  pixels.begin();
  pixels.show();
  pixels.setBrightness(BRIGHTNESS);

  pinMode(pin_MOTOR, OUTPUT);
  pinMode(MOSFET_Val, OUTPUT);
  pinMode(switchPin, INPUT);

  //SET MOTOR TO 0 SO IT DOESN'T RUN THE MOMENT POWER IS SUPPLIED
  analogWrite(pin_MOTOR, 0);

  //PRINT LINE IF MPR121 IS DETECTED
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

  //CHECK WHETHER MPR121 IS WORKING CORRECTLY
if (!cap.begin(0x5A)) {
  Serial.println("MPR121 not found, check wiring?");
  while (1);
}
  Serial.println("MPR121 found!");
}

//________________________________
//________________________________

void loop() {

  long sum = 0;

  //LED ALWAYS START ON LOW
  pixels.clear();

for (int i = 0; i < 10; i++) {
  sensorValue = analogRead(GSR);
  sum += sensorValue;
  delay(5);
}

  gsr_average = sum / 10;
  Serial.println(gsr_average);

  //USING MPR121 TO CONTROL VIBRATION MOTOR
  vibrateMPR();

  //GSR VALUE WILL EITHER TRIGGER THE ALERT FUNCTION OR PATTERN FUNCTION
  //OTHERWISE, THE BRACELET WILL RUN THE VIBRATEMPR FUNCTION
if (gsr_average > 399 && gsr_average < 410) {
  alert();
}

else if (gsr_average > 410) {
  pattern();
}
}

//________________________________
//________________________________

void colorWipe(uint32_t color, int wait) {

for (int i = 0; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, color);
  pixels.show();
  delay(wait);
}
}

//________________________________
//________________________________

void vibrateMPR() {

  //GET CURRENTLY TOUCHED PADS
  currtouched = cap.touched();

for (uint8_t i = 0; i < 12; i++) {

  if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i < 5 ) {
    Serial.print(i); Serial.println(" touched");
    analogWrite(pin_MOTOR, 150);
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

  //RESET STATE
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;

  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i = 0; i < 12; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i = 0; i < 12; i++) {
    Serial.print(cap.baselineData(i)); Serial.print("\t");
  }
  Serial.println();

  // put a delay so it isn't overwhelming
  delay(100);
}

//________________________________
//________________________________

void alert () {
  
if (T_F == 0) {

  analogWrite(pin_MOTOR, 255);

for (int i = 1; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(150, 0, 0));
  pixels.show();
}

  pixels.clear();
  delay(500);
  
  analogWrite(pin_MOTOR, 0);

for (int i = 1; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
}

  pixels.clear();
  delay(500);
  
  analogWrite(pin_MOTOR, 255);

for (int i = 1; i < NUMPIXELS; i++) {
pixels.setPixelColor(i, pixels.Color(150, 0, 0));
pixels.show();
}

  pixels.clear();
  delay(500);
  
  analogWrite(pin_MOTOR, 0);

for (int i = 1; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
}
  
  pixels.clear();
  delay(500);
  
  analogWrite(pin_MOTOR, 255);

for (int i = 1; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(150, 0, 0));
  pixels.show();
}
  
  pixels.clear();
  delay(500);
  
  analogWrite(pin_MOTOR, 0);

for (int i = 1; i < NUMPIXELS; i++) {
  pixels.setPixelColor(i, pixels.Color(0, 0, 0));
  pixels.show();
}
  
  pixels.clear();
  
  T_F = 1; //To make sure this runs only once!

}
}

//________________________________
//________________________________

void pattern () {
  
if (T_F == 1) {
  colorWipe(pixels.Color(150,   0,   0)     , 50); // Red
  colorWipe(pixels.Color(  0, 150,   0)     , 50); // Green
  colorWipe(pixels.Color(  0,   0, 150)     , 50); // Blue
  colorWipe(pixels.Color(  0,   0,   0, 150), 50); // True white (not RGB white)

  delay(2000);

for (int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
  pixels.fill(pixels.Color(0, pixels.gamma8(j), 0));
  pixels.show();
  delay(10);
}

  delay(100);

for (int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
  pixels.fill(pixels.Color(pixels.gamma8(j), pixels.gamma8(j), pixels.gamma8(j)));
  pixels.show();
  delay(10);
}

  delay(100);

for (int j = 151; j >= 0; j--) { // Ramp down from 255 to 0
  pixels.fill(pixels.Color(pixels.gamma8(j), 0, pixels.gamma8(j)));
  pixels.show();
  delay(10);
}

  T_F = 0;
}
}
