/*
OpenJumper WebServer Example
显示室内照度+开关灯控制
通过手机、平板、计算机等设备访问
Arduino Server，就看到当前室内光线照度
在A0引脚连接光敏模块，用于采集室内光线；在2号引脚连接LED模块。
http://www.openjumper.com/
http://x.openjumper.com/ethernet/
*/

#include <SPI.h>
#include <Ethernet.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,177);
EthernetServer server(80);
EthernetClient client;
String readString; 
int Light=2;

void setup() {
 // 初始化串口通信
  Serial.begin(9600);
  // 初始化Ethernet通信
  Ethernet.begin(mac, ip);
  server.begin();
  pinMode(Light,OUTPUT);
  Serial.print("Server is at ");
  Serial.println(Ethernet.localIP());
}

void loop() {
  // 监听连入的客户端
  client = server.available();
  if (client) 
{
    Serial.println("new client");
    // 一次http请求结束都带有一个空行
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available())
{
        char c = client.read();
        //将收到的信息都保存在readString函数中
        readString += c;
        // if you've gotten to the end of the line (received a newline
        // character) and the line is blank, the http request has ended,
        // so you can send a reply
        if (c == '\n' && currentLineIsBlank)
{
          Serial.print(readString);
          // 发送HTML文本
          SendHTML();
          break;
        }
// 检测是否有换行符
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
// 检测是否有回车符
        else if (c != '\r') 
{
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // 等待浏览器接收数据
delay(1);

    //关闭连接
    client.stop();
Serial.println("client disonnected");

// 检查收到的信息中是否有”/?on”，有则开灯
if(readString.indexOf("/?on") >0)//checks for on
{
      digitalWrite(Light, HIGH);
      Serial.println("Led On");
}

// 检查收到的信息中是否有”/?off”，有则关灯
    if(readString.indexOf("/?off") >0)//checks for off
{
      digitalWrite(Light, LOW);    // set pin 4 low
      Serial.println("Led Off");
    }
    readString="";
  }
}

// 用于输出HTML文本的函数
void SendHTML()
{
// 发送标准的HTTP响应
client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println("Connection: close");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
client.println("<head><title>OpenJumper!</title></head>");

// 每十秒刷新一次
client.println("<meta http-equiv=\"refresh\" content=\"10\">");
  client.println("<body>");
client.println("<div align=\"center\" style=\"border-style: dotted; font-size: 36px;\">");
  client.println("<div align=\"center\">");
  client.println("<strong>OpenJumper!<br />");
  client.println("Arduino Web Server<br /></strong>");
  client.println("</div><br />");
client.println("<div style=\"font-size: 30px;\">");

//显示室内光照度
  client.println("Light intensity: ");
  // 即将A0采集到的模拟值输出
  client.println(analogRead(A0));  
  client.println("<br />"); 
  // on按钮
  client.println("<a href=\"/?on\" target=\"inlineframe\"><button>on</button></a>");
  client.println("&nbsp;");
  // off按钮
  client.println("<a href=\"/?off\" target=\"inlineframe\"><button>off</button></a>");
  client.println("<IFRAME name=inlineframe style=\"display:none\" >");          
  client.println("</IFRAME>");
  client.println("<br /> ");
  client.println("</div><br />");
  client.println("<ahref=\"http://x.openjumper.com/ethernet/\">");
client.println("<imgsrc=\"http://www.openjumper.com/ad.jpg\"></a>");
  client.println("</div><p>");
  client.println("<a href=\"http://weibo.com/coloz/\">zhou</a>@");
  client.println("<a href=\"http://www.openjumper.com/\">OpenJumper</a></p>");
  client.println("</body>");
  client.println("</html>");  
}