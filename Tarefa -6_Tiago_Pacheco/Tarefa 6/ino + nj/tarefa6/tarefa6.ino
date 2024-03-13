/* 
 * seriArduino
 * 
 * Versão: 2.0
 * 
 * Fisica Aplicada a Computacao - Engenharia Informatica
 * Departamento de Matematica e Ciencias Fisicas
 * 
 * Ano lectivo 2021-22
 * 
 * Nuno Pereira | nuno.pereira@ipbeja.pt
 * 
 * Hardware: Arduino nano 33 BLE SENSE
 * 
 * Descricao: comunica com PC via Serial Port
 *            dados lidos pelo pySeriArduino_v5
 * 
 * Recursos: -
 * 
 * CC-BY-SA 4.0
 */
#include <Arduino_HTS221.h>
//#define PLOTTER

// prototypes
void writeData(void);

// global variables
int long to;
int long dt = 100; // sampling interval (ms)
int n_samples = 100;
float pi = acos(-1.);
float T = .5; // period (s)
float w = 2.*pi/T; // angular velocity (rad/s)
float A = 2.; // amplitude
char strBuffer[30];

// initialization
void setup() {
  Serial.begin(115200);
  while(!Serial);
  if (!HTS.begin()) {
    Serial.println("Failed to initialize humidity temperature sensor!");
    while (1);
  }
}

// main loop
void loop() {
  writeData();
  Serial.println("end");
}

// functions
void writeData()
{
 
  to = millis();
  for (byte k = 0; k < n_samples; k++)
  {
    delay(100);
    int long t = millis() - to;
    float x = HTS.readTemperature();

    sprintf(strBuffer,"%d,%.6f", t, x);
    Serial.println(strBuffer);

  }
}
