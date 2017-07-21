int counter = 0; // 计数器

void setup()
{
  //初始化串口
  Serial.begin(9600);
}

void loop()
{
  //每loop循环一次，计数器变量加1
  counter = counter + 1;
  // 输出变量
  Serial.print(counter);
  // 输出字符
  Serial.print(‘
               :’);
  // 输出字符串;
  Serial.println("Hellow World");
  delay(1000);
}