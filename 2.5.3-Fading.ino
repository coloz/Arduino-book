/*
Fading
通过analogWrite()函数实现呼吸灯效果
 */

int ledPin = 9; // LED连接在9号引脚上

void setup()
{
  // Setup部分不进行任何处理
}

void loop()
{
  // 从暗到亮，以每次加5的形式逐渐亮起来
  for (int fadeValue = 0; fadeValue <= 255; fadeValue += 5)
  {
    // 输出PWM
    analogWrite(ledPin, fadeValue);
    // 等待30ms，以便观察到渐变效果
    delay(30);
  }

  //从亮到暗，以每次减5的形式逐渐暗下来
  for (int fadeValue = 255; fadeValue >= 0; fadeValue -= 5)
  {
    //输出PWM
    analogWrite(ledPin, fadeValue);
    //等待30ms，以便观察到渐变效果
    delay(30);
  }
}