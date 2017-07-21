/*
设置DS1307的时间
RTC模块的使用
*/

//声明这个模块用到的三个类库
#include <DS1307RTC.h>
#include <Time.h>
#include <Wire.h>

const char *monthName[12] = {
    "Jan", "Feb", "Mar", "Apr", "May", "Jun",
    "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

// tmElements_t为保存日期时间的结构体类型
tmElements_t tm;

void setup()
{
    bool parse = false;
    bool config = false;

    // 获取编译时的时间和日期
    if (getDate(__DATE__) && getTime(__TIME__))
    {
        parse = true;
        // 将时间数据写入RTC模块
        if (RTC.write(tm))
        {
            config = true;
        }
    }

    Serial.begin(9600);
    delay(200);
    if (parse && config)
    {
        Serial.print("DS1307 configured Time=");
        Serial.print(__TIME__);
        Serial.print(", Date=");
        Serial.println(__DATE__);
    }
    else if (parse)
    {
        Serial.println("DS1307 Communication Error :-{");
        Serial.println("Please check your circuitry");
    }
    else
    {
        Serial.print("Could not parse info from the compiler, Time=\"");
        Serial.print(__TIME__);
        Serial.print("\", Date=\"");
        Serial.print(__DATE__);
        Serial.println("\"");
    }
}

void loop()
{
}
// 获取时间数据并存入tm
bool getTime(const char *str)
{
    int Hour, Min, Sec;

    if (sscanf(str, "%d:%d:%d", &Hour, &Min, &Sec) != 3)
        return false;
    tm.Hour = Hour;
    tm.Minute = Min;
    tm.Second = Sec;
    return true;
}
// 获取日期数据并存入tm
bool getDate(const char *str)
{
    char Month[12];
    int Day, Year;
    uint8_t monthIndex;

    if (sscanf(str, "%s %d %d", Month, &Day, &Year) != 3)
        return false;
    for (monthIndex = 0; monthIndex < 12; monthIndex++)
    {
        if (strcmp(Month, monthName[monthIndex]) == 0)
            break;
    }
    if (monthIndex >= 12)
        return false;
    tm.Day = Day;
    tm.Month = monthIndex + 1;
    tm.Year = CalendarYrToTm(Year);
    return true;
}