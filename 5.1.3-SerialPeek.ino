//peek函数读取串口数据

char col;
void setup()
{
    Serial.begin(9600);
}

void loop()
{
    while (Serial.available() > 0)
    {
        col = Serial.peek();
        Serial.print("Read: ");
        Serial.println(col);
        delay(1000);
    }
}