#define TYPE float

#include "tmp.h"
#include "tmp2.h"
#include "tmp3.h"
#define plotpressure
void setup() {
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  menu();
  //pressureplotter();
}

  float menu() {
  
  Serial.println("Menu Tarefa 5");
  Serial.println("1: sensor");
  Serial.println("2: sensor");
  Serial.println("3: sensor");
  Serial.println("4: Quit");

  while (Serial.available() < 1);
  int a = Serial.parseInt();
  Serial.println(a);

  Serial.println();
  
  Serial.println("Determine se quer uma leitura simples (1) ou multípla (2)?");
  while (Serial.available() < 1);
  int b = Serial.parseInt();

  if (b == 2) {
    Serial.println("Quantas vezes pretende ?");
  }

  while (Serial.available() < 1 && b == 2);
  int c  = Serial.parseInt();

  
 b == 1 ? c = 1 : c;

  int i = 0;
  switch (a) {

    case 1:

      if (b == 1) {
        monitorehts(c);
        Serial.print("O valor minimo é: " );
        Serial.println(minimum);

        Serial.print("O valor maximo é: ");
        Serial.println(maximum);

        Serial.print("A média aritmética é: ");
        Serial.println(media);

        Serial.print("O valor minimo da Humidade é: " );
        Serial.println(minimum1);

        Serial.print("O valor maximo da Humidade é: ");
        Serial.println(maximum1);

        Serial.print("A média aritmética da Humidade é: ");
        Serial.println(media1);
        Serial.println();
        break;
      }

      if (b == 2) {

        while (i < c) {
          monitorehts(c);
          i++;
          delay(1000);
        }
        
        Serial.print("O valor minimo é: " );
        Serial.println(minimum);

        Serial.print("O valor maximo é: ");
        Serial.println(maximum);

        Serial.print("A média aritmética é: ");
        Serial.println(media);

        Serial.print("O valor minimo da Humidade é: " );
        Serial.println(minimum1);

        Serial.print("O valor maximo da Humidade é: ");
        Serial.println(maximum1);

        Serial.print("A média aritmética da Humidade é: ");
        Serial.println(media1);
        Serial.println();
        break;
      }

    case 2:

      if (b == 1) {
        monitorlps(c);
        Serial.print("O valor minimo é: " );
        Serial.println(minimum2);

        Serial.print("O valor maximo é: ");
        Serial.println(maximum2);

        Serial.print("A média aritmética é: ");
        Serial.println(media2);

        Serial.print("O valor minimo da Humidade é: " );
        Serial.println(minimum3);

        Serial.print("O valor maximo da Humidade é: ");
        Serial.println(maximum3);

        Serial.print("A média aritmética da Humidade é: ");
        Serial.println(media3);
        Serial.println();
        break;
      }

      if (b == 2) {
        while (i < c) {
          monitorlps(c);
          i++;
          delay(1000);
          
        
        
        }
        Serial.print("O valor minimo é: " );
        Serial.println(minimum2);

        Serial.print("O valor maximo é: ");
        Serial.println(maximum2);

        Serial.print("A média aritmética é: ");
        Serial.println(media2);

        Serial.print("O valor minimo da Humidade é: " );
        Serial.println(minimum3);

        Serial.print("O valor maximo da Humidade é: ");
        Serial.println(maximum3);

        Serial.print("A média aritmética da Humidade é: ");
        Serial.println(media3);
        Serial.println();
      break;
      }

    case 3:

      if (b == 1) {
        acc();
        gyriscope();
        magnetic();

        Serial.println();
        Serial.println("acc");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum4);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum4);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum5);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum5);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum6);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum6);
        Serial.println();

         Serial.println();
         Serial.println("Gyriscope");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum7);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum7);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum8);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum8);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum9);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum9);
        Serial.println();

        Serial.println();
         Serial.println("Magnetic");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum10);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum10);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum11);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum11);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum12);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum12);
        Serial.println();
        break;
      }

      if (b == 2) {
        while (i < c) {
          acc();
          
          gyriscope();
          magnetic();
          i++;
          delay(1000);
        }
        Serial.println();
        Serial.println("acc");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum4);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum4);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum5);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum5);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum6);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum6);
        Serial.println();

         Serial.println();
         Serial.println("Gyriscope");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum7);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum7);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum8);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum8);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum9);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum9);
        Serial.println();

        Serial.println();
         Serial.println("Magnetic");
        Serial.print("O valor minimo de x é: " );
        Serial.println(minimum10);
        Serial.print("O valor máximo de x é: " );
        Serial.println(maximum10);
        Serial.println();
        Serial.print("O valor minimo de y é: " );
        Serial.println(minimum11);
        Serial.print("O valor máximo de y é: " );
        Serial.println(maximum11);
        Serial.println();
        Serial.print("O valor minimo de z é: " );
        Serial.println(minimum12);
        Serial.print("O valor máximo de z é: " );
        Serial.println(maximum12);
        Serial.println();


        
        break;
      }

    case 4:
      Serial.println("Quitting program!\n");

      exit(0);
  }
}
