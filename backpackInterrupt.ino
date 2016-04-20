long lastTapRight = millis();
long lastTapLeft = millis();

int rightLEDPin = 12;
int leftLEDPin = 10;

int howLongToBlink = 2000; // 2000 is 2 seconds. How long to keep blinking after piezo is triggered.
int blinkLength = 200;

void setup() {
  pinMode(rightLEDPin, OUTPUT);
  pinMode(leftLEDPin, OUTPUT);
  attachInterrupt(1, right, RISING); //SDA on flora attach right piezo INT1, digital pin 2
  attachInterrupt(0, left, RISING); //SCL on flora attach left piezo. INT0, digital pin 3.
}

void loop() {
  // put your main code here, to run repeatedly:
  if (lastTapRight > lastTapLeft) {
    if (lastTapRight > millis() - howLongToBlink) { //If the left sensor was tapped in the last 2 second (millis() - 2000), blink. Edit '2000' to change the time it blinks.
      blinkRight(); //blink once
      report(); //debug report to serial. 
    }
  } else {
    if (lastTapLeft > millis() - howLongToBlink) { //If the right sensor was tapped in the last 2 second (millis() - 2000), blink. Edit '2000' to change the time it blinks.
      blinkLeft();
      report(); //debug report to serial
    }
  }
}

void right() {
  lastTapRight = millis(); //store the current time in a variable to check against. millis() returns milliseconds that have passed since the program started
}

void left() {
  lastTapLeft = millis();
}

void blinkRight() {
  digitalWrite(rightLEDPin, HIGH);
  delay(blinkLength);
  digitalWrite(rightLEDPin, LOW);
  delay(blinkLength);
}

void blinkLeft() {
  digitalWrite(leftLEDPin, HIGH);
  delay(blinkLength);
  digitalWrite(leftLEDPin, LOW);
  delay(blinkLength);
}

void report() {
  Serial.print("Right: ");
  Serial.print(lastTapRight);
  Serial.print("   Left: ");
  Serial.println(lastTapLeft);
}


