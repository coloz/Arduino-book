/*
人体感应灯
奈何col
*/

int PIRpin=2;
int RELAYpin=3;

void setup() {
  Serial.begin(9600);
  pinMode(PIRpin,INPUT);
  pinMode(RELAYpin,OUTPUT); 
}

void loop() {
  // 等待传感器检测到人
  while(!digitalRead(PIRpin)){}
  // 将灯打开10秒，然后关闭
  Serial.println("turn on");
  digitalWrite(RELAYpin,HIGH);//继电器引脚输出高电平（打开），这个要看所使用的继电器是高电平触发还是低电平触发，如果是低电平触发的继电器需要把此处改为digitalWrite(RELAYpin,LOW)以导通继电器;
  delay(10000);  
  digitalWrite(RELAYpin,LOW);//同理,低电平触发的继电器此处应改为 digitalWrite(RELAYpin,HIGH);
  Serial.println("turn off");  
}
