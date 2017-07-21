/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>

int RECV_PIN = 11;// 红外一体化接收头连接到Arduino 11号引脚

IRrecv irrecv(RECV_PIN);

decode_results results;// 用于存储编码结果的对象

void setup()
{
  Serial.begin(9600);// 初始化串口通信
  irrecv.enableIRIn();// 初始化红外解码
}

void loop() {
  if (irrecv.decode(&results))
{
    Serial.println(results.value, HEX);
    irrecv.resume(); // 接收下一个编码
  }
}