/* Arduino proximity sensor sample */

#define trigPin 12
#define echoPin 11

int counter;
bool isMoving;
bool isStopped;

const int maxDistance = 5;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  counter = 0;

  isStopped = false;
  isMoving = false;
}

void loop() {
  long duration, duration2, distance, distance2;

  // proximity sensor reads distance

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;

  // process the distance data

  if (distance < maxDistance) {  //if obstacle is detected
    if(counter >= 4){
      if(!isStopped) {
        Serial.println("S");
      }
      isStopped = true;
      isMoving = false;
    }
  } else {
    if(!isMoving) {
      Serial.println("M");
      isMoving = true;
      isStopped = false;
    }

    counter = 0;
  }

  counter ++;

  delay(1000);
}
