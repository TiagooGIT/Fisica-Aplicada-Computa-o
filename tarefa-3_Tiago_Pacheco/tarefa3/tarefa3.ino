#define TYPE double
#define Funcao_recursiva
//Variaveis Globais
TYPE factorial_for, factorial_while, factorial_rec, average_time, t;
char strBuffer[35];
int n;
int nMax = 171;
int repetitions = 20;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while(!Serial);
  Serial.println("FAC - 2021/2022 - 20296");
  Serial.println("Factorial: Version WHILE & DOUBLE");
  Serial.print("Nmax --> ");
  Serial.print(nMax);
  Serial.print("  Repetitions --> ");
  Serial.println(repetitions);
  Serial.println("n     n!     t_exec(us)\n");
  
}

void loop() {
  unsigned long average_time;
  TYPE factorial_all;

  for (int a = 0; a <= nMax; a++){
    average_time = 0;

    for (int n = 0; n <= repetitions; n++){
      
      unsigned long t = micros();
      factorial_all = fact_rec(a);
      t = micros() - t;
      average_time = average_time + t;     
      }
    average_time = average_time / repetitions;
    sprintf(strBuffer, "%i %.6e %i",a , factorial_all, average_time);
    Serial.println(strBuffer);
    }
    while(true);
}

// ## WHILE ##
#ifdef Funcao_while

TYPE fact_while(int n)

{
  TYPE fact = 1;
  int x = 1;
  while (x <= n){
    
    fact = fact * x;
    x++;
        }
  return fact;
  }
#endif

// ## FOR ##
#ifdef Funcao_for

TYPE fact_for (int n){
  
  TYPE fact = 1;

  for (int x = 1 ; x <= n ; x++)
  {   
    fact = fact * x;
 }
return fact;      
}
#endif

// ## RECURSIVO ##
#ifdef Funcao_recursiva

TYPE fact_rec(int n)
{
 
  TYPE fact = 1;

   n > 1 ? fact = n * fact_rec( n -1): fact = 1;
   
   
  return fact;
 
}
#endif
