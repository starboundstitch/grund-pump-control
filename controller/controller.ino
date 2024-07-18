int x;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  pinMode(9, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(5, OUTPUT);
}

void  loop() {
  while (!Serial.available()) {
    delay(10);

  }
  x = Serial.readString().toInt();
  Serial.print(x);

  digitalWrite(9, LOW);
  digitalWrite(7, LOW);
  digitalWrite(5, LOW);

  if(x - 4 >= 0) {
    digitalWrite(9, HIGH);
    x -= 4;
  }
  if(x - 2 >= 0) {
    digitalWrite(7, HIGH);
    x -= 2;
  }
  if(x - 1 >= 0) {
    digitalWrite(5, HIGH);
    x -= 1;
  }
}
