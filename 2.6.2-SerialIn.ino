void setup()
{
  //初始化串口
  Serial.begin(9600);
}

void loop()
{
  // 读取输入的信息
  char ch = Serial.read();
  // 输出信息
  Serial.print(ch);
  delay(1000);
}