/*
串口控制开关灯
奈何col
*/

void setup()
{
  // 初始化串口
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop()
{
  // 如果缓冲区中有数据，则读取并输出
  if (Serial.available() > 0)
  {
    char ch = Serial.read();
    Serial.print(ch);
    //开灯
    if (ch == 'a')
    {
      digitalWrite(13, HIGH);
      Serial.println("turn on");
    }
    //关灯
    else if (ch == 'b')
    {
      digitalWrite(13, LOW);
      Serial.println("turn off");
    }
  }
}