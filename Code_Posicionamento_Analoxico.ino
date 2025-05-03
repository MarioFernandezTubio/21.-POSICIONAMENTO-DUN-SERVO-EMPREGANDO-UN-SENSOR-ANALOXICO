/*
-----POSICIONAMENTO DUN SERVO EMPREGANDO UN SENSOR ANALÓXICO.----

Realiza unha montaxe na que un servo (alimentado por 
unha batería externa) se conecte no pin PWM D03 (3~) 
como entrada de control (saída para Arduíno) e un potenciómetro 
se conecte no pin analóxico A05 como entrada do Arduíno. 

- O programa debe ser reactivo ao potenciómetro (8 veces por segundo).
- O potenciómetro controla o ángulo de xiro do servo.
- A precisión do potenciómetro é de 10º.

*****************************************************************/
/***************************************************************

Programa feito por Mario Fernández Tubío.
Última revisión: 03/05/2025

********************************************************/
#include <Servo.h>
#define pote A5


int pos = 0;
int veloz = 125;      // Reactividade (1000 ms / 8 = 125 ms)
int paso = 10;        // Precisión en pasos de 10º

Servo VIRAVIRA;

void setup(){
  
  VIRAVIRA.attach(3);
  Serial.begin(9600);

  
}

void loop(){
  
// Lemos o pote 
  pos = analogRead(pote);

    
/* Limitamos o rango de entrada para asegurarnos de que 
   map() só recibe valores no rango esperado.

        constrain(valor,min,max)*/
  pos = constrain(pos, 50, 975);
  
/* Remapear o rango para que "50 sexa 0" e "975 sexa 1023".
     "map(valor, fromLow, fromHigh, toLow, toHigh)"*/
  pos = map(pos, 50,    975,       0,     180); 
  

// Axustamos á precisión de 10 grados
  pos = (pos / paso) * paso;

  
  VIRAVIRA.write(pos);
  
  Serial.println(pos);
  
  delay(veloz);
  
}
