// Wire Master Writer
// by Nicholas Zambetti <http://www.zambetti.com>
// Demonstrates use of the Wire library
// Writes data to an I2C/TWI slave device
// Refer to the "Wire Slave Receiver" example for use with this
// Created 29 March 2006
// This example code is in the public domain.

#include <Wire.h>

void setup()
{
//作为主机加入到IIC总线
  Wire.begin(); 
}

byte x = 0;

void loop()
{
  Wire.beginTransmission(4); //向地址为4的从机传送数据
  Wire.write("x is ");        // 发送5个字节的字符串
  Wire.write(x);              // 发送1个字节的数据
  Wire.endTransmission();    // 结束传送
  x++;
  delay(500);
}