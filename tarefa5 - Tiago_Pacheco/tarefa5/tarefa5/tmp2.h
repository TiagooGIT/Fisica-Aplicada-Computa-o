#ifndef tmp2
#define tmp2

#define sensorlps_monitor
#define sensorlps_plotter
#include <Arduino_LPS22HB.h>

#ifdef sensorlps_monitor

float maximum2 = -1000;
float minimum2 = 1000;
float maximum3 = -1000;
float minimum3 = 1000;
float media2 ;
float media3 ;

float monitorlps(int c) {

  if (!BARO.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
  // read all the sensor values
  float pressure = BARO.readPressure();

  // print the sensor value
  Serial.print("Pressure = ");
  Serial.print(pressure);
  Serial.println(" kPa");

  float temperature = BARO.readTemperature();

  // print the sensor value
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");
  Serial.println();
  delay(1000);


  float sensorValue2 = temperature;

  if (sensorValue2 < minimum2) {

    minimum2 = sensorValue2;
  }

  if (sensorValue2 > maximum2  ) {

    maximum2 = sensorValue2;
  }

  float total2 = 0;

  for (int i = 0; i < c; i++) {

    total2 = total2 + sensorValue2;
    media2 = total2 / c;

  }

  //-----------------------------------------------------------//

  float sensorValue3 = pressure;

  if (sensorValue3 < minimum3) {

    minimum3 = sensorValue3;
  }

  if (sensorValue3 > maximum3  ) {

    maximum3 = sensorValue3;
  }

  float total3 = 0;

  for (int i = 0; i < c; i++) {

    total3 = total3 + sensorValue3;
    media3 = total3 / c;

  }
}
#endif

#ifdef sensorlps_plotter
  float plotterlps() {

    if (!BARO.begin()) {
      Serial.println("Failed to initialize humidity temperature sensor!");
      while (1);
    }

    float pressure = BARO.readPressure();
    float temperature1 = BARO.readTemperature();

    Serial.print("Sensor1:");
    Serial.print(pressure);
    Serial.print(',');
    Serial.print("Sensor2:");
    Serial.print(temperature1);
    Serial.println();

  }
#endif
#endif
