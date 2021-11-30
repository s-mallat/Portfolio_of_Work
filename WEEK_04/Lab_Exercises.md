<h1> Lab 01 | Project Proposal</h1>
<hr>
<h4>This lab will be submitted through moodles</h4> 

<br>
<br>

<h1> Lab 02 | Hook up A Servo</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138879074-0986c433-74a1-42a2-9088-2f368302099a.MOV

![Copy of SERVO MOTOR](https://user-images.githubusercontent.com/92052904/144074491-0f8f62ee-144f-4c71-9fdf-0c0fd559605d.png)


<br>
<br>

<h1> Lab 03 | Hook up A Motor</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138879283-2a7145fc-f0ed-4d8d-ae15-06bdb5ee0f4d.MOV

![Copy of Dc motor + Push button](https://user-images.githubusercontent.com/92052904/144074535-ca4e5a86-1a5e-4aa1-9054-672cc52845da.png)


<br>
<br>

<h1> Lab 04 | Hook up An MPR121</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138882558-431e3b11-1484-4c94-b04f-ee47796f921b.MOV

<img width="838" alt="Screenshot 2021-10-26 at 1 51 55 pm" src="https://user-images.githubusercontent.com/92052904/138882589-ff21fea3-7c25-4541-a10b-f75a2fc7a2ab.png">

<h1> Lab 04 Extra | Having Fun with the MPR121</h1>
<hr>


https://user-images.githubusercontent.com/92052904/143719087-ea70dc45-c06b-42ea-8c73-2a2574038fac.mp4

![IMG_4261-2](https://user-images.githubusercontent.com/92052904/143719185-81d94e87-1868-492c-8a3f-84f1f835103b.jpg)

```C++
#include <Wire.h>
#include "Adafruit_MPR121.h"

#ifndef _BV
#define _BV(bit) (1 << (bit)) 
#endif

Adafruit_MPR121 cap = Adafruit_MPR121();

#define NOTE_C4  262
#define NOTE_G3  396
#define NOTE_A3  90
#define NOTE_B3  247
#define NOTE_C4  262

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int noteDurations[] = {
  700, 120, 80, 550, 140, 240, 100, 20
};

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {
  Serial.begin(9600);

  while (!Serial) { 
    delay(10);
  }
  
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test"); 
  
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");
}

void loop() {
  currtouched = cap.touched();
  
  for (uint8_t i=0; i<12; i++) {
    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i == 0 ) {
      Serial.print(i); Serial.println(" touched");
        tone(12, melody[0], noteDurations[0]);
    }

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i == 3 ) {
      Serial.print(i); Serial.println(" touched");
        tone(12, melody[1], noteDurations[1]);
    }

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i == 5 ) {
      Serial.print(i); Serial.println(" touched");
        tone(12, melody[2], noteDurations[2]);
    }

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i == 7 ) {
      Serial.print(i); Serial.println(" touched");
        tone(12, melody[3], noteDurations[3]);
    }

    if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) && i == 10 ) {
      Serial.print(i); Serial.println(" touched");
        tone(12, melody[4], noteDurations[5]);
    }
    // if it *was* touched and now *isnt*, alert!
    if (!(currtouched & _BV(i)) && (lasttouched & _BV(i)) ) {
      Serial.print(i); Serial.println(" released");
    }
  }

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
```

<br>
<br>

<h1> Lab 05 | The Capsense Library </h1>
<hr>

https://user-images.githubusercontent.com/92052904/143721713-a0854c56-c804-4065-ada7-617aed724d53.mp4

![IMG_6115](https://user-images.githubusercontent.com/92052904/143721715-3c9e2c9c-3e49-4f7e-a640-b15ab29089f5.jpg)

```C++
#include <CapacitiveSensor.h>

/*
 * CapitiveSense Library Demo Sketch
 * Paul Badger 2008
 * Uses a high value resistor e.g. 10M between send pin and receive pin
 * Resistor effects sensitivity, experiment with values, 50K - 50M. Larger resistor values yield larger sensor values.
 * Receive pin is the sensor pin - try different amounts of foil/metal on this pin
 */


CapacitiveSensor   cs_4_2 = CapacitiveSensor(4,2);        // 10M resistor between pins 4 & 2, pin 2 is sensor pin, add a wire and or foil if desired
CapacitiveSensor   cs_4_6 = CapacitiveSensor(4,6);        // 10M resistor between pins 4 & 6, pin 6 is sensor pin, add a wire and or foil
CapacitiveSensor   cs_4_8 = CapacitiveSensor(4,8);        // 10M resistor between pins 4 & 8, pin 8 is sensor pin, add a wire and or foil

int LED = 7;
int LED_2 = 12;
int LED_3 = 9;

void setup()                    
{
   cs_4_2.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);

   pinMode(LED, OUTPUT);
   digitalWrite(LED, HIGH);
   pinMode(LED_2, OUTPUT);
   pinMode(LED_3, OUTPUT);

}

void loop()                    
{
    long start = millis();
    long total1 =  cs_4_2.capacitiveSensor(30);
    long total2 =  cs_4_6.capacitiveSensor(30);
    long total3 =  cs_4_8.capacitiveSensor(30);


    if (total1 > 500 && total1 < 800) {
      digitalWrite(LED, LOW);
      delay(50);
      digitalWrite(LED_2, HIGH);
      tone(11, 200, 100);
      }

    if (total1 > 800) {
      digitalWrite(LED, LOW);
      delay(50);
      digitalWrite(LED_3, HIGH);
      tone(11, 100, 100);
      }

    if (total2 > 500 && total2 < 800) {
      digitalWrite(LED_2, LOW);
      delay(50);
      digitalWrite(LED_3, HIGH);
      tone(11, 200, 100);
      }

    if (total2 > 800) {
      digitalWrite(LED_2, LOW);
      delay(50);
      digitalWrite(LED, HIGH);
      tone(11, 500, 800);
      }

    if (total3 > 500 && total3 < 800) {
      digitalWrite(LED_3, LOW);
      delay(50);
      digitalWrite(LED_2, HIGH);
      tone(11, 200, 100);
      }
      
    if (total3 > 800) {
      digitalWrite(LED_3, LOW);
      delay(50);
      digitalWrite(LED, HIGH);
      tone(11, 200, 100);
      }
    

    Serial.print(millis() - start);        // check on performance in milliseconds
    Serial.print("\t");                    // tab character for debug windown spacing

    Serial.print(total1);                  // print sensor output 1
    Serial.print("\t");
    Serial.print(total2);                  // print sensor output 2
    Serial.print("\t");
    Serial.println(total3);                // print sensor output 3

    delay(10);                             // arbitrary delay to limit data to serial port 
}
```
