/*
* EEPROM Write
* Stores values read from analog input 0 into the EEPROM.
* These values will stay in the EEPROM when the board is
* turned off and may be retrieved later by another sketch.
*/

#include <EEPROM.h>

// EEPROM 的当前地址,即你将要写入的地址,这里就是从0开始写
int addr = 0;

void setup()
{
}

void loop()
{
  //模拟值读出后是一个0-1024的值，但每字节的大小为0-255
//所以这里将值除以4再存储到val
  int val = analogRead(0) / 4;

  // 写入数据到对应的EEPROM空间
  // 即使Arduino断电，数据也会保存在EEPROM里
  EEPROM.write(addr, val);

  // 逐字节写入数据
  // 当EEPROM空间写满后，重新从0地址开始写
  addr = addr + 1;
  if (addr == 512)
    addr = 0;
  delay(100);
}