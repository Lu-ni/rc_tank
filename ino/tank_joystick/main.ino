#include <PS3BT.h>                                                    //Include the necessary libraries.
#include <SPI.h>

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);

const int controlPin11 = 2; // connected to pin 7 on the H-bridge --- sens avant moteur 1
const int controlPin12 = 3; // connected to pin 2 on the H-bridge --- sens arrière moteur 1
const int enablePin1 = 5;   // connected to pin 1 on the H-bridge --- entrée pwm moteur 1


const int controlPin21 = 21; // connected to pin 7 on the H-bridge --- sens avant moteur 2
const int controlPin22 = 7; // connected to pin 2 on the H-bridge --- sens arrière moteur 2
const int enablePin2 = 6;   // connected to pin 1 on the H-bridge --- entrée pwm moteur 2


float ratioGauche, ratioDroite, droite, gauche; //variable à virgule pour crée un ratio sur les vitesse éféctive en droite et en gauche
int motorSpeed, MsGauche, MsDroite;

//////////////////////////////////////////////////////////////////
////////////////////////////  SETUP  ////////////////////////////
////////////////////////////////////////////////////////////////
void setup() {
  Serial.begin(115200);
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); //halt
  }
  Serial.print(F("\r\nPS3 Bluetooth Library Started"));

  pinMode(controlPin11, OUTPUT);
  pinMode(controlPin12, OUTPUT);
  pinMode(enablePin1, OUTPUT);
  pinMode(controlPin21, OUTPUT);
  pinMode(controlPin22, OUTPUT);
  pinMode(enablePin2, OUTPUT);
}


/////////////////////////////////////////////////////////////////
////////////////////////////  LOOP  ////////////////////////////
///////////////////////////////////////////////////////////////
void loop() {
  Usb.Task();
  if (PS3.PS3Connected || PS3.PS3NavigationConnected) {

    if (PS3.getButtonClick(PS)) { //éteind la manette en appuyant sur le bouton PS (bouton du millieux)
      Serial.print(F("\r\nPS"));
      PS3.disconnect();
    }
    
    if (PS3.getAnalogHat(RightHatY) < 110) { //marche avant
      vitesse_avant(); //action à faire quand le joystick est en avant

      
    } else if (PS3.getAnalogHat(RightHatY) > 130) { //marche arrière
      vitesse_arriere(); //action  à faire quand L2 est pressé

      
    } else if ((PS3.getButtonPress(RIGHT)) || (PS3.getButtonPress(LEFT))) {
      rotation_sur_place();
    } else {
      inactif();                                                            //action à faire quand aucune touche n'est pressée
    }
  }//if (PS3.PS3Connected || PS3.PS3NavigationConnected) {
}//loop



///////////////////////////////////////////////////////////////////////////
////////////////////////////  Calcul_vitesse R2  ////////////////////////////
/////////////////////////////////////////////////////////////////////////
int vitesse_avant(void) {
  Serial.println("Avant");
  Serial.println(PS3.getAnalogHat(RightHatY));
  motorSpeed = map(PS3.getAnalogHat(RightHatY), 110, 0, 50, 170);
  Serial.println(motorSpeed);
  gauche = map(PS3.getAnalogHat(LeftHatX), 255, 0, 0, 200) - 100;
  gauche = 100 - gauche;
  if (gauche < 30) {
    gauche = 30;
  };
  if (gauche > 100) {
    gauche = 100;
  };
  droite = map(PS3.getAnalogHat(LeftHatX), 0, 255, 0, 200) - 100;
  droite = 100 - droite;
  if (droite < 15) {
    droite = 15;
  };
  if (droite > 100) {
    droite = 100;
  };
  ratioGauche = droite / 100;
  ratioDroite = gauche / 100;
  MsGauche = motorSpeed * ratioGauche;
  MsDroite = motorSpeed * ratioDroite;
  digitalWrite(controlPin12, LOW);
  digitalWrite(controlPin22, LOW);
  digitalWrite(controlPin11, HIGH);
  digitalWrite(controlPin21, HIGH);
  analogWrite(enablePin2, MsGauche);
  analogWrite(enablePin1, MsDroite);

}


///////////////////////////////////////////////////////////////////////////
////////////////////////////  Calcul_vitesse L2  ////////////////////////////
/////////////////////////////////////////////////////////////////////////
int vitesse_arriere(void) {

  Serial.println("marche arrière");
  motorSpeed = map(PS3.getAnalogHat(RightHatY), 130, 255, 50, 170);

  gauche = map(PS3.getAnalogHat(LeftHatX), 255, 0, 0, 200) - 100;
  gauche = 100 - gauche;
  if (gauche < 10) {
    gauche = 10;
  };
  if (gauche > 100) {
    gauche = 100;
  };

  droite = map(PS3.getAnalogHat(LeftHatX), 0, 255, 0, 200) - 100;
  droite = 100 - droite;
  if (droite < 10) {
    droite = 10;
  };
  if (droite > 100) {
    droite = 100;
  };
  ratioGauche = droite / 100;
  ratioDroite = gauche / 100;
  MsGauche = motorSpeed * ratioGauche;
  MsDroite = motorSpeed * ratioDroite;
  digitalWrite(controlPin11, LOW);
  digitalWrite(controlPin21, LOW);
  digitalWrite(controlPin12, HIGH);
  digitalWrite(controlPin22, HIGH);
  analogWrite(enablePin2, MsGauche);
  analogWrite(enablePin1, MsDroite);
}
///////////////////////////////////////////////////////////////////////////
////////////////////////////  Inactif  ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int inactif(void) {
  MsGauche = 0;
  MsDroite = 0;
  digitalWrite(controlPin11, LOW);
  digitalWrite(controlPin21, LOW);
  digitalWrite(controlPin12, LOW);
  digitalWrite(controlPin22, LOW);
  analogWrite(enablePin2, MsGauche);
  analogWrite(enablePin1, MsDroite);
}
///////////////////////////////////////////////////////////////////////////
////////////////////////////  Rotation sur place  ///////////////////////////////////
/////////////////////////////////////////////////////////////////////////
int rotation_sur_place(void) {
  if (PS3.getButtonPress(RIGHT)) {
    Serial.println("droite");
    digitalWrite(controlPin11, HIGH);
    digitalWrite(controlPin21, LOW);
    digitalWrite(controlPin12, LOW);
    digitalWrite(controlPin22, HIGH);
  } else {
    Serial.println("gauche");
    digitalWrite(controlPin11, LOW);
    digitalWrite(controlPin21, HIGH);
    digitalWrite(controlPin12, HIGH);
    digitalWrite(controlPin22, LOW);
  }
  analogWrite(enablePin2, 100);
  analogWrite(enablePin1, 100);
}
