/* Project: Arduino dibuja árbol de Navidad y mensaje sobre Osciloscopio */
/* Author: Jordi Rodriguez & Llorenç Marin */

// Uso de potenciómetro para afinar la señal
int POT = A0;
int pot_delay = 1000;

// Conexión de osciloscopio a pines 5 y 6 de Arduino (usan el Timer0)
int X_PIN = 6;
int Y_PIN = 5;

// Definir matriz de puntos 
#define POINTS_ARBRE 19
byte X_axis_arbre [POINTS_ARBRE] = {90,90,30,90,40,90,60,90,80,100,120,110,140,110,160,110,170,110,110};
byte Y_axis_arbre [POINTS_ARBRE] = {30,60,60,100,100,140,140,170,170,190,170,170,140,140,100,100,60,60,30};

#define POINTS_BON 18
byte X_axis_bon [POINTS_BON] = {20,10,10,20,30,20,30,20,40,40,60,60,40,70,70,90,90,90};
byte Y_axis_bon [POINTS_BON] = {110,110,150,150,140,130,120,110,110,150,150,110,110,110,150,110,150,110};

#define POINTS_BON_S 28
byte X_axis_bon_s [POINTS_BON_S] = {20,10,10,20,30,20,30,20,40,40,60,60,40,70,70,90,90,90,
240,180,200,220,160,220,200,180,240,200};
byte Y_axis_bon_s [POINTS_BON_S] = {110,110,150,150,140,130,120,110,110,150,150,110,110,110,150,110,150,110,
110,130,70,130,110,90,150,90,110,110};

#define POINTS_BON_NADAL 59
byte X_axis_bon_nadal [POINTS_BON_NADAL] = {20,10,10,20,30,20,30,20,40,40,60,60,40,70,70,90,90,90,
240,180,200,220,160,220,200,180,240,200,
200,150,
130,130,130,120,120,100,100,120,100,100,80,90,90,80,70,70,80,60,60,40,40,60,40,40,30,30,30,10,10,};
byte Y_axis_bon_nadal [POINTS_BON_NADAL] = {110,110,150,150,140,130,120,110,110,150,150,110,110,110,150,110,150,110,
110,130,70,130,110,90,150,90,110,110,
10,10,
10,50,10,10,50,50,30,30,30,10,10,20,40,50,50,10,10,10,50,50,30,30,30,10,10,50,10,50,10};

int i = 0;

void setup() {
  pinMode (X_PIN, OUTPUT);
  pinMode (Y_PIN, OUTPUT);
  pinMode (POT, INPUT);

  setPWMPrescaler(5,1);
  setPWMPrescaler(6,1);
}

void loop() {
  for (i = 0; i < 500; i++)
  {
    byte contador = 0;
    pot_delay = map (analogRead (POT), 0, 1024, 10, 2000);
    for (contador = 0; contador < POINTS_ARBRE; contador++)
    {
      analogWrite (X_PIN, X_axis_arbre [contador]);
      analogWrite (Y_PIN, Y_axis_arbre [contador]);
      delayMicroseconds (pot_delay);
    }
  }

  for (i = 500; i < 700; i++)
  {
    byte contador = 0;
    pot_delay = map (analogRead (POT), 0, 1024, 10, 2000);
    for (contador = 0; contador < POINTS_BON; contador++)
    {
      analogWrite (X_PIN, X_axis_bon [contador]);
      analogWrite (Y_PIN, Y_axis_bon [contador]);
      delayMicroseconds (pot_delay);
    }
  }

  for (i = 700; i < 900; i++)
  {
    byte contador = 0;
    pot_delay = map (analogRead (POT), 0, 1024, 10, 2000);
    for (contador = 0; contador < POINTS_BON_S; contador++)
    {
      analogWrite (X_PIN, X_axis_bon_s [contador]);
      analogWrite (Y_PIN, Y_axis_bon_s [contador]);
      delayMicroseconds (pot_delay);
    }
  }

  for (i = 900; i < 1100; i++)
  {
    byte contador = 0;
    pot_delay = map (analogRead (POT), 0, 1024, 10, 2000);
    for (contador = 0; contador < POINTS_BON_NADAL; contador++)
    {
      analogWrite (X_PIN, X_axis_bon_nadal [contador]);
      analogWrite (Y_PIN, Y_axis_bon_nadal [contador]);
      delayMicroseconds (pot_delay);
    }
  }

  i=0;
  
}
