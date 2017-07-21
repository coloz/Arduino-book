/* * EEPROM Clear
* Sets all of the bytes of the EEPROM to 0.
* This example code is in the public domain.
*/

#include <EEPROM.h>

void setup()
{
  // 让EEPROM的512字节内容全部清零
  for (int i = 0; i < 512; i++)
    EEPROM.write(i, 0);

  // 清零工作完成后，将L灯点亮，提示EEPROM清零完成
  digitalWrite(13, HIGH);
}

void loop(){
}