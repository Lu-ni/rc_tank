///////////////////////////////////////////////////////////////////////////
////////////////////////////  Calcul_vitesse R2  ////////////////////////////
/////////////////////////////////////////////////////////////////////////
int vitesse_r2(void) {
  Serial.println("Avant");
  motorSpeed = map(PS3.getAnalogButton(R2), 0, 255, 0, 180);
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
