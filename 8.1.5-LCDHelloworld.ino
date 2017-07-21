/*
LiquidCrystal Library - Hello World

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

 This sketch prints "Hello World!" to the LCDand shows the time.
*/

// 包含头文件
#include <LiquidCrystal.h>

// 实例化一个名为lcd的LiquidCrysta类型对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // 设置LCD有几列几行，1602LCD为16列2行
  lcd.begin(16, 2);
  //打印一段信息到LCD上
lcd.print("hello, world!");
}

void loop() {
  // 将光标设置在列 0, 行 1
  // 注意：在1602 LCD上行列的标号都是从0开始
  lcd.setCursor(0, 1);
  // 将系统运行时间打印到LCD上
  lcd.print(millis()/1000);
}