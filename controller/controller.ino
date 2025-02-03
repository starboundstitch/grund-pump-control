#include <MCP4725.h>
#include <Wire.h>

MCP4725 dac(0x60);

// Global Vars
volatile byte stopState = 0;
static float curVoltage = 0;
static float newVoltage = 0;
const byte eStop = 2;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1);
  Wire.begin();
  dac.begin();
  dac.setValue(0);
}

String readSerial() {

  String text = "";
  char msg = Serial.read();
  while (msg != '\r') {
    if (Serial.available()) {
      text.concat(msg);
      msg = Serial.read();
    } else
      delay(.001);
  }

  return text;
}

void loop() {
  while (!Serial.available()) {
    delay(10);
  }

  float newVoltage = readSerial().toFloat();


  if (newVoltage != curVoltage) {
    dac.setVoltage(newVoltage * .05);
    curVoltage = newVoltage;
  }
}
