int echoPin = 3, triggerPin = 2, ledPin = 13;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(echoPin, INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int t, d;
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  t = pulseIn(echoPin, HIGH);
  d = t * 0.034 / 2;
  Serial.println(d);
  lightLed(d);

}
void lightLed(float d) {
  if (d < 15)
    digitalWrite(ledPin, HIGH);
  else digitalWrite(ledPin, LOW);

};
