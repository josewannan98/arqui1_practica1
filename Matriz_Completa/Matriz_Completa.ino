#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

#include "LedControlMS.h"
#include "string.h"
#include "stdlib.h"
#include <FrequencyTimer2.h>

#define LETRA_G { \
    {0,1,1,1,1,1},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,1,1,1},\
    {1,0,0,0,0,1},\
    {1,0,0,0,0,1},\
    {0,1,1,1,1,0}\
}
#define LETRA_G_I { \
    {0,1,1,1,1,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {1,1,1,0,0,0},\
    {1,0,0,0,0,1},\
    {1,0,0,0,0,1},\
    {0,1,1,1,1,0}\
}
#define NUMERO_SIETE { \
    {1,1,1,1,1,1},\
    {0,0,0,0,1,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,1,0,0,0,0}\
}

#define NUMERO_SIETE_I { \
    {1,1,1,1,1,1},\
    {0,1,0,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,0,1,0}\
}

#define GUION { \
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {1,1,1,1,1,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0}\
  }
  
#define GUION_I { \
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,1,1,1,1,1},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0}\
  }

#define LETRA_S { \
    {0,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,0,0},\
    {0,1,1,1,0,0},\
    {0,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {0,1,1,1,0,0}\
  }
#define LETRA_S_I {\
    {0,0,1,1,1,0},\
    {0,1,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,1,1,1,0},\
    {0,1,0,0,0,0},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,0}\
  }

#define LETRA_E { \
    {1,1,1,1,1,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,1,1,1,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,1,1,1,1,0}\
  }
 #define LETRA_E_I{ \
    {0,1,1,1,1,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,1,1,1,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,1,1,1,1,1}\
  }

#define LETRA_C { \
    {0,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,1,0},\
    {0,1,1,1,0,0}\
  }
  
 #define LETRA_C_I{ \
    {0,0,1,1,1,0},\
    {0,1,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,0}\
  }

#define LETRA_I { \
    {1,1,1,1,1,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {1,1,1,1,1,0}\
  }
 #define LETRA_I_I{ \
    {0,1,1,1,1,1},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,1,1,1,1,1}\
  }


 #define LETRA_O { \
    {0,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {0,1,1,1,0,0}\
  }

 #define LETRA_O_I{\
    {0,0,1,1,1,0},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,0}\
  }
  
#define LETRA_N { \
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,1,0,0,1,0},\
    {1,0,1,0,1,0},\
    {1,0,0,1,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0}\
}
  
#define LETRA_N_I{\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,1,1},\
    {0,1,0,1,0,1},\
    {0,1,1,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1}\
  }

  
#define SPACE { \
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0},\
    {0,0,0,0,0,0}\
  }
#define LETRA_A { \
    {0,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,1,1,1,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0}\
  }
  
#define LETRA_A_I { \
    {0,0,1,1,1,0},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,1,1,1,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1}\
  }

#define LETRA_P { \
    {1,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,1,1,1,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0}\
  }
#define LETRA_P_I { \
    {0,0,1,1,1,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1}\
  }


#define LETRA_R { \
    {1,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,1,1,1,0,0},\
    {1,0,1,0,0,0},\
    {1,0,0,1,0,0},\
    {1,0,0,0,1,0}\
  }
#define LETRA_R_I { \
    {0,0,1,1,1,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,1},\
    {0,0,0,1,0,1},\
    {0,0,1,0,0,1},\
    {0,1,0,0,0,1}\
  }

#define LETRA_C { \
    {0,1,1,1,0,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,0,0},\
    {1,0,0,0,1,0},\
    {0,1,1,1,0,0}\
  }
#define LETRA_C_I { \
    {0,0,1,1,1,0},\
    {0,1,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,0,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,0}\
  }
  
#define LETRA_T { \
    {1,1,1,1,1,0},\
    {1,0,1,0,1,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0}\
  }

#define LETRA_T_I{ \
    {0,1,1,1,1,1},\
    {0,1,0,1,0,1},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0}\
  }

#define LETRA_I { \
    {1,1,1,1,1,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {0,0,1,0,0,0},\
    {1,1,1,1,1,0}\
  }
#define LETRA_I_I { \
    {0,1,1,1,1,1},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,0,0,1,0,0},\
    {0,1,1,1,1,1}\
  }
  

#define NUMERO_UNO { \
    {0,0,1,1,0,0},\
    {0,1,1,1,0,0},\
    {1,1,1,1,0,0},\
    {0,0,1,1,0,0},\
    {0,0,1,1,0,0},\
    {0,0,1,1,0,0},\
    {1,1,1,1,1,0}\
  }
  
#define NUMERO_UNO_I { \
    {0,0,1,1,0,0},\
    {0,1,1,1,0,0},\
    {1,1,1,1,0,0},\
    {0,0,1,1,0,0},\
    {0,0,1,1,0,0},\
    {0,0,1,1,0,0},\
    {1,1,1,1,1,0}\
  }

#define ASTERISCO { \
    {0,0,1,0,0,0},\
    {1,0,1,0,1,0},\
    {0,1,1,1,0,0},\
    {1,1,1,1,1,0},\
    {0,1,1,1,0,0},\
    {1,0,1,0,1,0},\
    {0,0,1,0,0,0}\
  }

  #define ASTERISCO_I { \
    {0,0,0,1,0,0},\
    {0,1,0,1,0,1},\
    {0,0,1,1,1,0},\
    {0,1,1,1,1,1},\
    {0,0,1,1,1,0},\
    {0,1,0,1,0,1},\
    {0,0,0,1,0,0}\
  }

  #define LETRA_U { \
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {1,0,0,0,1,0},\
    {0,1,1,1,0,0}\
  }
#define LETRA_U_I { \
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,1,0,0,0,1},\
    {0,0,1,1,1,0}\
  }
byte col = 0;
byte MLeds [8][8];
//pines de la matriz sin drive conectados al arduino 
int pins[17] = { -1, 34, 36, 23, 24, 37, 26, 35, 32, 30, 25, 27, 33, 22, 31, 28, 29};

//conjunto de pines conectado como columnas 
int cols[8] = {pins[13], pins[3], pins[4], pins[10], pins[06], pins[11], pins[15], pins[16]};

// conjunto de pines conectados como filas
int rows[8] = {pins[9], pins[14], pins[8], pins[12], pins[1], pins[7], pins[2], pins[5]};

const int numPatterns = 24;
int aux = 0;

//MENSAJE A MOSTRAR
byte patterns[numPatterns][7][6]={
  SPACE, ASTERISCO, LETRA_G, NUMERO_SIETE, GUION, LETRA_S, LETRA_E, LETRA_C, LETRA_C, LETRA_I, LETRA_O, LETRA_N, LETRA_A, GUION, LETRA_P, LETRA_R, LETRA_A, LETRA_C, LETRA_T, LETRA_I, LETRA_C, LETRA_A, NUMERO_UNO, ASTERISCO          
      };
//SPACE, LETRA_G, NUMERO_SIETE, GUION, LETRA_S, LETRA_E, LETRA_C, LETRA_C, LETRA_I, LETRA_O, LETRA_N, LETRA_A, GUION, LETRA_P, LETRA_R, LETRA_A, LETRA_C, LETRA_T, LETRA_I, LETRA_C, LETRA_A, NUMERO_UNO, SPACE      
//SPACE, ASTERISCO, LETRA_T, LETRA_P, LETRA_T, GUION, LETRA_G, LETRA_R, LETRA_U, LETRA_P, LETRA_O, NUMERO_SIETE, GUION, LETRA_S, LETRA_E, LETRA_C, LETRA_C, LETRA_I, LETRA_O, LETRA_N, LETRA_A, ASTERISCO

byte patternsE[numPatterns][7][6]={
  SPACE, ASTERISCO_I, NUMERO_UNO_I, LETRA_A_I, LETRA_C_I, LETRA_I_I, LETRA_T_I, LETRA_C_I, LETRA_A_I, LETRA_R_I, LETRA_P_I, GUION_I, LETRA_A_I, LETRA_N_I, LETRA_O_I, LETRA_I_I, LETRA_C_I, LETRA_C_I, LETRA_E_I, LETRA_S_I, GUION_I, NUMERO_SIETE_I, LETRA_G_I, ASTERISCO_I
  };
//SPACE, NUMERO_UNO_I, LETRA_A_I, LETRA_C_I, LETRA_I_I, LETRA_T_I, LETRA_C_I, LETRA_A_I, LETRA_R_I, LETRA_P_I, GUION_I, LETRA_A_I, LETRA_N_I, LETRA_O_I, LETRA_I_I, LETRA_C_I, LETRA_C_I, LETRA_E_I, LETRA_S_I, GUION_I, NUMERO_SIETE_I, LETRA_G_I, SPACE
// SPACE, ASTERISCO_I, LETRA_A_I , LETRA_N_I, LETRA_O_I, LETRA_T_I, LETRA_C_I, LETRA_C_I, LETRA_E_I, LETRA_S_I, GUION_I, NUMERO_SIETE_I, LETRA_O_I, LETRA_P_I, LETRA_U_I, LETRA_R_I, LETRA_G_I, GUION_I, LETRA_T_I, LETRA_P_I, LETRA_T_I, ASTERISCO_I
int pattern = 0;
int l;
// MATRIZ CON DRIVE
#include <MD_Parola.h>
//   https://github.com/MajicDesigns/MD_Parola
#include <MD_MAX72xx.h>
//   https://github.com/MajicDesigns/MD_MAX72xx
#include <SPI.h>

#define MAX_DEVICES 1 // Number of modules connected
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN   45
//
#if INCLUDE_HARDWARE_SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
#else
MD_Parola P = MD_Parola(HARDWARE_TYPE, 52, 51, CS_PIN, MAX_DEVICES); //CS_PIN 45
#endif // USE_HARDWARE_SPI
#define slider_pin A0  // PIN DONDE VA CONECTADO EL POTENCIOMETRO
int slider_val;  // POTENCIOMETRO
int slide_scroll_speed;   //VELOCIADA DEL POTENCIOMETRO
int scrollSpeed;    // VELOCIDAD A LA QUE ENTRA 
 
textEffect_t scrollEffect = PA_SCROLL_DOWN;// DIRECCION A LA QUE INICIA EL TEXTO
textPosition_t scrollAlign = PA_CENTER;  // DIRECCION PARA DONDE VA EL TEXTO
int scrollPause = 0; // TIEMPO DE ESPERA DESPUES QUE TERMINA EL TEXTO

#define  BUF_SIZE  25  // MAXIMO DE CARACTERES
char curMessage[BUF_SIZE] = { "G7-SECCIONA-PT1" };  // En lo que cambia de estado
//char curMessage[BUF_SIZE] = { "R" };  // En lo que cambia de estado
//char curMessage[BUF_SIZE] = { "U" };  // En lo que cambia de estado
//char curMessage[BUF_SIZE] = { "P" };  // En lo que cambia de estado
//char curMessage[BUF_SIZE] = { "O" };  // En lo que cambia de estado
//char curMessage[BUF_SIZE] = { "VII" };  // En lo que cambia de estado


//BOTONES
int pulsador = 4, up_right = 7, up_left = 13, down_right = 2, down_left = 8;

byte posicion[8];

//---------------------matriz sin drive
typedef struct Matriz {
  int fila;
  int columna;
  int pinfila;
  int pincolumna;
  boolean estado;
} m;

m matriz[8][8];

int pines[] = {30, 31, 32, 33, 34, 35, 36, 37, 22, 23, 24, 25, 26, 27, 28, 29};

bool posMatriz = false, pausado = false;

int contadorInicio = 0;
int contadorBug = 0;
int estado = 1, matriz_der = 0, fila = 7, columna = 6, direccion = 45, x = 0, y = 0, j1 = 0; //control
unsigned long tiempo, fin;

LedControl lc = LedControl(52, 51, 45, 2); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales
//================================VARIABLES JUEGO======================================

byte pausa[] {B00000000, B00000000, B00000000, B00011000, B00011000, B00000000, B00000000, B00000000};

byte play[] = {B00110000, B00101000, B00100100, B00100010, B00100010, B00100100, B00101000, B00110000};

byte BarreraDerecha[] = {B00000000, B00000000, B00000001, B00000001, B00000001, B00000001, B00000000, B00000000};
// delay time between faces
unsigned long delaytime = 750;
float timeCount = 0;

// Numeritos
/*byte N1[8] = {B00011000,B01111000,B00011000,B00011000,B00011000,B00011000,B01111110,B00000000};
  byte N2[8] = {B00111100,B01000110,B00000110,B00011000,B00110000,B01100000,B01111110,B00000000};
  byte N3[8] = {B00111100,B01000010,B00000010,B00011100,B00000010,B01000010,B00111100,B00000000};
  byte N4[8] = {B00000100,B00001100,B00010100,B00100100,B01111110,B00000100,B00000100,B00000000};
  byte N0[8] = {B00111100,B01000010,B01000010,B01000010,B01000010,B01000010,B00111100,B00000000};*/

byte N1[8] = {B00000000, B01111110, B00011000, B00011000, B00011000, B00011110, B00011000, B00000000};
byte N2[8] = {B00000000, B00111110, B00000010, B00001100, B00010000, B00100010, B00011100, B00000000};
byte N3[8] = {B00000000, B00011100, B00100000, B00100000, B00011000, B00100000, B00111100, B00000000};
byte N4[8] = {B00000000, B00100000, B00100000, B00111110, B00100010, B00100100, B00101000, B00000000};
byte N0[8] = {B00111100, B01000010, B01000010, B01000010, B01000010, B01000010, B00111100, B00000000};
int flag =0;
//-------------
//------------------------------------
void setup() {
  Serial.begin(9600);
  pattern = 0;
  pinMode(pulsador, INPUT); //BOTON PAUSA
  pinMode(up_right, INPUT); //BOTON DE DERECHA
  pinMode(down_right, INPUT); //BOTON DE ABAJO
  int address = 0;
  lc.shutdown(address, false);
  lc.setIntensity(address, 8);
  lc.clearDisplay(address);

  int i, j, contador = 22;
  for (i = 0; i < 8; i++) {
    for (j = 0; j < 8; j++) {
      matriz[i][j].fila = i;
      matriz[i][j].columna = j;
      matriz[i][j].pinfila = pines[15 - i];
      matriz[i][j].pincolumna = pines[j];
      matriz[i][j].estado = false;
    }
  }

  for (i = 0; i < 16; i++) {
    pinMode(contador, OUTPUT);
    contador ++;
  }
  IniciarMatriz();
   pinMode(slider_pin, INPUT);

  P.begin();  // INICIO DE TEXTO

  // configure Parola
  P.displayText(curMessage, scrollAlign, scrollSpeed, scrollPause, scrollEffect, scrollEffect);
  // Configuramos los pinso como salida
  for (int i = 1; i <= 16; i++) {
    pinMode(pins[i], OUTPUT);
  }

  // inicializamos filas y columnas
  for (int i = 1; i <= 8; i++) {
    digitalWrite(cols[i - 1], LOW);
  }

  for (int i = 1; i <= 8; i++) {
    digitalWrite(rows[i - 1], LOW);
  }

  clearLeds();

  // Apagamos la conmutación del pin 11
  FrequencyTimer2::disable();
  // ratio de refresco en microsegundos
  FrequencyTimer2::setPeriod(2000);
  // Función de desbordamiento, se llama cada ciclo.
  FrequencyTimer2::setOnOverflow(display);

  setPattern(pattern);

}

void loop() {
  // put your main code here, to run repeatedly:
  //------------BOTON PAUSA
    if (digitalRead(pulsador) && estado == 1) {
    tiempo = fin = millis();
    while ( digitalRead(pulsador) && fin - tiempo <= 3000 ) {
      lc.clearDisplay(0);
      Representar(matriz_der, pausa, 5);
      fin = millis();
    }

    if (fin - tiempo >= 3000) {
      clearLeds();
      Serial.println("Tiempo" + (fin - tiempo) / 1000);
      estado = 2;
    }
    lc.clearDisplay(0);
    }
    //--------------------- PAUSA EN EL JUEGO
 else if (digitalRead(pulsador) == HIGH && estado == 2) {
    if (pausado == true) {
      pausado = false;
    }
    else {
      pausado = true;
    }
  }
  else if (pausado == true) {
    lc.clearDisplay(matriz_der);
    Marcador(j1);
  }

  //----------------------------JUEGO

  //else {
  //INICIA EL TEXTO

  if (flag == 0) {
      if (contadorInicio <= 2) {
        // slidePattern(pattern, 100);
        if (flag == 0) {
          slider_val = analogRead(A0);  // check slider analog value

          if (slider_val <= 10) {
            if (flag == 0) {
            } else {
              flag = 0;
              contadorInicio = 139 - contadorInicio;
              Serial.println("Cambio izquierda -> derecha");
              Serial.println(contadorInicio);
            }
          }
          if (slider_val >= 1022) {
            if (flag == 1) {
            } else {
              flag = 1;
              contadorInicio = 135 - contadorInicio;
              Serial.println("Cambio derecha -> izquierda");
              Serial.println(contadorInicio);
            }
          }

          if (flag == 0) {
            scrollEffect = PA_SCROLL_UP;
            P.setTextEffect(scrollEffect, scrollEffect);
            slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
            P.setSpeed(400 - slide_scroll_speed);
            delay(400 - slide_scroll_speed);
          }
          if (flag == 1) {
            scrollEffect = PA_SCROLL_DOWN;
            P.setTextEffect(scrollEffect, scrollEffect);
            slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
            P.setSpeed(slide_scroll_speed);
            //delay(slide_scroll_speed);
          }
          if (P.displayAnimate()) // If finished displaying message
          {
            P.displayReset();  // Reset and display it again
          }
          contadorInicio = contadorInicio + 1;
        }
      } else {
        if (flag == 0) {
          if (l == 6) {
            l = 0;
            pattern = ++pattern % numPatterns;
          }

          // slidePattern(pattern, 100);

          slider_val = analogRead(A0);  // check slider analog value

          if (slider_val <= 10) {
            if (flag == 0) {
            } else {
              flag = 0;
              contadorInicio = 139 - contadorInicio;
              Serial.println("Cambio izquierda -> derecha");
              Serial.println(contadorInicio);
            }
          }
          if (slider_val >= 1022) {
            if (flag == 1) {
            } else {
              flag = 1;
              contadorInicio = 135 - contadorInicio;
              Serial.println("Cambio derecha -> izquierda");
              Serial.println(contadorInicio);
            }
          }

          if (flag == 0) {
            scrollEffect = PA_SCROLL_UP;
            P.setTextEffect(scrollEffect, scrollEffect);
            slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
            P.setSpeed(400 - slide_scroll_speed);
            if (contadorInicio >= 2) {
              for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 8; j++) {
                  MLeds[j][i] = MLeds[j][i + 1];
                }
              }
              for (int j = 0; j < 7; j++) {
                MLeds[j][7] = patternsE[pattern][j][l];
              }
              delay(400 - slide_scroll_speed);
            }
          }
          if (flag == 1) {
            scrollEffect = PA_SCROLL_DOWN;
            P.setTextEffect(scrollEffect, scrollEffect);
            slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
            P.setSpeed(slide_scroll_speed);
            for (int i = 0; i < 7; i++) {
              for (int j = 0; j < 8; j++) {
                MLeds[j][i] = MLeds[j][i + 1];
              }
            }
            for (int j = 0; j < 7; j++) {
              MLeds[j][7] = patterns[pattern][j][l];
            }
            delay(slide_scroll_speed);
          }
          if (P.displayAnimate()) // If finished displaying message
          {

            if (contadorBug == 0) {
              if (contadorInicio == 141) {
                contadorInicio = -7;
                contadorBug = 1;
                l = - 1;
                clearLeds();
                P.displayReset();
              }
            } else {
              if (contadorInicio == 135) {
                contadorInicio = -7;
                l = - 1;
                clearLeds();
                P.displayReset();
              }
            }


          }
          l = l + 1;
          contadorInicio = contadorInicio + 1;
        }
      }
    } if (flag == 1) {

      if (contadorInicio <= 11) {


        if (flag == 1) {
          if (l == 6) {
            l = 0;
            pattern = ++pattern % numPatterns;
          }

          // slidePattern(pattern, 100);

          slider_val = analogRead(A0);  // check slider analog value

          if (slider_val <= 10) {
            if (flag == 0) {
            } else {
              flag = 0;
              contadorInicio = 139 - contadorInicio;
              Serial.println("Cambio izquierda -> derecha");
              Serial.println(contadorInicio);
            }
          }
          if (slider_val >= 1022) {
            if (flag == 1) {
            } else {
              flag = 1;
              contadorInicio = 135 - contadorInicio;
              Serial.println("Cambio derecha -> izquierda");
              Serial.println(contadorInicio);
            }
          }

          slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
          for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 8; j++) {
              MLeds[j][i] = MLeds[j][i + 1];
            }
          }
          for (int j = 0; j < 7; j++) {
            MLeds[j][7] = patterns[pattern][j][l];
          }
          delay(slide_scroll_speed);


          l = l + 1;
          contadorInicio = contadorInicio + 1;
        }
      } else {

        if (contadorInicio <= 137) {
          if (l == 6) {
            l = 0;
            pattern = ++pattern % numPatterns;
          }

          // slidePattern(pattern, 100);

          slider_val = analogRead(A0);  // check slider analog value

          if (slider_val <= 10) {
            if (flag == 0) {
            } else {
              flag = 0;
              contadorInicio = 139 - contadorInicio;
              Serial.println("Cambio izquierda -> derecha");
              Serial.println(contadorInicio);

            }
          }
          if (slider_val >= 1022) {
            if (flag == 1) {
            } else {
              flag = 1;
              contadorInicio = 135 - contadorInicio;
              Serial.println("Cambio derecha -> izquierda");
              Serial.println(contadorInicio);
            }
          }


          if (flag == 1) {
            scrollEffect = PA_SCROLL_DOWN;
            P.setTextEffect(scrollEffect, scrollEffect);
            slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
            P.setSpeed(slide_scroll_speed);
            if (contadorInicio < 138) {
              for (int i = 0; i < 7; i++) {
                for (int j = 0; j < 8; j++) {
                  MLeds[j][i] = MLeds[j][i + 1];
                }
              }
              for (int j = 0; j < 7; j++) {
                MLeds[j][7] = patterns[pattern][j][l];
              }
              delay(slide_scroll_speed);
            } else {

            }
          }

          if (P.displayAnimate()) // If finished displaying message
          {

          }

          l = l + 1;
          contadorInicio = contadorInicio + 1;
        } else {
          clearLeds();
          scrollEffect = PA_SCROLL_DOWN;
          P.setTextEffect(scrollEffect, scrollEffect);
          slide_scroll_speed = map(slider_val, 1023, 0, 400, 15);
          P.setSpeed(slide_scroll_speed);

          if (P.displayAnimate()) // If finished displaying message
          {
                      
            P.displayReset();
            l = -1;
            contadorInicio = -1;
          }
        }


      }
    }
}
  //----------------APAGA TODO
void LowTodo() {
  for (int i = 22; i <= 37; i++)
  {
    digitalWrite(i, LOW);
  }
}
void clearLeds() {
  // Limpia el array
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      MLeds[i][j] = 0;
    }
  }
}
void IniciarMatriz() {
  int i, j;
  posicion[0] = posicion[1] = posicion[6] = posicion[7] = false;
  posicion[2] = posicion[3] = posicion[4] = posicion[5] = true;
  for (i = 2; i < 6; i++) {
    matriz[i][0].estado = true;
  }

  for (i = 1; i < 8; i++) {
    digitalWrite(matriz[0][i].pincolumna, HIGH);
  }
}

//---------------------RECINICA EL JUEGO
void Reiniciar() {
  fila = 3;
  columna = 7;
  x = 0;
  y = 5;
  posMatriz = false;
  direccion = 45;
  estado = 1;
  j1 = 0;
}
//---------------- MARCADOR 

void Marcador(int GI) {
  if (GI == 1)
  {
    //Dibujar1();
  }
  else if (GI == 2)
  {
    //Dibujar2();
  }
  else if (GI == 3)
  {
    //Dibujar3();
  }
  else if (GI == 4)
  {
    //Dibujar4();
  }
  /*
  else if (GI == 0)
  {
    Dibujar0();
  }

  if (GD == 1)
  {
    Representar(matriz_der, N1, 5);
  }
  else if (GD == 2)
  {
    Representar(matriz_der, N2, 5);
  }
  else if (GD == 3)
  {
    Representar(matriz_der, N3, 5);
  }
  else if (GD == 4)
  {
    Representar(matriz_der, N4, 5);
  }
  else if (GD == 0)
  {
    Representar(matriz_der, N0, 5);
  }
*/
}
//-----------------REPRESENTAR
void Representar(int matriz, byte *Datos, int retardo) { //Funcion para la representacion de bytes de datos para una matriz de 8x8
  for (int i = 0; i < 8; i++) {
    lc.setColumn(matriz, i, Datos[7 - i]);
  }
  delay(retardo);
}
//----------------DISPLAY

void display() {
  digitalWrite(cols[col], LOW);  // Apagamos la columna previa
  col++;
  if (col == 8) {
    col = 0;
  }
  for (int row = 0; row < 8; row++) {
    if (flag == 0) {
      if (MLeds[col][row] == 1) {//row izq->der // 7-row der->izq
        digitalWrite(rows[row], LOW);  // Apagamos este led
      }
      else {
        digitalWrite(rows[row], HIGH); // Apagamos este led
      }
    }
    if (flag == 1) {
      if (MLeds[col][7 - row] == 1) { //row izq->der // 7-row der->izq
        digitalWrite(rows[row], LOW);  // Apagamos este led
      }
      else {
        digitalWrite(rows[row], HIGH); // Apagamos este led
      }
    }
  }
  digitalWrite(cols[col], HIGH); // Encendemos toda la columna
}


void setPattern(int pattern) {
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 6; j++) {
      MLeds[i][j] = patternsE[pattern][i][j];
    }
  }
}
