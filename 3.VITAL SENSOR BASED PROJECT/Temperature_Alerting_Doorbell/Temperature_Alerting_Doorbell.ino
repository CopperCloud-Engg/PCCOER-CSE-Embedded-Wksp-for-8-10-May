const int DoorbellRelay =  13;
int sensorPin = A0;
int sensorValue = 0; 


void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(DoorbellRelay, OUTPUT);
}

void loop() {
    sensorValue = analogRead(sensorPin);
    Serial.print("Sensor_value=");
    Serial.println(sensorValue);
    if(sensorValue>=250){digitalWrite(DoorbellRelay,HIGH);}
    else{digitalWrite(DoorbellRelay,LOW);}
    delay(1000);
}
