const int sensorPin = A0;
const float baselineTemp = 22.0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int pins = 2; pins < 7; pins++){
  pinMode(pins,OUTPUT);
  digitalWrite(pins,LOW);
}
}

void loop() {
  // put your main code here, to run repeatedly:

  int sensorVal = analogRead(sensorPin);
  float voltage = (sensorVal/ 1024.0) *5.0;
  float Temp = (voltage-0.5)*100;
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);
  Serial.print(", Voltage: ");
  Serial.print(voltage);
  Serial.print(", Temp: ");
  Serial.print(Temp);

  if (Temp < baselineTemp){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if (Temp > baselineTemp +1 && Temp < baselineTemp +2){
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if (Temp > baselineTemp +2 && Temp <baselineTemp +3) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
     digitalWrite(5,LOW);
    digitalWrite(6,LOW);
  }
  else if (Temp > baselineTemp +4 && Temp < baselineTemp +5){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
     digitalWrite(5,LOW);
    digitalWrite(6,LOW);
}
else if (Temp > baselineTemp +5 && Temp < baselineTemp +6){
  digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
}
else if (Temp > baselineTemp +6){
  digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
     digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
}
delay(10);
  }

