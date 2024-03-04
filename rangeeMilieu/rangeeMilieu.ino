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




for (int i=c; i<= c + 60; i+=1){

    art3.write(i);

    delay(10);

  }



  for (int i=b; i<= b + 35; i+=1){

    art2.write(i);

    delay(10);

  }



  for (int i=a; i<= a + 20; i+=1){

    servosocle.write(i);

    delay(10);

  }

  delay(1000);

  pince.write(90);

  delay(500);

  pince.write(0);

  delay(500);



  for (int i=a; i>= a - 30; i-=1){

    servosocle.write(i);

    delay(10);

  }



  delay(500);

  art3.write(n);

  delay(500);

  art2.write(n);

  delay(500);

  servosocle.write(n);



  for(int i=a; i<= a+35 ; i+=1) {

    servosocle.write(i);

    delay(10);

  }

  for(int i=b; i>= b-100 ; i-=1) {

    art2.write(i);

    delay(10);

  }





  for(int i=c; i>= c-75; i-=1) {

    art3.write(i);

    delay(10);

  }

  

  delay(1000);

  pince.write(90);

  delay(500);

  pince.write(0);

  delay(500);



void loop() {



  int a = servosocle.read();

  int b = art2.read();

  int c = art3.read();

  int d = pince.read();

  int e = rail.read();





}