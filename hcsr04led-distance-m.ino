
const int trigPin = 7; // trigger pin output (pin 7)
const int echoPin = 8; // echo pin output (pin 8)

void setup() {
  // initialize led pin
  pinMode(13, OUTPUT); // 1st Red 
  pinMode(12, OUTPUT); // 2nd Red
  pinMode(4, OUTPUT);  // 1st White
  pinMode(2, OUTPUT);  // 2nd White

  // initialize serial communication:
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  long duration, inches, cm;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  // light up led according to object distance
  if (cm <= 10) {
    digitalWrite(13, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
  } else if (cm <= 15) {
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
  } else if (cm <= 20) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(2, HIGH);
  } else if (cm <= 30) {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(4, LOW);
    digitalWrite(2, LOW);
  }

  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(100);
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
