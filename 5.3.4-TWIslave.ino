// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>
// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this
// Created 29 March 2006
// This example code is in the public domain.

#include <Wire.h>

void setup()
{
//作为从机加入IIC总线，从机地址为4
  Wire.begin(4); 
  //注册一个IIC事件
  Wire.onReceive(receiveEvent);
  //初始化串口
  Serial.begin(9600); 
}

void loop()
{
  delay(100);
}

// 当主机发送的数据被接收到时，将触发receiveEvent事件
void receiveEvent(int howMany)
{
// 循环读取接收到的数据，最后一个数据单独读取
  while(1 < Wire.available())
  {
    char c = Wire.read(); // 以字符形式接收数据
    Serial.print(c);       // 串口输出该字符
  }
  int x = Wire.read();    // 以整型形式接收数据
  Serial.println(x);      //串口输出该整形变量
}