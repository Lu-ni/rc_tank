///////////////////////////////////////////////////////////////////////////
////////////////////////////  Calcul_vitesse L2  ////////////////////////////
/////////////////////////////////////////////////////////////////////////
int vitesse_l2(void) {

  Serial.println("marche arrière");
  motorSpeed = map(PS3.getAnalogButton(L2), 0, 255, 0, 180);

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
