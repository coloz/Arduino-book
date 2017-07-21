/*
OpenJumper SD Module
读文件
www.openjumper.com
*/
#include <SD.h>

File myFile;

void setup(){
  //我们在2号引脚上连接一个按键模块，用以控制程序开始
  pinMode(2,INPUT_PULLUP);
  while(digitalRead(2)){}

// 初始化串口通信
  Serial.begin(9600);
  while (!Serial) {
    ; // 等待串口连接，该方法只适用于Leonardo
  }
Serial.print("Initializing SD card...");

  // Arduino上的SS引脚(UNO的10号引脚， Mega的53号引脚) 
  // 必须保持在输出模式否则SD库无法工作
  pinMode(10, OUTPUT);

  if (!SD.begin(4)) {
Serial.println("initialization failed!");
    return;
  }
Serial.println("initialization done.");

  // 打开文件，需要注意的是，一次只能打开一个文件
  // 如果你要打开另一个文件，必须先关闭之前打开的文件
  myFile = SD.open("arduino.txt");

  // 如果文件打开正常，那么开始读文件
  if (myFile) {
    Serial.println("arduino.txt:");

    // 读取文件数据，直到文件结束
    while (myFile.available()) {
	Serial.write(myFile.read());
    }
    // 关闭这个文件
    myFile.close();
} 
else {
	//如果文件没有正常打开，那么输出错误提示
Serial.println("error opening arduino.txt ");
}
}

void loop(){
	//程序只运行一次，因此loop中没有其他操作
}