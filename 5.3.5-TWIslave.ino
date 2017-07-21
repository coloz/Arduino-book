// Wire Slave Sender
// by Nicholas Zambetti <http://www.zambetti.com>
// Demonstrates use of the Wire library
// Sends data as an I2C/TWI slave device
// Refer to the "Wire Master Reader" example for use with this
// Created 29 March 2006
// This example code is in the public domain.

#include <Wire.h>

void setup()
{
// 作为从机加入IIC总线，并将地址设为2
Wire.begin(2);  
// 注册一个事件，用于相应主机的数据请求
Wire.onRequest(requestEvent); 
}

void loop()
{
  delay(100);
}

// 每当主机请求数据时，该函数便会执行
// 在setup()中，该函数被注册为一个事件
void requestEvent()
{
  Wire.write("hello "); // 用6个字节的信息回应主机的请求，hello后带一个空格
}