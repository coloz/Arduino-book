#include <SPI.h>
#include <Ethernet.h>

// 设置一个MAC地址
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
//设置一个IP地址
byte ip[] = {192, 168, 1, 177};

void setup()
{
    // 初始化Ethernet功能
    Ethernet.begin(mac, ip);
}

void loop()
{
}