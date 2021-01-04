int aM = 5;      
int e1 = 3;   
int e2 = 4;   
int pot = A0;  

int valorP;
double Volt;
double rpm=0;


void setup() {
  Serial.begin(9600);

  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(A0, INPUT);
   
}
// 	Si se quiere cambiar entre un ejercicio y otro, comentar la sección que se desea ignorar.

void loop() {

  valorP = analogRead(A0);  
  Serial.println(valorP);
  
  
  /*
  //-----------Incremento de Velocidad------------
  rpm=map(valorP,0,1023,0,255);
   digitalWrite(e1,HIGH);
    digitalWrite(e2,LOW);
  analogWrite(aM,rpm);
  
  //----------------------------------------------
  */

 
  //----------------Cambio de sentido---------------------------
  if(valorP<511){
    digitalWrite(e1,HIGH);
    digitalWrite(e2,LOW);
    rpm=map(valorP,0,511,25.5,0);
     Serial.println(rpm);
    analogWrite(aM,rpm);
  }
  if(valorP==511){
    digitalWrite(e1,LOW);
    digitalWrite(e2,LOW);
  }
  if(valorP>511){
    digitalWrite(e1,LOW);
    digitalWrite(e2,HIGH);
    rpm=map(valorP,511,1023,0,25.5);
     Serial.println(rpm);
    analogWrite(aM,rpm);
  }
//-----------------------------------------------
  
  
  
  

}