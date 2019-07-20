
void setup() {
  // put your setup code here, to run once:
//  Serial.begin(9600);
  for(int i=0;i<13;i++){
    pinMode(i,OUTPUT);
    }
  

}

void loop() {
  digitalWrite(2,HIGH);
  digitalWrite(0,HIGH);
  delay(2000);
  //Serial.println(getTemperature(A5));

}

int getTemperature(int pin) {
  int temp = 0;
  temp = analogRead(pin);
  return temp * 500 / 1023;
}
