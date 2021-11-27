<h1> Lab 01 | Project Proposal</h1>
<hr>
<h4>This lab will be submitted through moodles</h4> 

<br>
<br>

<h1> Lab 02 | Hook up A Servo</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138879074-0986c433-74a1-42a2-9088-2f368302099a.MOV

<br>
<br>

<h1> Lab 03 | Hook up A Motor</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138879283-2a7145fc-f0ed-4d8d-ae15-06bdb5ee0f4d.MOV

<br>
<br>

<h1> Lab 04 | Hook up An MPR121</h1>
<hr>

https://user-images.githubusercontent.com/92052904/138882558-431e3b11-1484-4c94-b04f-ee47796f921b.MOV

<img width="838" alt="Screenshot 2021-10-26 at 1 51 55 pm" src="https://user-images.githubusercontent.com/92052904/138882589-ff21fea3-7c25-4541-a10b-f75a2fc7a2ab.png">

<img width="856" alt="Screenshot 2021-10-26 at 1 52 04 pm" src="https://user-images.githubusercontent.com/92052904/138882599-5be4db43-5e3f-4d53-91df-d3d337e105f9.png">

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

![IMG_5920](https://user-images.githubusercontent.com/92052904/140052400-d00e538a-5415-4d2c-bbdc-6a6ea7ecb420.jpg)
