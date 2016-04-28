/*
按键控制LED
奈何col
*/
int buttonPin = 2;
int ledPin = 13;
int buttonState = 0; 
 
void setup() 
{
  //初始化I/O口
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(ledPin,OUTPUT);
}
 
void loop() 
{
  buttonState = digitalRead(buttonPin);
  //按住按键时，点亮LED；放开按键后，熄灭LED。
  if(buttonState==HIGH)
  {
    digitalWrite(ledPin,LOW);
  }
  else
  {
    digitalWrite(ledPin,HIGH);
  }
}