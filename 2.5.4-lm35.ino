/*
项目：LM35电子温度计
 */

int LM35 = A0;
void setup() 
{
  // 初始化串口通信
  Serial.begin(9600); 
}

void loop() 
{
  // 读取传感器模拟值，并计算出当前温度
  float temp = (5.0 * analogRead(LM35) * 100.0) / 1024;
  // 将温度输出至串口显示
  Serial.print("temperature   " );                       
  Serial.print(temp);           
  Serial.println("C");   
  delay(1000);                     
}