/*
OpenJumper WebClient Example
访问百度，搜索“OpenJumper Arduino”
并返回搜索结果。
http://www.openjumper.com/
http://x.openjumper.com/ethernet/
*/
#include <SPI.h>
#include <Ethernet.h>

// 输入MAC地址，及要访问的域名
byte mac[] = {  0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02 };
IPAddress ip(192,168,1,177);
char serverName[] = "www.baidu.com";

// 初始化客户端功能
EthernetClient client;

void setup() {
 // 初始化串口通信
  Serial.begin(9600);

  //开始Ethernet连接
  if (Ethernet.begin(mac) == 0) {
    Serial.println("Failed to configure Ethernet using DHCP");
// 如果DHCP方式获取IP失败,则使用自定义IP
Ethernet.begin(mac, ip);
  }
  // 等待1秒钟用于Ethernet扩展板或W5100芯片完成初始化
  delay(1000);
Serial.println("connecting...");

  // 如果连接成功，通过串口输出返回数据

  if (client.connect(serverName, 80)) {
    Serial.println("connected");
    // 发送HTTP请求:
    client.println("GET /s?wd=openjumper+arduino HTTP/1.1");
    client.println();
  } 
  else {
    // 如果连接失败则输出提示：
    Serial.println("connection failed");
  }
}

void loop()
{
  // 如果有可读的服务器返回数据，则读取并输出数据
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  //如果服务器中断了连接，则中断客户端功能
  if (!client.connected()) {
    Serial.println();
Serial.println("disconnecting.");
    client.stop();

    // 进入一个死循环，相当于停止程序
    while(true);
  }
}