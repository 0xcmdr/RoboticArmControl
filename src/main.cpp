#include <Arduino.h>
#include <MyServos.h>
#include <MyControls.h>

MyControls* joystick1;
MyControls* joystick2;

MyServos* morServo;
MyServos* siyahServo1;
MyServos* siyahServo2;
MyServos* yesilServo;
MyServos* kirServo;
//MyServos* maviServo;

void setup() {
  /*Joystick oluşturmak için MyControls sınıfından obje türetmeniz lazım
  Her bir obje bir joysticke denk gelir.Aşağıdaki parametrelerde,
  AO=VRX pininin takıldığı arduino pininin adı
  A1=VRY Pininin takıldığı arduino pininin adı*/
  joystick1=new MyControls(A0,A1);
  joystick2=new MyControls(A2,A3);
  /*Servo oluşturmak içinse MyServos sınıfından nesne türetmelisiniz
  Servo üretmek için grekli parametreler şu şekilde
  new MyServos(int maxAci,int minAci, byte pinAdi,byte aciArtis,byte gecikme)
  maxAci= servonun ulasacağı max aci degeri.(donanımsal olarak sağlanan max)
  minAci=minimum geleceği açı değeri(genelde sıfır verilir)
  pinAdi=servonun bağlandığo digital pin numarası(pin pwm olmalıdır)
  aciArtis=acinin artis miktarı 1 verilirse aci 1 er 1 er artar
  gecikme=aciArtis gibi dönüs hızını ayarlamak icin kullanılır.(değer vererek hızınızı ayarlayın default 50 veya 100 verin)
  */
  morServo=new MyServos(360,0,8,1,50);
  siyahServo1=new MyServos(180,0,9,1,50);
  siyahServo2=new MyServos(180,0,10,1,50);
  yesilServo=new MyServos(180,0,11,1,50);
  kirServo=new MyServos(180,0,12,1,50);

  /*Herbir joystick maximum 2 servo kontrol edebilir, birisi x ekseni diğeri y eksenin
  Eğer servoyu x ekseninde kontrol edecekseniz, oluşturduğunuz joystickin ilgili metoduyla bağlayın
  Benzer şekilde ye ekseninene de servo bağlayın.Bağlamak şart değil. Boşta kalabilir.Kullanılacaksa bağlayın

  */
  //1.Joysticke resimdeki yesil ve kirmizi servolar atanıyor

  joystick1->yEksenineAta(morServo);
  //siyahServo2 atanmayacak manuel olarak dönderilecek.
  joystick1->xEksenineAta(siyahServo1);

  //2.Joysticke resimdeki yesil ve kirmizi servolar atanıyor
  joystick2->yEksenineAta(yesilServo);
  joystick2->xEksenineAta(kirServo);



}

void loop() {
  /*JOYSTICK 1 X EKSENI KONTROLÜ(SİYAH SERVOLAR)*/

  /*eğer joystick 1 in X ekseni > 700 yani
  Dikeyde yukarı (+X) hareket ettirince
(SAĞ VE SOL KAVRAMLARI DURUMA GÖRE DEĞİŞEBİLİR.
SAĞA DÖNMEK AÇIYI ARTIRIR. SOLA DÖNMEK AÇIYI AZALTIR.)
  */
  if(joystick1->getXEkseni() > 700){
    //joystick1'in X eksenine bağlı servonun acisini arttır
    joystick1->servomX->sagaDon();
    siyahServo2->solaDon();
  }

  /*eğer joystick 1 in X ekseni  < 300  yani
  Dikeyde aşağı (-X) hareket ettirince
  */
  else if(joystick1->getXEkseni() <300){
    //joystick1'in X eksenine bağlı servonun acisini azalt
    joystick1->servomX->solaDon();
    //siyah servoları ters calistir
    siyahServo2->sagaDon();
  }

/*JOYSTICK 1 Y EKSENI KONTROLÜ (MOR SERVO)*/

/*eğer joystick 1 in X ekseni > 700 yani
Yatayda Sağ (+Y) hareket ettirince
*/
  if(joystick1->getYEkseni() > 700){
    //joystick1'in Y eksenine bağlı servonun acisini arttır
    joystick1->servomY->sagaDon();
  }

  /*eğer joystick 1 in X ekseni < 300 yani
  Yatayda Sol (-Y) hareket ettirince
  */
  else if(joystick1->getYEkseni() <300){
    //joystick1'in Y eksenine bağlı servonun acisini azalt
    joystick1->servomY->solaDon();
  }


  /*JOYSTICK 2 X EKSENI KONTROLÜ(KIRMIZI SERVO)*/

  /*eğer joystick 1 in X ekseni > 700 yani
  Dikeyde yukarı (+X) hareket ettirince
  */
  if(joystick2->getXEkseni() > 700){
    //joystick2'in X eksenine bağlı servonun acisini arttır
    joystick2->servomX->sagaDon();
  }

  /*eğer joystick 2 in X ekseni < 300 ise yani
  Dikeyde aşağı (-X) hareket ettirince
  */
  else if(joystick2->getXEkseni() <300){
    //joystick2'in X eksenine bağlı servonun acisini azalt
    joystick2->servomX->solaDon();

  }

/*JOYSTICK 2 Y EKSENI KONTROLÜ (YEŞİL SERVO)*/

/*eğer joystick 2 in X ekseni > 700 yani
Yatayda Sağ (+Y) hareket ettirince
*/
  if(joystick2->getYEkseni() > 700){
    //joystick2'in Y eksenine bağlı servonun acisini arttır
    joystick2->servomY->sagaDon();
  }

  /*eğer joystick 1 in X ekseni  < 300  yani
  Yatayda Sol (-Y) hareket ettirince
  */
  else if(joystick2->getYEkseni() <300){
    //joystick2'in Y eksenine bağlı servonun acisini azalt
    joystick2->servomY->solaDon();
  }


}
