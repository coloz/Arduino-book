/*
OpenJumper Examples
写入float类型到EEPROM
奈何col  2013.2.2
www.openjumper.com
*/

#include <EEPROM.h>
union data {
    float a;
    byte b[4];
};
data c;
int addr = 0;
int led = 13;

void setup()
{
    c.a = 987.65;
    for (int i = 0; i < 4; i++)
        EEPROM.write(i, c.b[i]);
    pinMode(led, OUTPUT);
}

void loop()
{
    //LED闪烁，提示任务已完成
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
}