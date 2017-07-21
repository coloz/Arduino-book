/*
使用电位器调节呼吸灯的呼吸频率
奈何col
*/

int ledPin = 9; //9号引脚控制LED
int pot = A0;   //A0引脚读取电位器输出电压
void setup() {}

void loop()
{
  //LED逐渐变亮
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5)
  {
    analogWrite(ledPin, fadeValue);
    //读取电位器输出电压，除以5时为了缩短延时时间
    int time = analogRead(pot) / 5;
    delay(time); //将time用于延时
  }
  //LED逐渐变暗
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5)
  {
    analogWrite(ledPin, fadeValue);
    delay(analogRead(pot) / 5); //读取电位器输出电压，并用于延时
  }
}