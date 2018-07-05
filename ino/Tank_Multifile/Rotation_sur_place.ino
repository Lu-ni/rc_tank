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
