
int matriz[8][16];
int matriz1[8][15];
int punteo;
int pausa;
/*
 * 
 * Se inicia con la posicion inicial del carro, en la matriz, luego se parsearan y crearan vehiculos aleatorios
 * y por cada iteracion avanzaran una posicion es decir se realizara un movimiento cada 5seg, mientras que la velocidad
 * del carrito sera normal
 * 
 *  el carrito se distingira por el valor 1
 *  los enemigos por el valor 2;
 *  
 *  para controlar las colisiones, se pretende validar una posicion anterior al enemigo
 *  y de esa manera generar colisiones
 *  
 *  
 *  si esta en pausa = 1; se envia señal de no continuar con el juego
 *  
 *  
 *  En matriz1 se va a escribir la posicion de las letras
 *  
 *  
 *  sendData() ----> metodo para enviar 1 a los leds;
 *  sendPosition() ---> posicion del jugador
 *  sendEnemies() ---> posicion del enemigo
 *    
 * 
 */

void setup() {
  // put your setup code here, to run once:

  punteo=0;
  pausa=1;
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

}

void loop() {
  // put your main code here, to run repeatedly:
  if(pausa)
  {
    //letras
    
  }
  else
  {
    move_enemies();
    colision();
    //juego
  }
  delay(1000); // delay de 1000 ms, cada segundo se actualizara

}


void colision()
{
  //chequeo si el vehiculo a colisionado
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
