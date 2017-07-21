/*
  LiquidCrystal Library - Serial Input

 Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 library works with all LCD displays that are compatible with the 
 Hitachi HD44780 driver. There are many of them out there, and you
can usually tell them by the 16-pin interface.

 This sketch displays text sent over the serial port
(e.g. from the Serial Monitor) on an attached LCD.
 */

// 包含头文件
#include <LiquidCrystal.h>

//实例化一个名为lcd的LiquidCrysta类型对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup(){
    //设置LCD有几列几行，1602LCD为16列2行
  lcd.begin(16, 2);
  // 初始化串口通信功能
  Serial.begin(9600);
}

void loop()
{
  // 当串口接收到字符时…
  if (Serial.available()) {
    // 等待所有数据输入进缓冲区
    delay(100);
    // 清屏
    lcd.clear();
    // 读取所有可用的字符
    while (Serial.available() > 0) {
      // 将字符一个一个的输出到LCD上。
      lcd.write(Serial.read());
    }
  }
}