void setup()
{
  Serial.begin(9600); // open serial port, set the baud rate to 9600 bps
}
const int light = 0;
const int dark =2000;
void loop()
{
      int val;
      //const int ligt = 0;
      //const int dark =1023;

      val=analogRead(A0);   //connect grayscale sensor to Analog 0
      //Serial.println((val/1023)*100);//print the value to serial
      int percent = map(val, dark, light, -50, 100);
      Serial.print(percent);
      Serial.println("%");
  
      delay(500);
}


