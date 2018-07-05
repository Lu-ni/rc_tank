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
