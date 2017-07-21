/*
OpenJumper WebServer Example
建立一个显示传感器信息的Arduino服务器
http://www.openjumper.com/
http://x.openjumper.com/ethernet/
*/

#include <SPI.h>
#include <Ethernet.h>

// 设定MAC地址、IP地址
// IP地址需要参考你的本地网络设置
byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);

// 初始化Ethernet库
// HTTP默认端口为80
EthernetServer server(80);

void setup() {
 // 初始化串口通信
  Serial.begin(9600);

  // 开始ethernet连接，并作为服务器初始化
  Ethernet.begin(mac, ip);
  server.begin();
  Serial.print("server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // 监听客户端传来的数据
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    // 一个Http请求结尾必须带有回车换行
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // 如果收到空白行，说明http请求结束，并发送响应消息
        if (c == '\n' && currentLineIsBlank) {
          // 发送标准的HTTP响应
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println("Connection: close");
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          // 添加一个meta刷新标签, 浏览器会每5秒刷新一次
          // 如果此处刷新频率设置过高，可能会出现网页的卡死的状况
          client.println("<meta http-equiv=\"refresh\" content=\"5\">");
          // 输出每个模拟口读到的值
          for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
            int sensorReading = analogRead(analogChannel);
            client.print("analog input ");
            client.print(analogChannel);
            client.print(" is ");
            client.print(sensorReading);
            client.println("<br />");       
          }
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // 已经开始一个新行
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // 在当前行已经得到一个字符
          currentLineIsBlank = false;
        }
      }
    }
    // 等待浏览器接收数据
    delay(1);
    // 断开连接
    client.stop();
    Serial.println("client disonnected");
  }
}