/*
Arduino外部中断的使用
外部中断触发警报声
*/

//默认无遮挡，蜂鸣器发声
boolean RunBuzzer = true;

void setup()
{
  Serial.begin(9600);
  // 初始化外部中断
  // 当int.0电平由高变低时,触发中断函数Hello
  attachInterrupt(0, warning, CHANGE);
}

void loop()
{
  if (RunBuzzer)
  {
    tone(8, 1000);
  }
  else
  {
    noTone(8);
  }
}

// 中断函数
void warning()
{
  RunBuzzer = !RunBuzzer;
}