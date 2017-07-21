//2012-4-27 奈何col From OpenJumper.com
#include "SR04.h"
SR04 sr04 = SR04(2, 3);
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  float distance = sr04.Get();
  Serial.print(distance);
  Serial.print("cm");
  Serial.println();
}