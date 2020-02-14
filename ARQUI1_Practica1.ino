#include <LedControlMS.h>
 
 
LedControl lc=LedControl(12,11,10,1); // Los numeros se refieren a que pin de ARDUINO tienes en cada uno de los terminales

int matriz[8][16];
int matriz1[8][15];
int punteo;
int pausa;
int fin;
int contador;
int max_enemies = 3;
int enemies_appear = 0;
int num_aleatorio = 0;
int cont =0;

/* 12 para el DIN, 11 para el CLK, 10 para el CS y el 1 se refiere a la asignacion de la matriz*/ 
 
 
 
void setup()
 
{
 
  // El numero que colocamos como argumento de la funcion se refiere a la direccion del decodificador
  punteo=0;
  pausa=0;
  fin = 0;
  for(int a=0;a<8;a++)
  {
    for(int b=0; b<16;b++)
    {
      matriz[a][b] = 0;
    }
  }
  //inicial posicion del jugador
  matriz[3][15] = 1;
  matriz[4][15] = 1;
  matriz[5][15] = 1;
  matriz[4][14] = 1;
  lc.shutdown(0,false);
 
  lc.setIntensity(0,8);// La valores estan entre 1 y 15 
 
  lc.clearDisplay(0);
 
}
 
void loop()
{
  num_aleatorio = random(1,3);
  delay(500);
   for (int row=0; row<8; row++)
  {
    for (int col=0; col<8; col++)
    {
      lc.setLed(0,col,row,false);
 
    }
 
  }

  //delay(1000);
 if(pausa==1)
  {
    //letras
    
  }
  else
  {
    if(fin==1)
    {
      //mostrar punteo
    }
    else
    {
      move_enemies();
      escritura();
      colision();
      if (cont >2)
      {
        send_enemies();
        cont =0;
      }
      cont++;
      
      
    }
    
  }
  
 
}
void send_enemies()
{
  if(enemies_appear< max_enemies)
  {
    
    enemies_appear += 1;
    if(enemies_appear == 0)
    {
      matriz[0][0] = 2;
      matriz[1][0] = 2;
      matriz[2][0] = 2;
      matriz[1][1] = 2;
    }
    if(enemies_appear == 1)
    {
      matriz[5][0] = 2;
      matriz[6][0] = 2;
      matriz[7][0] = 2;
      matriz[6][1] = 2;
    }
    if(enemies_appear == 2)
    {
      matriz[4][0] = 2;
      matriz[5][0] = 2;
      matriz[6][0] = 2;
      matriz[5][1] = 2;
    }
  }
}
void escritura()
{
  for(int a=0; a<8;a++)
  {
    for(int b=0; b<16;b++)
    {
      if(b>7)
      {
        if(matriz[a][b]!=0)
        {
            lc.setLed(0,(b-8),a,true); // 
            delay(25);
        }
      }
    }
  }
}
void colision()
{
  //chequeo si el vehiculo a colisionado
  for(int a=0;a<8;a++)
  {
    for(int b=0; b<16;b++)
    {
      if(matriz[a][b]==2)
      {
        if(matriz[a][b+1] == 1)fin=1;
      }
      if(fin ==1)break;
    }
    if(fin==1)break;
  }
}
void move_enemies()
{
  //movimiento, vamos a preguntar desde las columnas
  for(int a =15; a>-1;a--)
  {
    for(int b=0; b<8;b++)
    {
      if(matriz[b][a]==2)
      {
        if(a==15)
        {
          punteo += 1;
          enemies_appear -= 1;
          if(matriz[b-1][a]==2 || matriz[b+1][a]==2)
          {
            matriz[b-1][a] =0;
            matriz[b][a] =0;
            matriz[b+1][a] =0;
          }
          else
          {
            matriz[b-1][a-1] =0;
            matriz[b][a-1] =0;
            matriz[b+1][a-1] =0;
            matriz[b][a] = 0;
          }
        }
        else
        {
          matriz[b][a] = 0;
          matriz[b][a+1] = 2;
        }
        
      }
    }
  }
}
