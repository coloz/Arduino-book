//read函数读取串口数据
char col;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)
    {
        col = Serial.read();
        Serial.print("Read: ");
        Serial.println(col);
        delay(1000);
    }
}