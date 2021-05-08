/* Sketch to find distance to obstacle using HC-SR04 Ultrasound Sensor */

// defines pins numbers
const int trigPin = 6;  //D5
const int echoPin = 7;  //D6
const int RelayPin =  13;

// defines variables
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(RelayPin, OUTPUT);
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}

void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println("cm");
  if((distance<30)&&(distance>5)){
    digitalWrite(RelayPin, LOW);
  }
  else{digitalWrite(RelayPin, HIGH);}
  delay(1000);
}
