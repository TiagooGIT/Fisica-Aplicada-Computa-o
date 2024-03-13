#define TYPE double

// global variables
TYPE a = 0.;
TYPE b = 1.;
TYPE delta = 1.e-6;
int Nmax = 17;

// prototypes
TYPE f( TYPE );
TYPE bissec( TYPE, TYPE, TYPE, int );

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("Tarefa 4: bissecção\nModo: Double Precision\n");
  
  Serial.print ("[a,b] = ");
  Serial.print(a,3);
  Serial.print(" ");
  Serial.println( b,3);
  
  Serial.println("\nk          Xk           |f(Xk)|\n");
  TYPE c = bissec(a, b, delta , Nmax);
  
}

void loop() {
  TYPE bissec(TYPE a, TYPE b, TYPE delta, int Nmax);
}

TYPE f( TYPE x ) {
  return exp(x)-(TYPE)3.*x;
}

TYPE bissec( TYPE a, TYPE b, TYPE delta, int Nmax ) {
  if ( f(a) * f(b) > 0 ) {
    Serial.print("O intervalo não é válido!");
    return 999;
  } else {
    int cnt = 1;
    TYPE c;
    TYPE fc = 1.;
    while ( (cnt <= Nmax ) && abs(f(c)) > delta)  {
      c = (a+b)/(TYPE)2.;
      fc = f(c);
      if ( f(a) * fc < 0. ) {
        b = c;     
      } else {
        a = c;
      }
      Serial.print(cnt);
      Serial.print("\t");
      Serial.print(c, 12);
      Serial.print("\t"),
      Serial.println(abs(f(c)), 12);
      cnt++;
    }
    return c;
  }
}
