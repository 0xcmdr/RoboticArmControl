#include <MyControls.h>
MyControls::MyControls(){

}

/*Bu method joystickin x ve y eksenlerinin hangi pinlerden okunacagini
belirler*/
MyControls::MyControls(byte xPini,byte yPini){
  xPin=xPini;
  yPin=yPini;

}

//bir servoyu x eksenine atar
bool MyControls::xEksenineAta(MyServos* servoX){
  //servo X mevcutsa,iliskilendir
  if(servoX!=NULL)
    servomX=servoX;
}

//bir servoyu y eksenine atar
bool MyControls::yEksenineAta(MyServos* servoY){
  //servo Y mevcutsa,iliskilendir
if(servoY!=NULL)
  servomY=servoY;
}

//joystick in x ekseninin degeri
int MyControls::getXEkseni(){
  return analogRead(xPin);
}

//joystick in Y ekseninin degeri
int MyControls::getYEkseni(){
  return analogRead(yPin);
}
