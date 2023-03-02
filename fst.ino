#include "NewPing.h"

int avantMG = 12;
int arriereMG = 13;

int vitesseMd = 3;
int vitesseMg = 11;

int avantMD = 4;
int arriereMD = 2;

int captintD = A0;
int captintG = A1;
int captExtD = A2;
int captExtG = A3;
int captcentre = A4;

int lD, lG, extD, extG, centre;

int trig_front = 8;
int echo_front = 9;
int echo_left = A5;
int trig_left = 10;
int trig_right = 5;
int echo_right = 6;

int flag = 0;
int dr = 0;
int dl = 0;
int D = 0;
int d = 0;
int n = 0;
int y1 = 0;
int y2 = 0;
int y3 = 0;
int y4 = 0;
NewPing front(trig_front, echo_front, 200);
NewPing left(trig_left, echo_left, 200);
NewPing right(trig_right, echo_right, 200);

void setup() {
  // put your setup code here, to run once:

  pinMode(4, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(6, INPUT);
  pinMode(9, INPUT);
  Serial.begin(9600);
}
void readsens () {
  lD = digitalRead(A0);
  lG = digitalRead(A1);
  extD = digitalRead(A2);
  extG = digitalRead(A3);
  centre = digitalRead(A4);

}

void reculer () {
  digitalWrite(arriereMG, HIGH);
  digitalWrite(avantMG, LOW);
  digitalWrite(avantMD, LOW);
  digitalWrite(arriereMD, HIGH);
  analogWrite(vitesseMd, 150);
  analogWrite(vitesseMg, 150);
}
void arreter () {
  reculer();
  delay(15);
  digitalWrite(arriereMG, LOW);
  digitalWrite(avantMG, LOW);
  digitalWrite(avantMD, LOW);
  digitalWrite(arriereMD, LOW);
  analogWrite(vitesseMd, 0);
  analogWrite(vitesseMg, 0);
}
void avancer () {
  digitalWrite(arriereMG, LOW);
  digitalWrite(avantMG, HIGH);
  digitalWrite(arriereMD, LOW);
  digitalWrite(avantMD, HIGH);
  analogWrite(vitesseMd, 160);
  analogWrite(vitesseMg, 150);
}

void avancerD () {
  digitalWrite(avantMG, HIGH);
  digitalWrite(arriereMG, LOW);
  digitalWrite(avantMD, HIGH);//
  digitalWrite(arriereMD, LOW);//
  analogWrite(vitesseMd, 0);
  analogWrite(vitesseMg, 150);
}
void avancerG () {
  digitalWrite(avantMG, HIGH);
  digitalWrite(arriereMG, LOW);
  digitalWrite(avantMD, HIGH);//
  digitalWrite(arriereMD, LOW);//
  analogWrite(vitesseMd, 160);
  analogWrite(vitesseMg, 0);
}
void tournergauche () {
  digitalWrite(arriereMG, HIGH);
  digitalWrite(avantMG, LOW);
  digitalWrite(arriereMD, LOW);
  digitalWrite(avantMD, HIGH);
  analogWrite(vitesseMg, 150);
  analogWrite(vitesseMd, 170);
}
void tournerdroite () {
  digitalWrite(arriereMG, LOW);
  digitalWrite(avantMG, HIGH);
  digitalWrite(arriereMD, HIGH);
  digitalWrite(avantMD, LOW);
  analogWrite(vitesseMg, 170);
  analogWrite(vitesseMd, 150);
}

void ajust() {

  if ((!extG) && (extD)) {
    while (!centre) {
      readsens();
      tournerdroite();


    }
  }

  else if ((extG) && (!extD))
  {
    do {
      avancer();
      readsens();
    }

    while ( (lD) || (lG));

    do {
      tournergauche() ;
      readsens();
    }
    while (!centre);
  }

  else if ((!lG) && (lD))
    avancerD();

  else if ((lG) && (!lD))
    avancerG();

  else if (((lD) && (lG)) || ((!lG) && (!lD)))
    avancer();
}






void loop() {
  // put your main code here, to run repeatedly:
while(flag==0){  
  readsens();
  ajust();
  //Serial.println(lD);
  //Serial.println(lG);
    if ((front.ping_cm() == 7) && (flag == 0))
    { arreter();
     delay(5000);
      flag++;
    }}

   while(flag==1){
    while(front.ping_cm() > 7){
    avancer();
    delay(200);
    }
    digitalWrite(arriereMD, LOW);
    digitalWrite(avantMD, HIGH);
    digitalWrite(arriereMG, HIGH );
    digitalWrite(avantMG, LOW );
    analogWrite(vitesseMg, 180);
    analogWrite(vitesseMd, 180);
    delay(500);
    avancer();
      delay(600);
      
    
 //maze  
    while(1){
  dl = left.ping_cm();
  dr = right.ping_cm();
  d = front.ping_cm();
  // delay(500);
  

  if (d > 5)
  {
    if (dl > 15)// fi 5ater ** yasser bagga **
    {
      digitalWrite(arriereMG, LOW);
      digitalWrite(avantMG, HIGH);
      digitalWrite(arriereMD, LOW );
      digitalWrite(avantMD, HIGH );
      analogWrite(vitesseMg, 0);
      analogWrite(vitesseMd, 160);
    }
    else if (dl < 13)
    {
      digitalWrite(arriereMG, LOW);
      digitalWrite(avantMG, HIGH);
      digitalWrite(arriereMD, LOW );
      digitalWrite(avantMD, HIGH );
      analogWrite(vitesseMg, 160);
      analogWrite(vitesseMd, 0);

    }
    else
    {
      digitalWrite(arriereMG, LOW);
      digitalWrite(avantMG, HIGH);
      digitalWrite(arriereMD, LOW );
      digitalWrite(avantMD, HIGH );
      analogWrite(vitesseMg, 140);
      analogWrite(vitesseMd, 140);

    }
  }
  else
  {
    digitalWrite(arriereMG, LOW);
    digitalWrite(avantMG, HIGH);
    digitalWrite(arriereMD, HIGH );
    digitalWrite(avantMD, LOW );
    analogWrite(vitesseMg, 180);
    analogWrite(vitesseMd, 180);
    delay(400);
  }
}
}}
