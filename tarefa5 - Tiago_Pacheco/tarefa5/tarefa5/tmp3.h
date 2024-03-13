#ifndef tmp3
#define tmp3

#define magneticplotter
#define magneticmonitor
#define gyromonitor
#include <Arduino_LSM9DS1.h>

#define accmonitor
float maximum4 = -1000;
float minimum4 = 1000;
float maximum5 = -1000;
float minimum5 = 1000;
float maximum6 = -1000;
float minimum6 = 1000;

float maximum7 = -1000;
float minimum7 = 1000;
float maximum8 = -1000;
float minimum8 = 1000;
float maximum9 = -1000;
float minimum9 = 1000;

float maximum10 = -1000;
float minimum10 = 1000;
float maximum11 = -1000;
float minimum11 = 1000;
float maximum12 = -1000;
float minimum12 = 1000;

#ifdef accmonitor
float acc() {

  Serial.println("Acellaration");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  Serial.print("Accelerometer sample rate = ");
  Serial.print(IMU.accelerationSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Acceleration in G's");
  Serial.println("X\tY\tZ");

  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    Serial.println(x);
    Serial.println('\t');
    Serial.println(y);
    Serial.println('\t');
    Serial.println(z);

float sensorValue5 = x;

  if (sensorValue5< minimum4) {

    minimum4 = sensorValue5;
  }

  if (sensorValue5 > maximum4  ) {

    maximum4 = sensorValue5;
  }

float sensorValue6 = y;

  if (sensorValue6< minimum5) {

    minimum5 = sensorValue6;
  }

  if (sensorValue6 > maximum5  ) {

    maximum5 = sensorValue6;
  }

  float sensorValue7 = z;

  if (sensorValue7< minimum6) {

    minimum6 = sensorValue7;
  }

  if (sensorValue7 > maximum6  ) {

    maximum6 = sensorValue7;
  }


  
  }
}
#endif

#ifdef accplotter
float plotteracc() {
  Serial.println("Acellaration");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  float x, y, z;

  IMU.readAcceleration(x, y, z);

  Serial.print("X:")
  Serial.print(x);
  Serial.print(',');
  Serial.print("Y:")
  Serial.print(y);
  Serial.print(',');
  Serial.print("Z:")
  Serial.print(z);
  Serial.println();
}

#endif

#ifdef gyromonitor

float gyriscope() {

  Serial.println("Gyriscope");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Gyroscope sample rate = ");
  Serial.print(IMU.gyroscopeSampleRate());
  Serial.println(" Hz");
  Serial.println();
  Serial.println("Gyroscope in degrees/second");
  Serial.println("X\tY\tZ");

  float x, y, z;

  if (IMU.gyroscopeAvailable()) {
    IMU.readGyroscope(x, y, z);

    Serial.println(x);
    Serial.println('\t');
    Serial.println(y);
    Serial.println('\t');
    Serial.println(z);


    float sensorValue8 = x;

  if (sensorValue8< minimum7) {

    minimum7 = sensorValue8;
  }

  if (sensorValue8 > maximum7  ) {

    maximum7 = sensorValue8;
  }

float sensorValue9 = y;

  if (sensorValue9< minimum8) {

    minimum8 = sensorValue9;
  }

  if (sensorValue9 > maximum8  ) {

    maximum8 = sensorValue9;
  }

  float sensorValue10 = z;

  if (sensorValue10< minimum9) {

    minimum9 = sensorValue10;
  }

  if (sensorValue10 > maximum9  ) {

    maximum9 = sensorValue10;
  }
  }
}
#endif

#ifdef gyroplotter

float gyroscopeplotter() {
  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  float x, y, z;

  IMU.readGyroscope(x, y, z);
  Serial.print("x:")
  Serial.print(x);
  Serial.print(',');
  Serial.print("y:")
  Serial.print(y);
  Serial.print(',');
  Serial.print("z:")
  Serial.print(z);
  Serial.println();
}
#endif

#ifdef magneticmonitor
float magnetic() {

  Serial.println("Magnetic");

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
  Serial.print("Magnetic field sample rate = ");
  Serial.print(IMU.magneticFieldSampleRate());
  Serial.println(" uT");
  Serial.println();
  Serial.println("Magnetic Field in uT");
  Serial.println("X\tY\tZ");

  float x, y, z;

  if (IMU.magneticFieldAvailable()) {
    IMU.readMagneticField(x, y, z);

    Serial.print(x);
    Serial.print('\t');
    Serial.print(y);
    Serial.print('\t');
    Serial.println(z);


    float sensorValue11 = x;

  if (sensorValue11< minimum10) {

    minimum10 = sensorValue11;
  }

  if (sensorValue11 > maximum10  ) {

    maximum10 = sensorValue11;
  }

float sensorValue12 = y;

  if (sensorValue12< minimum11) {

    minimum11 = sensorValue12;
  }

  if (sensorValue12 > maximum11  ) {

    maximum11 = sensorValue12;
  }

  float sensorValue13 = z;

  if (sensorValue13< minimum12) {

    minimum12 = sensorValue13;
  }

  if (sensorValue13 > maximum12  ) {

    maximum12 = sensorValue13;
  }
  }
}
#endif

#ifdef magneticplotter

float magneticplotter1() {

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  float x, y, z;

  IMU.readMagneticField(x, y, z);
  Serial.print ("X:");
  Serial.print(x);
  Serial.print(',');
  Serial.print ("Y:");
  Serial.print(y);
  Serial.print(',');
  Serial.print ("Z:");
  Serial.print(z);
  Serial.println();
}

#endif
#endif
