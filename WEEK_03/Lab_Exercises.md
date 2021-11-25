<h1> Lab 00 | Soldering </h1>
<hr>
<h4>This lab was completed in class (image below of soldered button)</h4> 

![IMG_4209](https://user-images.githubusercontent.com/92052904/137774623-2d84bb75-1e65-4f5d-bdc7-2215451774cb.jpg)

![IMG_4208](https://user-images.githubusercontent.com/92052904/137774632-eb94b94f-46d8-4ac2-a4ce-6bdf58680f83.jpg)

<br>
<br>

<h1> Lab 01 | PWM (Pulse Width Modulation)  </h1>
<hr>


https://user-images.githubusercontent.com/92052904/137776039-c6f1849d-b8cd-4fc5-94fe-27aa8e91798b.mp4

<h4>Arduino Code</h4>

```C++
int ledPin = 9;
int brightness = 0;
int fadeDeg = 5;

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  analogWrite(ledPin, brightness);

  brightness = brightness + fadeDeg;

  if (brightness <= 0 || brightness >= 255) {
    fadeDeg = -fadeDeg;
  }
  delay(50);
}
```

<br>
<br>

<h1>Lab 02 | Voltage Dividers</h1>
<hr>
<h4>Voltage Divider using a Potentiometer</h4>

https://user-images.githubusercontent.com/92052904/137778023-1dba545a-184c-4578-920a-4f88a6249bed.mp4

<h4>Arduino Code</h4>

```C++
int ledPin = 3;
int p_Pin = A0;

void setup() {
  pinMode(ledPin, OUTPUT);                  
  pinMode(p_Pin, INPUT);
}

void loop() {
  int p_Reading = analogRead(p_Pin) / 4; 
  analogWrite(ledPin, p_Reading);
}
```

<br><br>
<h4>Voltage Divider using a Light Dependent Resistor (LDR)</h4>

https://user-images.githubusercontent.com/92052904/137782607-49044cd7-a6ad-4a59-8b88-75961f1ac60c.mp4

<img width="841" alt="Screenshot 2021-10-18 at 6 50 26 pm" src="https://user-images.githubusercontent.com/92052904/137782665-875726d9-74e4-4629-af65-aa16e17fd4d4.png">

<h4>Arduino Code</h4>

```C++
int ledPin = 11; 
int sensorPin = A0; 

int ledValue; 
int sensorValue;

void setup() { 
  Serial.begin (9600);
  pinMode (ledPin, OUTPUT); 
}

void loop() {  
  sensorValue = analogRead (sensorPin); 
  delay (5); 
  
  Serial.print("Sensor Values: ");
  Serial.println(sensorValue); 
  
  ledValue = sensorValue/4; 

  Serial.print("LED Value: ");  
  Serial.println(ledValue);
 
  analogWrite(ledPin, ledValue); 
}
```

<br>
<br>

<h1>Lab 03 | Dark detecting Circuit</h1>
<hr>

https://user-images.githubusercontent.com/92052904/137903791-51a89fe9-f6f9-44e7-95ef-8365ebea19da.mp4

![IMG_4218](https://user-images.githubusercontent.com/92052904/137904256-f0000d79-1cb5-4c8f-a154-b6eafdaf99ad.jpg)

<img width="697" alt="Screenshot 2021-10-19 at 12 52 51 pm" src="https://user-images.githubusercontent.com/92052904/137904014-dda38459-12b0-42c1-981a-2663c3240cac.png">


<h1>Dark Detection Circuit Variation</h1>
<hr>


https://user-images.githubusercontent.com/92052904/143504701-3de8aa8a-2e4e-47a4-be77-90dd461617f9.mp4

![IMG_6092 2](https://user-images.githubusercontent.com/92052904/143504968-bcc28e2c-619f-4c65-88ee-c4978bfe69be.jpg)

<h4>Arduino Code</h4>

```c++
int pin = 9;
int pin2 = 10;
int pin3 = 11;

int brightness = 0;
int fadeAmount = 5;

int Photo_Pin = A0;

void setup() {

  pinMode(pin, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(Photo_Pin, INPUT);
}


void loop() {
 int readPhoto = analogRead(Photo_Pin);
  
 if (readPhoto > 50) {
      analogWrite(pin, 0);
      analogWrite(pin2, 0);
      analogWrite(pin3, 0);

  } else if (readPhoto < 50) {
      analogWrite(pin, brightness);
      analogWrite(pin2, brightness);
      analogWrite(pin3, brightness);

      brightness = brightness + fadeAmount;
      
      if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;

  } else if (readPhoto == 0) {
      analogWrite(pin, brightness);
      analogWrite(pin2, brightness);
      analogWrite(pin3, brightness);

      brightness = brightness + fadeAmount;
      
      if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;

  }
  
  delay(90);

}
}
}
```

<br>
<br>

<h1>Lab 03B |  Touch Sensor</h1>
<hr>


https://user-images.githubusercontent.com/92052904/137910780-4be5ced2-b477-4182-bf8c-4b5b0cbbaeeb.mp4

![IMG_5373](https://user-images.githubusercontent.com/92052904/137910928-2cec473d-66ab-4ce9-9185-c76b599560ab.jpg)

<img width="695" alt="Screenshot 2021-10-19 at 1 39 57 pm" src="https://user-images.githubusercontent.com/92052904/137911212-fd8ce549-4e4d-4ba7-8dbb-4dd5dd84a7eb.png">

<br>
<br>

<h1>Lab 04 |  Feedback Systems</h1>
<hr>


https://user-images.githubusercontent.com/92052904/138115983-dabf54c7-9d8d-477d-8ca8-29f53ae35b64.mp4

<img width="814" alt="Screenshot 2021-10-20 at 3 55 32 pm" src="https://user-images.githubusercontent.com/92052904/138117933-353595cc-340b-4add-b656-6fa3cc29806e.png">
