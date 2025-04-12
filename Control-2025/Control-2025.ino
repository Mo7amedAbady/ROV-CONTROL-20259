#include <ESP32Servo.h>
#define Griber1 5
#define Griber2 19
Servo motor1;Servo motor2;Servo motor3;Servo motor4;Servo motor5;Servo motor6;
void setup() {
  motor1.attach(12); motor2.attach(13); motor3.attach(14);
  motor4.attach(15); motor5.attach(2); motor6.attach(4);
  motor1.writeMicroseconds(1500);motor2.writeMicroseconds(1500);motor3.writeMicroseconds(1500);motor4.writeMicroseconds(1500);motor5.writeMicroseconds(1500);motor6.writeMicroseconds(1500);
  Serial.begin(115200);
  Serial.setTimeout(2);
  delay(1000); 
}

void front(int sped){
  motor1.writeMicroseconds(sped); motor2.writeMicroseconds(sped); motor3.writeMicroseconds(sped);motor4.writeMicroseconds(sped);
}
void back(int sped){
  motor1.writeMicroseconds(1500-(sped-1500));motor2.writeMicroseconds(1500-(sped-1500));motor3.writeMicroseconds(1500-(sped-1500));motor4.writeMicroseconds(1500-(sped-1500));
}
void right(int sped){
  motor1.writeMicroseconds(sped); motor2.writeMicroseconds(1500-(sped-1500)); motor3.writeMicroseconds(1500-(sped-1500));motor4.writeMicroseconds(sped);
}
void left(int sped){
  motor1.writeMicroseconds(1500-(sped-1500)); motor2.writeMicroseconds(sped); motor3.writeMicroseconds(sped);motor4.writeMicroseconds(1500-(sped-1500));
}
void Rotate_H_Right(int sped){
  motor1.writeMicroseconds(sped); motor2.writeMicroseconds(1500-(sped-1500)); motor3.writeMicroseconds(sped);motor4.writeMicroseconds(1500-(sped-1500));
}
void Rotate_H_Left(int sped){
  motor1.writeMicroseconds(1500-(sped-1500)); motor2.writeMicroseconds(sped); motor3.writeMicroseconds(1500-(sped-1500));motor4.writeMicroseconds(sped);
}
void up(int sped){
  motor5.writeMicroseconds(sped); motor6.writeMicroseconds(sped);
}
void down(int sped){
  motor5.writeMicroseconds(1500-(sped-1500)); motor6.writeMicroseconds(1500-(sped-1500));
}

void loop() {
  if (Serial.available()){
    String motion = Serial.readStringUntil('\0');
    motion.trim();
    int F=int(motion[0]-48) , B=int(motion[1]-48) , R=int(motion[2]-48) , L=int(motion[3]-48) , U=int(motion[4]-48) , D=int(motion[5]-48) , RHR=int(motion[6]-48) , RHL=int(motion[7]-48) , G1=int(motion[8]-48) , G2=int(motion[9]-48) ;
    int FRONT=map(F,0,8,1500,1900) , BACK=map(B,0,8,1500,1900) , UP=map(U,0,8,1500,1900) , DOWN=map(D,0,8,1500,1900) , RIGHT=map(R,0,8,1500,1900) , LEFT=map(L,0,8,1500,1900) , ROTATE_H_RIGHT=map(RHR,0,8,1500,1900) , ROTATE_H_LEFT=map(RHL,0,8,1500,1900);
    if (F){
      front(FRONT);
    }
    else if (B) {
      back(BACK);
    }
    else if (R) {
      right(RIGHT);
    }
    else if (L) {
      left(LEFT);
    }
    else if (RHR) {
      Rotate_H_Right(ROTATE_H_RIGHT);
    }
    else {
      Rotate_H_Left(ROTATE_H_LEFT);
    }
    if (U){
      up(UP);
    }
    else {
      down(DOWN);
    }
    if (G1){
      digitalWrite(Griber1,HIGH);
    }
    else {
      digitalWrite(Griber1,LOW);
    }
    if (G2){
      digitalWrite(Griber2,HIGH);
    }
    else {
      digitalWrite(Griber2,LOW);
    }
  }
}
