/*
Get the run time
http://www.arduino.cn/
*/
unsigned long time1;
unsigned long time2;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  time1 = millis();
  time2 = micros();
  //输出系统运行时间
  Serial.print(time1);
  Serial.println("ms");
  Serial.print(time2);
  Serial.println("us");
  //等待1秒开始下一次loop循环
  delay(1000);
}
