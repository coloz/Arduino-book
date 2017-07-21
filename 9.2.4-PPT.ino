/*
按键对应关系：
ON> FFA25D 
OFF>FFE21D
UP> FF9867
DOWN> FFB04F
*/
#include <IRremote.h>

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup(){
  Serial.begin(9600);
  // 开始接收红外信号
  irrecv.enableIRIn(); 
}

void loop() 
{
  // 接收红外编码
  if (irrecv.decode(&results)) 
  {
    Serial.println(results.value, HEX);
    // 准备接收下一次编码
    irrecv.resume();
  }
  switch (results.value)
  {
    // 遥控器ON键>键盘F5键>开始播放
    case 0xFFA25D:
    Keyboard.press(KEY_F5);
    Keyboard.releaseAll();
    break;
    // 遥控器OFF键>键盘Esc键>退出播放
    case 0xFFE21D:
    Keyboard.press(KEY_ESC);
    Keyboard.releaseAll();
    break;
    // 遥控器向上键>键盘Esc键>退出播放
    case 0xFF9867:
    Keyboard.press(KEY_LEFT_ARROW);
    Keyboard.releaseAll();
    break;
    // 遥控器向下键>键盘Esc键>退出播放
    case 0xFFB04F:
    Keyboard.press(KEY_RIGHT_ARROW);
    Keyboard.releaseAll();
    break;
  }
  // 清空编码数据，开始下一次接收
  results.value = 0;
}