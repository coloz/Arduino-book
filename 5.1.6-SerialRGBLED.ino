/*
OpenJumper Example
串口RGB LED调光
奈何col  2013.2.20
www.openjumper.com
*/

int i;                          //保存PWM需要输出的值
String inString = "";           // 输入的字符串
char LED = ' ';                 // 用于判断指定LED颜色对应的引脚
boolean stringComplete = false; // 用于判断数据是否读取完成

void setup()
{
    //初始化串口
    Serial.begin(9600);
}
void loop()
{
    if (stringComplete)
    {
        if (LED == 'A')
        {
            analogWrite(9, i);
        }
        else if (LED == 'B')
        {
            analogWrite(10, i);
        }
        else if (LED == 'C')
        {
            analogWrite(11, i);
        }
        // 清空数据，为下一次读取做准备
        stringComplete = false;
        inString = "";
        LED = ' ';
    }
}

//使用串口事件
// 读取并分离字母和数字
void serialEvent()
{
    while (Serial.available())
    {
        // 读取新的字符
        char inChar = Serial.read();
        //根据输入数据分类
        // 如果是数字，则存储到变量inString中
        // 如果是英文字符，则存储到变量LED中
        // 如果是结束符“\n”，则结束读取，并将inString转换为int
        if (isDigit(inChar))
        {
            inString += inChar;
        }
        else if (inChar == '\n')
        {
            stringComplete = true;
            i = inString.toInt();
        }
        else
            LED = inChar;
    }
}