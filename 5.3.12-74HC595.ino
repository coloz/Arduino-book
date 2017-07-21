/*
使用74HC595扩展I/O
（shiftOut串行输出的使用）
*/
// ST_CP连接8号引脚
int latchPin = 8;
// SH_CP 连接12号引脚
int clockPin = 12;
// DS连接11号引脚
int dataPin = 11;

void setup() {
  //初始化模拟SPI引脚
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() 
{
  //count up routine
  for (int j = 0; j < 256; j++) 
  {
    //当你传输数据时，STCP需要保持低电平
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, j);   
// 传输完数据后，将STCP拉高
// 此时74HC595会更新并行引脚输出状态
    digitalWrite(latchPin, HIGH);
    delay(1000);
  }
}