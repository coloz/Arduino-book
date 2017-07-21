/*
使用通过2号引脚连接的按键，控制13号引脚连接的LED

备注：大多数Arduino的13号引脚上都连接了名为L的LED.

 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
*/

// 设置各引脚别名
const int buttonPin = 2; // 连接按键的引脚
const int ledPin = 13;   // 连接LED的引脚

// 变量定义
int buttonState = 0; // 存储按键状态的变量

void setup()
{
  // 初始化LED引脚为输出状态
  pinMode(ledPin, OUTPUT);
  // 初始化按键引脚为输入状态
  pinMode(buttonPin, INPUT);
}

void loop()
{
  // 读取按键状态并存储在变量中
  buttonState = digitalRead(buttonPin);

  // 检查按键是否被按下
  // 如果按键按下，那buttonState应该为高电平
  if (buttonState == HIGH)
  {
    //点亮LED
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    // 熄灭LED
    digitalWrite(ledPin, LOW);
  }
}