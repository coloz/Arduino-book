/*
Arduino UNO端程序
串口使用情况：
Serial ------ computer
softSerial ------ Mega Serial1
*/

#include <SoftwareSerial.h>
//新建一个softSerial对象，RX:10，TX:11
SoftwareSerial softSerial(10, 11);

void setup()
{
    //初始化串口通信
    Serial.begin(9600);
    //初始化软串口通信
    softSerial.begin(9600);
    // 监听软串口通信
    softSerial.listen();
}

// 两个字符串分别用于存储AB两端传输来的数据
String device_B_String = "";
String device_A_String = "";

void loop()
{
    // 读取从计算机传入的数据，并通过softSerial发送给设备B
    if (Serial.available() > 0)
    {
        if (Serial.peek() != '\n')
        {
            device_B_String += (char)Serial.read();
        }
        else
        {
            Serial.read();
            Serial.print("you said: ");
            Serial.println(device_B_String);
            softSerial.println(device_B_String);
            device_B_String = "";
        }
    }
    //读取从设备A传入的数据，并在串口监视器中显示
    if (softSerial.available() > 0)
    {
        if (softSerial.peek() != '\n')
        {
            device_A_String += (char)softSerial.read();
        }
        else
        {
            softSerial.read();
            Serial.print("device A said: ");
            Serial.println(device_A_String);
            device_A_String = "";
        }
    }
}