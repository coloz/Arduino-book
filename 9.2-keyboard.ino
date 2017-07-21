/* 
 Keyboard Button test
该程序仅适用于Leonardo、Micro.
当按下按键时，发送文本.
 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/KeyboardButton
 */

const int buttonPin = 2;        // 按键连接引脚
int previousButtonState = HIGH; // 之前按键状态
int counter = 0;                // 按键计数器

void setup()
{
    // 初始化按键引脚，如果没有上拉电阻，需要使用INPUT_PULLUP
    pinMode(buttonPin, INPUT);
    // 初始化模拟键盘功能
    Keyboard.begin();
}

void loop()
{
    // 读按键状态
    int buttonState = digitalRead(buttonPin);
    // 如果按键状态改变，且当前按键状态为高电平
    if ((buttonState != previousButtonState) && (buttonState == HIGH))
    {
        // 按键计数器加1
        counter++;
        // 模拟键盘输入信息
        Keyboard.print("You pressed the button ");
        Keyboard.print(counter);
        Keyboard.println(" times.");
    }
    // 保存当前按键状态，用于下一次比较
    previousButtonState = buttonState;
}