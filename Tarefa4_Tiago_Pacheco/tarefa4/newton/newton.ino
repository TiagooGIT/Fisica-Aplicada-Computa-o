#define TYPE double



// global variables
TYPE xo = 0.;
TYPE delta = 1.e-12;
int Nmax = 15;

void setup() {
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Tarefa 4: Newton\nModo: Double Precision\n");
  Serial.println("k          Xk           |f(Xk)|\n");
  TYPE raiz = newton(xo, delta, Nmax);
}

void loop() {
 
}

TYPE newton(TYPE xo, TYPE delta, int Nmax) {
int counter = 1;
  TYPE fx = 1.;
  TYPE x=xo;
  
  while ( counter <= Nmax && abs(fx) > delta ) {

    fx = f(x);
    x = x - fx/df(x);
        
    Serial.print(counter);
    Serial.print("\t");
    Serial.print(x, 12);
    Serial.print("\t");
    Serial.println(abs(fx), 12);
    
    counter++;
  }
  return x;
}

TYPE f( TYPE x ) {
  return exp(x)-3.*x;
}

TYPE df( TYPE x ) {
  return exp(x)-3.;
}
