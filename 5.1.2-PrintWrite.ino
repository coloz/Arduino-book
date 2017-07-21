/*
串口的高级用法
Print和write的使用
Arduino.cn
*/

float FLOAT = 1.23456;
int INT = 123;
byte BYTE[6] = {48, 49, 50, 51, 52, 53};

void setup()
{
    Serial.begin(9600);
    //Print的各种输出形式
    Serial.println("Serial Print:");
    Serial.println(INT);
    Serial.println(INT, BIN);
    Serial.println(INT, OCT);
    Serial.println(INT, DEC);
    Serial.println(INT, HEX);
    Serial.println(FLOAT);
    Serial.println(FLOAT, 0);
    Serial.println(FLOAT, 2);
    Serial.println(FLOAT, 4);

    //Write的各种输出形式
    Serial.println();
    Serial.println("Serial Write:");
    Serial.write(INT);
    Serial.println();
    Serial.write("Serial");
    Serial.println();
    Serial.write(BYTE, 6);
}

void loop()
{
}