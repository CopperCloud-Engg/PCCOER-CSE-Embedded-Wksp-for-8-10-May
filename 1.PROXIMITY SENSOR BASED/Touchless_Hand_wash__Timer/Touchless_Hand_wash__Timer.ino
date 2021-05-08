const int Sensorpin = 2;     // the number of the pushbutton pin
const int TimerRelay =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(TimerRelay, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(Sensorpin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(Sensorpin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(TimerRelay, HIGH);
  } else {
    // turn LED off:
    digitalWrite(TimerRelay, LOW);
  }
}
