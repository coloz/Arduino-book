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
  digitalWrite(RELAYpin,HIGH);
  delay(10000);  
  digitalWrite(RELAYpin,LOW);
  Serial.println("turn off");  
}