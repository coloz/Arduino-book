/*
OpenJumper Examples
从EEPROM读出float类型
奈何col  2013.2.2
www.openjumper.com
*/

#include <EEPROM.h>
union data
{
  float a;
  byte b[4];
};
data c;
int addr = 0;
int led = 13;

void setup(){
  for(int i=0;i<4;i++)
  c.b[i]=EEPROM.read(i);
  Serial.begin(9600);     
}

void loop(){
  //输出
  Serial.println(c.a);
  delay(1000);    
}