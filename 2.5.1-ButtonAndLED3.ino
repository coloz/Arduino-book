/*
按键控制LED
奈何col
*/

int buttonPin = 2;
int ledPin = 13;
boolean ledState = false;   // 记录LED状态
boolean buttonState = true; // 记录按键状态

void setup()
{
  //初始化I/O口
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop()
{
  //等待按键按下
  while (digitalRead(buttonPin) == HIGH)
  {
  }

  //当按键按下时，点亮或熄灭LED
  if (ledState == true)
  {
    digitalWrite(ledPin, LOW);
    ledState = !ledState;
  }
  else
  {
    digitalWrite(ledPin, HIGH);
    ledState = !ledState;
  }
  delay(500);
}