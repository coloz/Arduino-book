/*
OpenJumper ChatServer Example
http://www.openjumper.com/
http://x.openjumper.com/ethernet/

*/

#include <SPI.h>
#include <Ethernet.h>

// 输入MAC地址和IP地址，此后的设置将会用到
// IP地址需要根据你的本地网络设置
// 网关和子网掩码是可选项，可以不用
byte mac[] = {
    0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(192, 168, 1, 177);

// telnet 默认端口为23
EthernetServer server(23);
boolean alreadyConnected = false; // 记录是否之前有客户端被连接
String thisString = "";

void setup()
{
    // 初始化网络设备
    Ethernet.begin(mac, ip);
    // 开始监听客户端
    server.begin();
    // 初始化串口
    Serial.begin(9600);
    // 串口输出提示信息
    Serial.print("Chat server address:");
    Serial.println(Ethernet.localIP());
}

void loop()
{
    // 等待一个新的客户端连接
    EthernetClient client = server.available();
    // 当服务器第一次发送数据时，发送一个hello回应
    if (client)
    {
        if (!alreadyConnected)
        {
            // 清除输入缓冲区
            client.flush();
            Serial.println("We have a new client");
            client.println("Hello, client!");
            alreadyConnected = true;
        }

        if (client.available() > 0)
        {
            // 读取从客户端发来的数据
            char thisChar = client.read();
            thisString += thisChar;
            // 检测到结束符，便输出字符串
            if (thisChar == '\n')
            {
                server.println(thisString);
                Serial.println(thisString);
                thisString = "";
            }
        }
    }
}