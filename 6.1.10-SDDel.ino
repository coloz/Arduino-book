/*
OpenJumper SD Module 
删除文件
www.openjumper.com
*/
#include <SD.h>

File myFile;

void setup()
{
    //我们在2号引脚上连接一个按键模块，用以控制程序开始
    pinMode(2, INPUT_PULLUP);
    while (digitalRead(2))
    {
    }

    // 初始化串口通信
    Serial.begin(9600);
    Serial.print("Initializing SD card...");

    // Arduino上的SS引脚(UNO的10号引脚， Mega的53号引脚)
    // 必须保持在输出模式否则SD库无法工作
    pinMode(10, OUTPUT);
    if (!SD.begin(4))
    {
        Serial.println("initialization failed!");
        return;
    }
    Serial.println("initialization done.");

    if (SD.exists("arduino.txt"))
    {
        Serial.println("arduino.txt exists.");
    }
    else
    {
        Serial.println("arduino.txt doesn't exist.");
    }

    // 删除文件
    Serial.println("Removing arduino.txt...");
    SD.remove("arduino.txt");

    // 检查文件是否存在
    if (SD.exists("arduino.txt"))
    {
        Serial.println("arduino.txt exists.");
    }
    else
    {
        Serial.println("arduino.txt doesn't exist.");
    }
}

void loop()
{
    // 该程序只运行一次，所以在loop中没有其他操作
}