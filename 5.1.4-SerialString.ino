//Read String

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    String inString = "";
    while (Serial.available() > 0)
    {
        char inChar = Serial.read();
        inString += (char)inChar;
        //延时函数用于等待输入字符完全进去接收缓冲区
        delay(10);
    }
    // 检查是否接收到数据，如果接收到，便输出该数据
    if (inString != "")
    {
        Serial.print("Input String: ");
        Serial.println(inString);
    }
}