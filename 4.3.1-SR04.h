R04.hArduino

//2012-4-27 奈何col From OpenJumper.com
#ifndef SR04_H
#define SR04_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

	class SR04
{
  public:
	SR04(int TrigPin, int EchoPin);
	float Get();

  private:
	int Trig_pin;
	int Echo_pin;
	float distance;
};
#endif
