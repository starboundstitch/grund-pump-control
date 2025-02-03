#include <MCP4725.h>
#include <Wire.h>

MCP4725 dac(0x60);

// Global Vars
volatile byte stopState = 0;
static float curVoltage = 0;
static float newVoltage = 0;
const byte eStop = 2;

void setup() {

  // Serial Setup
  Serial.begin(9600);
  Serial.setTimeout(1);

  // I2C Setup
  Wire.begin();
  dac.begin();
  dac.setValue(0);

  // Set Stop Interrupt
  pinMode( eStop, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(eStop), stop, CHANGE);

  // Set Stopstate Based on Button
  if (digitalRead(eStop == HIGH)) {
    stopState = 1;
  }
}

// E-Stop Interrupt Function
void stop() {
    if (digitalRead(eStop) == HIGH) {
      stopState = 1;
    } else
      stopState = 0;
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

  // Set Voltage Loop (and check for serial data available)
  while (!Serial.available()) {
    if (stopState == 1) {
      dac.setVoltage(0);
      curVoltage = 0;
    }
    else if (newVoltage != curVoltage) {
      dac.setVoltage(newVoltage);
      curVoltage = newVoltage;
    }
    delay(10);
  }

  newVoltage = readSerial().toFloat() * .05;

}
