/*
  Digital Pot Control

  This example controls an Analog Devices AD5206 digital potentiometer.
  The AD5206 has 6 potentiometer channels. Each channel's pins are labeled
*/

// 引用SPI库
#include <SPI.h>

// 设置10号引脚控制AD5206的SS脚
const int slaveSelectPin = 10;

void setup() {
  // 设置SS为输出
  pinMode (slaveSelectPin, OUTPUT);
  // 初始化SPI
  SPI.begin(); 
}

void loop() {
  // 分别操作6个通道的数字电位器
  for (int channel = 0; channel < 6; channel++) { 
    // 逐渐增大每个通道的阻值
    for (int level = 0; level < 255; level++) {
      digitalPotWrite(channel, level);
      delay(10);
    }
    // 延时一段时间
    delay(100);
    // 逐渐减小每个通道的阻值
    for (int level = 0; level < 255; level++) {
      digitalPotWrite(channel, 255 - level);
      delay(10);
    }
  }
}

int digitalPotWrite(int address, int value) {
  // 将SS输出低电平，选择能这个设备
  digitalWrite(slaveSelectPin,LOW);
  // 向SPI传输地址和对应的配置值
  SPI.transfer(address);
  SPI.transfer(value);
  //将SS输出高电平，取消选择这个设备
  digitalWrite(slaveSelectPin,HIGH); 
}