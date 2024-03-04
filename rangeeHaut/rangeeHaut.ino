#include <Servo.h>

Servo servosocle; // crée un servo moteur, celui du bas.

Servo servotourne; 

Servo pince;

Servo art3;

Servo art2;

Servo rail;





  int a = servosocle.read();

  int b = art2.read();

  int c = art3.read();

  int d = pince.read();

  int e = rail.read();



  int n = 90;



void setup() {

  Serial.begin(9600);

  servosocle.attach(7); // assigne le servo moteur à une sortie physique 

  servotourne.attach(2);

  pince.attach(8);

  art3.attach(5);

  art2.attach(4);

  rail.attach(12);





  servosocle.write(90);



  for(int i = 74; i >+4 ; i-=1){

    servotourne.write(i);

    delay(10);

  }

  delay(500);

  pince.write(0);

  delay(500);

  art3.write(n);

  delay(500);

  art2.write(n);

  delay(500);

  servosocle.write(n);





  delay(1000);




  for(int pos1=a; pos1 <= a+15 ; pos1+=1){

    servosocle.write(pos1);

    delay(15);

  }



  for(int pos2=b; pos2 <= b+5 ; pos2+=1){

    art2.write(pos2);

    delay(15);

  }



   for(int pos3=c; pos3 <= c+50 ; pos3+=1){ 

    art3.write(pos3);

    delay(15);

  }



  pince.write(0);

  delay(500);

  pince.write(90);

  delay(500);

  pince.write(0);

  delay(200);



    





  for(int pos3=c; pos3 >= c-31 ; pos3-=1){ 

    art3.write(pos3);

    delay(10);

  }



  for(int i=a; i<= a+33 ; i+=1) {

    servosocle.write(i);

    delay(10);

  }

  for(int i=b; i>= b-92 ; i-=1) {

    art2.write(i);

    delay(10);

  }





  for(int i=c; i>= c-80; i-=1) {

    art3.write(i);

    delay(10);

  }

  delay(1000);

  pince.write(90);

  delay(500);


  

 

  

}



void loop() {



  int a = servosocle.read();

  int b = art2.read();

  int c = art3.read();

  int d = pince.read();

  int e = rail.read();





}