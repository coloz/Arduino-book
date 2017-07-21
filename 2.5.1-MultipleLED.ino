/*
流水灯效果
奈何col
*/

void setup()
{
  //初始化I/O口
  for (int i = 2; i < 8; i++)
    pinMode(i, OUTPUT);
}

void loop()
{
  //从引脚2到引脚7，逐个点亮LED，等待1秒再熄灭LED
  for (int i = 2; i < 7; i++)
  {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
  //从引脚7到引脚2，逐个点亮LED，等待1秒再熄灭LED
  for (int i = 7; i > 2; i--)
  {
    digitalWrite(i, HIGH);
    delay(1000);
    digitalWrite(i, LOW);
  }
}