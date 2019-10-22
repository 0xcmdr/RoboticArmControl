#ifndef MYCONTROLS_H
#define MYCONTROLS_H

#include <MyServos.h>
#include <Arduino.h>

class MyControls{

byte xPin,yPin;//joystick in Arduino uzerindeki x ve y pinleri
public:
  MyServos* servomX;//X ve Y Eksenine gore hareket edecek servolar
  MyServos* servomY;//X ve Y Eksenine gore hareket edecek servolar
  MyControls();
  MyControls(byte xPini, byte yPini); //CONSTRUCTOR
  bool xEksenineAta(MyServos* servoX); //bir servoyu x eksenine atar
  bool yEksenineAta(MyServos* servoY); //bir servoyu y eksenine atar
  int getXEkseni(); //x ekseninin o anki degerini donderir
  int getYEkseni(); //y ekseninin o anki degerini donderir

};

#endif
