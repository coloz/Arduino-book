/*
使用print函数输出数据到LCD
图形显示器：OpenJumper MINI 12864
控制器：Arduino UNO
*/

#include "U8glib.h"

U8GLIB_MINI12864 u8g(10, 9, 8);

String t1 = "OpenJumper";
String t2 = "MINI";
int t3 = 12864;

// draw函数用于包含实现显示内容的语句
void draw(void)
{
    // 设定字体->指定输出位置->输出数据
    u8g.setFont(u8g_font_ncenB14);
    u8g.setPrintPos(0, 20);
    u8g.print(t1);
    u8g.setFont(u8g_font_unifont);
    u8g.setPrintPos(50, 40);
    u8g.print(t2);
    u8g.setPrintPos(45, 60);
    u8g.print(t3);
}

void setup(void)
{
}

void loop(void)
{
    // u8glib图片循环结构：
    u8g.firstPage();
    do
    {
        draw();
    } while (u8g.nextPage());
    // 等待一定时间后重绘
    delay(500);
}