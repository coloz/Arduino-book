/*
OpenJumper Examples
DHT11 Moudle
www.openjumper.com
*/
#include <dht11.h>

dht11 DHT11;

#define DHT11PIN 2

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    Serial.println("\n");
    // 读取传感器数据
    int chk = DHT11.read(DHT11PIN);
    Serial.print("Read sensor: ");
    // 检测数据是否正常接收
    switch (chk)
    {
    case DHTLIB_OK:
        Serial.println("OK");
        break;
    case DHTLIB_ERROR_CHECKSUM:
        Serial.println("Checksum error");
        break;
    case DHTLIB_ERROR_TIMEOUT:
        Serial.println("Time out error");
        break;
    default:
        Serial.println("Unknown error");
        break;
    }
    // 输出湿度与温度信息
    Serial.print("Humidity (%): ");
    Serial.println(DHT11.humidity);
    Serial.print("Temperature (oC): ");
    Serial.println(DHT11.temperature);

    delay(1000);
}