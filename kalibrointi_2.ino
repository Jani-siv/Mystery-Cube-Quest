//Lukee anturin pinit. A0 = X-akseli jne.
const int analogInPinX = A0;
const int analogInPinY = A1;
const int analogInPinZ = A2; 

//sensorarvot alussa
int sensorValueX = 0;
int sensorValueY = 0;
int sensorValueZ = 0;


unsigned long aika = 0;

//First time / start test
int sisaanmeno = 0;

//kalibroinnin arvot
float Ax = 0.0;
float Ay = 0.0;
float Az = 0.0;
float DegX = 0.0;
float DegY = 0.0;
float DegZ = 0.0;


float A = 0.0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  //Testi- ensimmäinen kertaa tai ei
  if(sisaanmeno == 0) {
    delay(500);
    Serial.print("Time(ms)");
    Serial.print("\t sens_x");
    Serial.print("\t sens_y");
    Serial.print("\t sens_z");
    Serial.print("\t DegX");
    Serial.print("\t DegY");
    Serial.print("\t DegZ");
    sisaanmeno = 1;
  }

  //sensorValueX jne. lukee mitä anturin X, Y ja Z näyttää
  sensorValueX = analogRead(analogInPinX);
  sensorValueY = analogRead(analogInPinY);
  sensorValueZ = analogRead(analogInPinZ);
  aika = millis();
  
  //ohjelma laskee sensoriarvoa vastaavan kiihtyvyyden
  //Tai selkkokielillä anturin kalibrointi :)
  Ax = 0.1307*sensorValueX - 45.519;
  Ay = 0.1306*sensorValueY - 45.277;
  Az = 0.1532*sensorValueZ - 55.368;
  Ax = min(9.81, Ax);
  Ay = min(9.81, Ay);
  Az = min(9.81, Az);
  Ax = max(-9.81, Ax);
  Ay = max(-9.81, Ay);
  Az = max(-9.81, Az);

  DegX = asin(Ax / 9.81) * 180 / 3.141593;
  DegY = asin(Ay / 9.81) * 180 / 3.141593;
  DegZ = asin(Az / 9.81) * 180 / 3.141593;
  

  //Sen jälkeen kaikki arvot viedään näyttölle. Aika ja X,Y,Z akselit.
  
  if(DegX > 30) {
    //left
  }
  if(DegX < -30) {
    //right
  }
  if(DegY > 30) {
    //Down
  }
  if(DegY < -30) {
    //Up
  }
  delay(100);
}
