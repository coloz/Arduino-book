/*
  LiquidCrystal Library - Custom Characters

 Demonstrates how to add custom characters on an LCD  display.  
 The LiquidCrystal library works with all LCD displays that are 
compatible with the  Hitachi HD44780 driver. There are many of 
them out there, and you can usually tell them by the 16-pin interface.

 This sketch prints "I <heart> Arduino!" and a little dancing man
to the LCD.
*/

// 包含头文件
#include <LiquidCrystal.h>

//实例化一个名为lcd的LiquidCrysta类型对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 自定义字符：
byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000};

byte smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000};

byte frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001};

byte armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010};

byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010};
void setup()
{
    // 创建一个新字符
    lcd.createChar(8, heart);
    // 创建一个新字符
    lcd.createChar(1, smiley);
    // 创建一个新字符
    lcd.createChar(2, frownie);
    // 创建一个新字符
    lcd.createChar(3, armsDown);
    // 创建一个新字符
    lcd.createChar(4, armsUp);

    //设置LCD有几列几行，1602LCD为16列2行
    lcd.begin(16, 2);
    // 输出信息到LCD上
    lcd.print("I ");
    lcd.write(8);
    lcd.print(" Arduino! ");
    lcd.write(1);
}

void loop()
{
    // 读A0引脚连接的电位器的值
    int sensorReading = analogRead(A0);
    // 将数据范围转换到 200 - 1000:
    int delayTime = map(sensorReading, 0, 1023, 200, 1000);
    // 设置光标在第二行，第五列
    lcd.setCursor(4, 1);
    // 小人手臂放下
    lcd.write(3);
    delay(delayTime);
    lcd.setCursor(4, 1);
    // 小人手臂抬起
    lcd.write(4);
    delay(delayTime);
}