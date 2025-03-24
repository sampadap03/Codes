#include <RohmMultiSensor.h>

RPR_0521RS TOF;

void setup() {
  Serial.begin(9600);
  Serial.println();
  Wire.begin();
  TOF.init();
  Serial.println("PROXY");
}

void loop() {
  TOF.measure();
  Serial.print(sensorAls.prox);
  delay(100);
}
