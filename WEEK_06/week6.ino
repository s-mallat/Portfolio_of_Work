int pin = A0; 
int pin1 = A1; 
int pin2 = A2; 
int pin3 = A3; 
int pin4 = A4; 
int sensorValue = 0; 
int sensorValue1 = 0; 
int sensorValue2 = 0; 
int sensorValue3 = 0; 
int sensorValue4 = 0; 

int total;
void setup()
{
 Serial.begin(9600); 
}

void loop()
{
  sensorValue = analogRead(pin1); 
  sensorValue1 = analogRead(pin2); 
  sensorValue2 = analogRead(pin3); 
  sensorValue3 = analogRead(pin4); 

  total = sensorValue + sensorValue1 + sensorValue2 + sensorValue3;

  Serial.print("\t");
  Serial.println(total);
  
  int thisPitch = map(total,3500,4000, 120, 1500);
  tone(9, thisPitch, 10);
    
  delay(1); 
}
