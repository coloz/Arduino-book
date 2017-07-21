// Wire Master Reader
// by Nicholas Zambetti <http://www.zambetti.com>
// Demonstrates use of the Wire library
// Reads data from an I2C/TWI slave device
// Refer to the "Wire Slave Sender" example for use with this
// Created 29 March 2006
// This example code is in the public domain.

#include <Wire.h>

void setup()
{
//作为主机加入IIC总线
  Wire.begin();        
  Serial.begin(9600); // 初始化串口通信
}

void loop()
{
  Wire.requestFrom(2, 6); // 向2号从机请求6个字节的数据
  while(Wire.available())// 等待从机发送完数据
  { 
    char c = Wire.read(); // 将数据作为字符接收
    Serial.print(c);       // 串口输出字符
  }
  delay(500);
}