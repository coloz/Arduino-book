float distance;

void setup()
{
	Set_SR04(2, 3);
	Serial.begin(9600);
}

void loop()
{
	distance = Get_SR04(2, 3);
	Serial.print(distance);
	Serial.print("cm");
	Serial.println();
	delay(1000);
}

void Set_SR04(int TrigPin, int EchoPin)
{
	pinMode(TrigPin, OUTPUT);
	pinMode(EchoPin, INPUT);
}

float Get_SR04(int TrigPin, int EchoPin)
{
	digitalWrite(TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(TrigPin, LOW);
	float distance = pulseIn(EchoPin, HIGH) / 58.0;
	return distance;
}