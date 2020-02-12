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
byte Columna = 0;
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
#include <MD_MAX72xx.h>
#include <SPI.h>
#define MAX_DEVICES 1 // Number of modules connected NUMERO DE MATRIZ 
#define HARDWARE_TYPE MD_MAX72XX::GENERIC_HW
#define MAX_DEVICES 1
#define CS_PIN   45 // NUMERO DE PIN DE LOAD
#if INCLUDE_HARDWARE_SPI
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
#else
MD_Parola P = MD_Parola(HARDWARE_TYPE, 52, 51, CS_PIN, MAX_DEVICES); //DIN 52, CLK 51, CS_PIN 45
#endif // USE_HARDWARE_SPI

#define slider_pin A0  // PIN DONDE VA CONECTADO EL POTENCIOMETRO
int slider_val;  // POTENCIOMETRO
int slide_scroll_speed;   //VELOCIADA DEL POTENCIOMETRO
int scrollSpeed;    // VELOCIDAD A LA QUE ENTRA 
 
textEffect_t scrollEffect = PA_SCROLL_LEFT;// DIRECCION A LA QUE INICIA EL TEXTO
textPosition_t scrollAlign = PA_LEFT;  // DIRECCION PARA DONDE VA EL TEXTO
int scrollPause = 0; // TIEMPO DE ESPERA DESPUES QUE TERMINA EL TEXTO

#define  BUF_SIZE  75  // MAXIMO DE CARACTERES
char curMessage[BUF_SIZE] = { "PRACTICA1-GRUPO7-SECCTONA" };  // En lo que cambia de estado


//BOTONES
int pulsador = 4, up_right = 7, up_left = 13, down_right = 2, down_left = 8;

byte posicion[8];

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
