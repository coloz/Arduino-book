/*
Arduino Mega端程序
串口使用情况：
Serial ------ computer
Serial1 ------ UNO SoftwareSerial
*/

void setup()
{
    // 初始化Serial，该串口用于与计算机连接通信
    Serial.begin(9600);
    // 初始化Serial1，该串口用于与设备B进行连接通信
    Serial1.begin(9600);
}

// 两个字符串分别用于存储AB两端传输来的数据
String device_A_String = "";
String device_B_String = "";

void loop()
{
    // 读取从计算机传入的数据，并通过Serial1发送给设备B
    if (Serial.available() > 0)
    {
        if (Serial.peek() != '\n')
        {
            device_A_String += (char)Serial.read();
        }
        else
        {
            Serial.read();
            Serial.print("you said: ");
            Serial.println(device_A_String);
            Serial1.println(device_A_String);
            device_A_String = "";
        }
    }

    //读取从设备B传入的数据，并在串口监视器中显示
    if (Serial1.available() > 0)
    {
        if (Serial1.peek() != '\n')
        {
            device_B_String += (char)Serial1.read();
        }
        else
        {
            Serial1.read();
            Serial.print("device B said: ");
            Serial.println(device_B_String);
            device_B_String = "";
        }
    }
}