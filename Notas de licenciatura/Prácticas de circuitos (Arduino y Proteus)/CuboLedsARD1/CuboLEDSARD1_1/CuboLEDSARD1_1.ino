// Cubo de leds con operaciones de suma, multiplicacion e inversa de matrices
// BUAP FCC - Amador Ortega Christian Amauri - 201927821
// Version 1.0
// ---------------------------------------------------------------------------
        // cómo funciona?
        // (sólo puede trabajar unos y ceros en las matrices, no tiene forma
        // de representar valores negativos ni mucho menos números reales)
        // al ejectutar el circuito, el código tiene ya las dos matrices 
        // cargadas y la operación a realizar (cuando el circuito se ha
        // ejecutado no hay forma de alterar estos parámetros), la forma de
        // ejecutarlo es redefiniendo estos parámetros y volverlos a cargar
        // en la tarjeta arduino.
// ---------------------------------------------------------------------------
short int A[3][3];
short int B[3][3];
short int C[3][3];
short int k;
short int j;
short int i;
int det = 0;
short int operacion;// 1 = suma, 2 = multiplicacion, 3 = matriz inversa

void setup() {
  for(short int pin=2;pin<14;pin++){
    pinMode(pin,OUTPUT);
  }

  operacion = 3; // operación

  // pin 11
  A[0][0] = 1;  A[0][1] = 1;  A[0][2] = 0;  
  A[1][0] = 1;  A[1][1] = 0;  A[1][2] = 0;  
  A[2][0] = 0;  A[2][1] = 0;  A[2][2] = 0;  

  // pin 12
  B[0][0] = 0;  B[0][1] = 0;  B[0][2] = 0;  
  B[1][0] = 0;  B[1][1] = 1;  B[1][2] = 0;  
  B[2][0] = 0;  B[2][1] = 0;  B[2][2] = 1;  

  // pin 13
  C[0][0] = 0;  C[0][1] = 0;  C[0][2] = 0;  
  C[1][0] = 0;  C[1][1] = 0;  C[1][2] = 0;  
  C[2][0] = 0;  C[2][1] = 0;  C[2][2] = 0;  

  switch(operacion){
    case 1:// suma
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          C[i][j] = A[i][j] + B[i][j];
        } 
      }
      break;
    case 2:// multiplicacion
      for(i=0;i<3;i++){
        for(j=0;j<3;j++){
          C[i][j] = 0;
          for(k=0;k<3;k++){
            C[i][j] = C[i][j] +A[i][k]*B[k][j];  
          }
        } 
      }
      break;
    case 3:// inversa
      //determinante
      det = A[0][0]*(A[1][1]*A[2][2] - A[2][1]*A[1][2]) +
            A[1][0]*(A[2][1]*A[0][2] - A[0][1]*A[2][2]) +
            A[2][0]*(A[0][1]*A[1][2] - A[1][1]*A[0][2]) ;

      if (det != 0){// hay matriz inversa
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            B[i][j] = ( A[(i+1)%3][(j+1)%3] * A[(i+2)%3][(j+2)%3] - 
                        A[(i+1)%3][(j+2)%3] * A[(i+2)%3][(j+1)%3] );
            C[j][i] = B[i][j] / det;
          } 
        }
        for(i=0;i<3;i++){
          for(j=0;j<3;j++){
            B[i][j] = 0;
          } 
        }
      }
      break;
  }
}

void loop(){
  // muestra matriz 1 (matriz A) (pin 11)
  digitalWrite(11,1); j=0; k=0;
  for(i=2;i<=10;i++){
    digitalWrite(i,A[j][k]); k++;
    if(k==3){ k=0; j++; }
    if(j==3) j=0;
  }
  delay(2000);
  for(i=2;i<=10;i++) digitalWrite(i,0);
  digitalWrite(11,0);

  // muestra matriz 2 (matriz B) (pin 12)
  digitalWrite(12,1); j=0; k=0;
  for(i=2;i<=10;i++){
    digitalWrite(i,B[j][k]); k++;
    if(k==3){ k=0; j++; }
    if(j==3) j=0;
  }
  delay(2000);
  for(i=2;i<=10;i++) digitalWrite(i,0);
  digitalWrite(12,0);

  //muestra matriz 3 (matriz C) (pin 13)
  if ((operacion == 3) && (det == 0)){// esta animación avisa que la matriz A no es inversible
      digitalWrite(13,1);
      digitalWrite(2,1);  delay(200); digitalWrite(2,0);
      digitalWrite(6,1);  delay(200); digitalWrite(6,0);
      digitalWrite(10,1); delay(200); digitalWrite(10,0);
      digitalWrite(4,1);  delay(200); digitalWrite(4,0);
      digitalWrite(6,1);  delay(200); digitalWrite(6,0);
      digitalWrite(8,1);  delay(200); digitalWrite(8,0);
      digitalWrite(13,0);
  }else{
    digitalWrite(13,1); j=0; k=0;
    for(i=2;i<=10;i++){
      digitalWrite(i,C[j][k]); k++;
      if(k==3){ k=0; j++; }
      if(j==3) j=0;
    }
    delay(2000);
    for(i=2;i<=10;i++) digitalWrite(i,0);
    digitalWrite(13,0);
  }
}
