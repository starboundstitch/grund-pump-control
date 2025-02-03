#include <MCP4725.h>
#include <Wire.h>

MCP4725 dac(0x62);

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

  static float curVoltage = 0;
  float newVoltage = readSerial().toFloat();


  if (newVoltage != curVoltage) {
    dac.setVoltage(newVoltage * .05);
    curVoltage = newVoltage;
  }
}
