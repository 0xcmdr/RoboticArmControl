#include <MyServos.h>

/*SERVOYU OLUSTUR*/
MyServos::MyServos(){
  //BOS CONSTRUCTOR
}

MyServos::MyServos(int maxAci,int minAci, byte pinAdi,byte aciArtis,byte delays){
max=maxAci;
min=minAci;
pin=pinAdi;
gecikme=delays;
hiz=aciArtis;
}

int MyServos::sagaDon(){
  servom.attach(pin);
  //acinin degerini oku
  int anlikAci=servom.read();
  //eğer açı maxtaysa işlem yapma
  if(!(anlikAci >= max)){
    //aci degeri max a ulasmadiysa aciyi arttir
      servom.write(anlikAci+hiz); //aciyi arttir
      delay(gecikme); //dönüş hızını ayarlamak için

  }
  servom.detach(); //servo gücünü kes
  delay(1);//titremeyi engelle
return anlikAci; //son aciyi donder
}

int MyServos::solaDon(){
  servom.attach(pin); //servoyu aktif et
  //acinin degerini oku
  int anlikAci=servom.read();
  //anlıkaçı minimumdan büyükse hareket ettir
  if((anlikAci > min)){
    servom.write(anlikAci-hiz); //aciyi arttir
    delay(gecikme);
  }
  servom.detach(); //servo gücünü kes
  delay(1); //titremeyi engelle
return anlikAci; //oanki aciyi donder
}
