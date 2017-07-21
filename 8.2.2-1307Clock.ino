/*
DS1307和1602 LCD制作电子时钟
*/
// 引用会使用到的四个库文件
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>
#include <LiquidCrystal.h>

// 实例化一个名为lcd的LiquidCrysta类型对象，并初始化相关引脚
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
{
    // 设置LCD有几列几行，1602LCD为16列2行
    lcd.begin(16, 2);
    // 打印一段信息到LCD上
    lcd.print("This is a Clock");
    delay(3000);
    lcd.clear();
}

void loop()
{
    tmElements_t tm;
    // 读出DS1307中的时间数据，并存入tm中
    if (RTC.read(tm))
    {
        // 清除屏幕显示内容
        lcd.clear();
        //在LCD第一行输出日期信息
        lcd.setCursor(0, 0);
        lcd.print(tmYearToCalendar(tm.Year));
        lcd.print("-");
        lcd.print(tm.Month);
        lcd.print("-");
        lcd.print(tm.Day);
        //在LCD第二行输出时间信息
        lcd.setCursor(8, 1);
        lcd.print(tm.Hour);
        lcd.print(":");
        lcd.print(tm.Minute);
        lcd.print(":");
        lcd.print(tm.Second);
    }
    // 如果读取数据失败，则输出错误提示
    else
    {
        lcd.setCursor(0, 1);
        lcd.print("error");
    }
    //每秒钟更新一次显示内容
    delay(1000);
}