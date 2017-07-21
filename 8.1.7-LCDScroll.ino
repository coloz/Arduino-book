/*
  LiquidCrystal Library - scrollDisplayLeft() and scrollDisplayRight()

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCD and uses the
 scrollDisplayLeft() and scrollDisplayRight() methods to scroll
the text.
*/

//包含头文件
#include <LiquidCrystal.h>

//实例化一个名为lcd的LiquidCrysta类型对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    //设置LCD有几列几行，1602LCD为16列2行
    lcd.begin(16, 2);
    // 打印一段信息到LCD上
    lcd.print("hello, world!");
    delay(1000);
}

void loop()
{
    // 向左滚动13格
    // 移动到显示区域以外
    for (int positionCounter = 0; positionCounter < 13; positionCounter++)
    {
        // 向左移动一格
        lcd.scrollDisplayLeft();
        // 等待一会儿
        delay(150);
    }

    // 向右滚动29格
    //移动到显示区域以外
    for (int positionCounter = 0; positionCounter < 29; positionCounter++)
    {
        // 向右移动一格
        lcd.scrollDisplayRight();
        //等待一会儿
        delay(150);
    }

    // 向左滚动16格
    // 移回中间位置
    for (int positionCounter = 0; positionCounter < 16; positionCounter++)
    {
        // 向左移动一格
        lcd.scrollDisplayLeft();
        //等待一会儿
        delay(150);
    }

    // 每次循环结束后，等待一会儿，再开始下一次循环
    delay(1000);
}