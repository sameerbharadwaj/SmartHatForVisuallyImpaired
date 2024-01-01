int epin = 9;
int tpin = 10;
int dur;
int dist;
void setup() {
  pinMode(epin, INPUT);
  pinMode(tpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(tpin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(tpin, LOW);
  dur = pulseIn(epin, HIGH);
  dist = (dur / 2) / 29.1;
  Serial.print(dist);
  Serial.println("CM");
  delay(1000);

}
