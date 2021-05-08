// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int count=0;                 //No of time input event coming
int lastButtonState = 0;     // previous state of the button

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState) {
          // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
          if (buttonState == HIGH) {
            // turn LED on:
            digitalWrite(ledPin, LOW);
            count++;
            Serial.print("No of times Input Event comming=");       
            Serial.println(count);
          } else {
            // turn LED off:
            digitalWrite(ledPin, HIGH);
          }
  }
  lastButtonState = buttonState; 
  
  delay(100);
}
