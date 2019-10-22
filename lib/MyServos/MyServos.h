#ifndef MYSERVOS_H
#define MYSERVOS_H

#include <Arduino.h>
#include <Servo.h>

class MyServos{
  int max; //Servonun donebilecegi max aci'(aci degerinde yazilmaz)
  int min; //servonun donebilecegi min aci (aci degerinde yazilmaz)
  byte pin,hiz,gecikme;
  Servo servom;
  /*DEFAULT CONSTRUCTOR*/
public:
  MyServos();
  MyServos(int maxAci,int minAci, byte pinAdi,byte aciArtis,byte gecikme); //Servoyu tanımlayıp oluşturacak
  int sagaDon(); //servoyu sağa dönderecek
  int solaDon(); //servoyu sola dönderecek

};
#endif
