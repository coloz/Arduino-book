/*
* EEPROM Read
* Reads the value of each byte of the EEPROM and prints it 
* to the computer.
* This example code is in the public domain.
*/

#include <EEPROM.h>

// 从地址0处开始读取EEPROM的值
int address = 0;
byte value;

void setup()
{
  //初始化串口，并等待计算机打开串口
  Serial.begin(9600);
  while (!Serial) {
    ; //等待串口连接，该功能仅支持Arduino Leonardo
  }
}

void loop()
{
  // 从当前EEPROM地址中读取一个字节数据
  value = EEPROM.read(address);

  Serial.print(address);
  Serial.print("\t");
  Serial.print(value, DEC);
  Serial.println();

  // 前进到下一个EEPROM地址
  address = address + 1;

  //当读到EEPROM尾部时，跳转到起始地址0处
  if (address == 512)
    address = 0;

  delay(500);
}