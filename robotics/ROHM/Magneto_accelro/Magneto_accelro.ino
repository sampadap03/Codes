#include <RohmMultiSensor.h>
BM1422GMV sensorMag(INT_0);  //magnetometer 
KX022_1020 sensorAcc(INT_1); //Accelerometer

void acc_isr(void) {
  sensorAcc.setFlagDrdy();
}
void mag_isr(void) {
  sensorMag.setFlagDrdy();
}
void setup() {
  Serial.begin(9600);
  Serial.println();
  Wire.begin();
  // initialize the sensor with default settings
  // we have to provide the interrupt service routine to the .init() method
  sensorMag.init(mag_isr);
  // initialize KX022-1020 with the default values
  // we have to provide the interrupt service routine to the .init() method
  sensorAcc.init(acc_isr);

  Serial.println("X[uT]\tY[uT]\tZ[uT]\tX[g]\tY[g]\tZ[g]");
}

void loop() {
  if(sensorMag.measure() == 0||sensorAcc.measure() == 0) {
    // if the values were successfully measured, print them to the serial port
    Serial.print(sensorMag.magX);
    Serial.print('\t');
    Serial.print(sensorMag.magY);
    Serial.print('\t');
    Serial.print(sensorMag.magZ);
    Serial.print('\t');
    Serial.print(sensorAcc.accelX);
    Serial.print('\t');
    Serial.print(sensorAcc.accelY);
    Serial.print('\t');
    Serial.println(sensorAcc.accelZ);
  }

  delay(100);
}

