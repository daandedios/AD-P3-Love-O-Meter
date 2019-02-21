//Developer:  Daan de Dios
//Date:       2019-02-14
//function:   Love-O-Meter


//----------------------global vars----------------------------------
const int sensorPin = A0;
const float baseTemp = 20.0;

int ledPins[] = {2, 3, 4}; 
int pinCount = 3;

//----------------------end-global vars------------------------------



//setup runs once, when the Arduino is first oiwerd on.
void setup() {
  Serial.begin(9600); // open a serial port
  
  for (int i = 0; i < pinCount; i ++) {
    pinMode(ledPins[i], OUTPUT);
    digitalWrite(ledPins, LOW);
  }

}


//loop runs continuously after the setup() has completed.
void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);


  // convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");



  // convert the voltage to temperature in degrees 
  float temperature;
  temperature = (voltage - .5) * 100;
  Serial.println(temperature);

  if(temperature < baseTemp){ 
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baseTemp+2 && temperature < baseTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baseTemp+4 && temperature < baseTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baseTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
  } 
  
  delay(1);

}