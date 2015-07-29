/* Arduino customer feedback sample */

// digital pin 13 has a pushbutton attached to it. Give it a name:
int pushButtonGood = 4;
int pushButtonOK = 5;
int pushButtonBad = 6;

int goodLedPin = 9;
int okLedPin = 12;
int badLedPin = 13;

bool goodDown = false;
bool okDown = false;
bool badDown = false;
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // make the pushbutton's pins an input:
  pinMode(pushButtonGood, INPUT);
  pinMode(pushButtonOK, INPUT);
  pinMode(pushButtonBad, INPUT);

  // Make led pins output
  pinMode(goodLedPin, OUTPUT);
  pinMode(okLedPin, OUTPUT);
  pinMode(badLedPin, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input pins:
  int buttonStateGood = digitalRead(pushButtonGood);
  int buttonStateOK = digitalRead(pushButtonOK);
  int buttonStateBad = digitalRead(pushButtonBad);

  // process the good button
  if(buttonStateGood && !goodDown) {
    goodDown = true;
    Serial.println('G');
    digitalWrite(goodLedPin, HIGH);
  } else if(!buttonStateGood && goodDown) {
    goodDown = false;
    digitalWrite(goodLedPin, LOW);
  }

  // process the OK button
  if(buttonStateOK && !okDown) {
    okDown = true;
    Serial.println('O');
    digitalWrite(okLedPin, HIGH);
  } else if(!buttonStateOK && okDown) {
    okDown = false;
    digitalWrite(okLedPin, LOW);
  }

  // process the bad button
  if(buttonStateBad && !badDown) {
    badDown = true;
    Serial.println('B');
    digitalWrite(badLedPin, HIGH);
  } else if(!buttonStateBad && badDown) {
    badDown = false;
    digitalWrite(badLedPin, LOW);
  }

  delay(1);        // delay in between reads for stability
}
