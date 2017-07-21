/*
获取原始红外信号
OpenJumper38K红外一体化接收模块
2013.4.24奈何col
*/

#include <IRremote.h>

int RECV_PIN = 11; //红外接收模块连接在11脚
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();
}

void loop()
{
    if (irrecv.decode(&results))
    {
        dump(&results);
        irrecv.resume();
    }
}

void dump(decode_results *results)
{
    int count = results->rawlen;
    Serial.print("Raw (");
    Serial.print(count);
    Serial.print("): ");

    for (int i = 0; i < count; i++)
    {
        Serial.print(results->rawbuf[i] * USECPERTICK);
        Serial.print(",");
    }
    Serial.println();
}