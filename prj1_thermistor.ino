 
int Rp = 348; // parallel reistance
int R0 = 1000;
int x; //resistance dependency parameter
 
int sensorPin0 = A0;    // select the input pin for the potentiometer
int sensorPin1 = A1;
int sensorPin5 =A5;
int ledPin = 13;      // select the pin for the LED
float sensorValue = 0;  // variable to store the value coming from the sensor
float sensorValue1 = 0;
float sensorValue5 = 0;
 
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
 
void loop() {

  sensorValue5 = analogRead(A5); // I am expecting to see the output voltage
  //sensorValue2 = analogRead(A2);//Vout
  int vi = 5;
  float vo = sensorValue5*5.0 /1023.0; //e0xperimental
  float Rt = (Rp * R0 *(1-(2*vo /vi))) / (Rp -(R0 *(1-2*vo/ vi)));

  float Vt = (vi/2)*((Rt * Rp)/((Rt+348)*R0) );
  float Vout = vi /2 +  Vt;
  //Serial.println(vo);
  Serial.println(sensorValue5 *5.0 /1023.0);
  //temperature
  Serial.println(sensorValue5 *100 /1023.0);
 
  delay(500);
}
