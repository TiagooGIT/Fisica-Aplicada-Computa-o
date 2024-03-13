#ifndef tmp
#define tmp
#define monitore
#define plotpressure
#include <Arduino_HTS221.h>

float maximum = -1000;
float minimum = 1000;
float maximum1 = -1000;
float minimum1 = 1000;
float media ;
float media1 ;

#ifdef monitore
float monitorehts(int c) {
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }

  float temperature = HTS.readTemperature();

  // print the sensor value
  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" kPa");

  float humidity    = HTS.readHumidity();

  // print the sensor value
  Serial.print("Humidity = ");
  Serial.print(humidity);
  Serial.println(" C");
  Serial.println();
 
  float sensorValue = temperature;

  if (sensorValue < minimum) {

    minimum = sensorValue;
  }

  if (sensorValue > maximum  ) {

    maximum = sensorValue;
  }

  float total = 0;

  for (int i = 0; i < c; i++) {

    total = total + sensorValue;
    media = total / c;

  }

  //-----------------------------------------------------------//

  float sensorValue1 = humidity;

  if (sensorValue1 < minimum1) {

    minimum1 = sensorValue1;
  }

  if (sensorValue1 > maximum1  ) {

    maximum1 = sensorValue1;
  }

  float total1 = 0;

  for (int i = 0; i < c; i++) {

    total1 = total1 + sensorValue1;
    media1 = total1 / c;

  }

  Serial.println();
  delay(1000);

}
#endif

#ifdef plotpressure
float pressureplotter() {
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }

  float temperature = HTS.readTemperature();
  float humidity    = HTS.readHumidity();

  Serial.print("sensor1:");
  Serial.print(temperature);

  Serial.print(',');
  Serial.print("sensor2:");

 
  Serial.print(humidity);

  Serial.println();
  
}
#endif
#endif
