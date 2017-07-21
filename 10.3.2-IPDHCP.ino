/*
OpenJumper DHCP Example
http://www.openjumper.com/
http://x.openjumper.com/ethernet/

*/

#include <SPI.h>
#include <Ethernet.h>

// 设置MAC地址
byte mac[] = { 0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };

void setup() {
 // 初始化串口通信
  Serial.begin(9600);
  // 开启Ethernet连接:
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
    // 连接失败，便进入一个死循环（相当于结束程序运行）
for(;;);
  }
  // 输出你的本地IP地址
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // 将四个字节的IP地址逐字节输出
    Serial.print(Ethernet.localIP()[thisByte], DEC);
Serial.print("."); 
  }
  Serial.println();
}

void loop() {
}