/*
OpenJumper Example
环境记录器
奈何col 2013.3.14
www.openjumper.com
*/

#include <SD.h>
#include <dht11.h>

dht11 DHT11;
#define DHT11_PIN 2   // DHT11引脚
#define LIGHT_PIN A0// 光敏引脚
const int chipSelect = 4;// TF卡CS选择引脚

void setup()
{
	// 初始化串口
	Serial.begin(9600);
    //将SS引脚设置为输出状态，UNO为10号引脚
	pinMode(10, OUTPUT);
	// 初始化SD卡
	Serial.println("Initializing SD card");
	if (!SD.begin(chipSelect))
	{
		Serial.println("initialization failed!");
		return;
	}
	Serial.println("initialization done.");
}

void loop()
{
	// 读取DHT11的数据
	Serial.println("Read data from DHT11");  
	DHT11.read(DHT11_PIN);

	// 读取光敏模块数据
	Serial.println("Read data from Light Sensor");  
	int light=analogRead(LIGHT_PIN);

	// 打开文件并将DHT11检测到的数据写入文件
	Serial.println("Open file and write data");  
	File dataFile = SD.open("datalog.txt", FILE_WRITE);
	if (dataFile)
	{
		dataFile.print(DHT11.humidity);
		dataFile.print(",");
		dataFile.print(DHT11.temperature);
		dataFile.print(",");
		dataFile.println(light);
		dataFile.close();
	} 
	else
	{
		Serial.println("error opening datalog.txt");
	} 

	//延时一分钟
	Serial.println("Wait for next loop"); 
	delay(60000);
}