int led1 = 7;
int led2 = 6;
int led3 = 5;
int led4 = 4;
int led5 = 2;
int boton = 3;
//#define led5 3
//#define boton 2
int val;
void setup() {
  pinMode (led1,OUTPUT);
  pinMode (led2,OUTPUT);
  pinMode (led3,OUTPUT);
  pinMode (led4,OUTPUT);
  pinMode (led5,OUTPUT);
  pinMode (boton,INPUT);
}

void loop() {
  digitalWrite(led5, digitalRead(boton));
  val = analogRead(A1);
  if(val>=0&&val<255){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  if(val>=255&&val<511){
    digitalWrite(led1,LOW);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  if(val>=511&&val<767){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  if(val>=767&&val<1023){
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,HIGH);
  }
  
}
