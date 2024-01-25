float calc_temperature(float R) {
  const float R0 = 10000;
  const float T0 = 25;
  const float B = 3650;
  float T = 1 / (1/T0 + 1/B*log(R/R0));
  return T;
}

void Heat(){
  float R = 1023.0 / analogRead(PA0) - 1;
  if (calc_temperature(R) < 8) {
    Serial.println("Нагрев");
  }
}

void setup(){
  Serial.begin(9600);
}

void loop() {
  Heat();
}
