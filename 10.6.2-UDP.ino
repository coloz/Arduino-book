/*
  UDPSendReceive.pde:
 This sketch receives UDP message strings, prints them to the serial port
 and sends an "acknowledge" string back to the sender

 A Processing sketch is included at the end of file that can be used to send 
and received messages for testing with a computer.

 created 21 Aug 2010
 by Michael Margolis

 This code is in the public domain.
*/

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// 为你的Arduino设置MAC地址和IP地址
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 0, 177);

unsigned int localPort = 8888;      // 设置需要监听的端口

// 接收和发送数据的数组
char packetBuffer[UDP_TX_PACKET_MAX_SIZE];//保存收到的数据包的缓冲区
char ReplyBuffer[] = "acknowledged";       // 一个返回的字符串

// 程序中我们需要使用EthernetUDP类库发送接收数据包
EthernetUDP Udp;

void setup() {
  // 初始化网络并开始UDP通信
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  Serial.begin(9600);
}

void loop() {
  // 如果有可读数据, 那么读取一个包
  int packetSize = Udp.parsePacket();
  if(packetSize)
  {
    Serial.print("Received packet of size ");
    Serial.println(packetSize);
Serial.print("From ");
// 输出IP地址，端口等UDP连接信息
    IPAddress remote = Udp.remoteIP();
    for (int i =0; i < 4; i++)
    {
      Serial.print(remote[i], DEC);
      if (i < 3)
      {
Serial.print(".");
      }
    }
    Serial.print(", port ");
    Serial.println(Udp.remotePort());

    // 将数据包读进数组
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    Serial.println("Contents:");
    Serial.println(packetBuffer);

    // 发送应答，到刚才传输数据包来的设备
    Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
    Udp.write(ReplyBuffer);
    Udp.endPacket();
  }
  delay(10);
}