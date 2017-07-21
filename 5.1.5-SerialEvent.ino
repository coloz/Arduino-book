/*
  Serial Event example

 When new serial data arrives, this sketch adds it to a String.
 When a newline is received, the loop prints the string and 
clears it.

 This example code is in the public domain.
 http://www.arduino.cc/en/Tutorial/SerialEvent
*/

String inputString = "";        // 用于保存输入数据的字符串
boolean stringComplete = false; // 字符串是否已接收完全

void setup()
{
    // 初始化串口
    Serial.begin(9600);
    // 设置字符串存储量为200个字节
    inputString.reserve(200);
}

void loop()
{
    // 当收到新的一行字符串时，输出这个字符串
    if (stringComplete)
    {
        Serial.println(inputString);
        // 清空字符串
        inputString = "";
        stringComplete = false;
    }
}

/*
当一个新的数据被串口接收到时会触发SerialEvent事件
  SerialEvent函数中的程序会在两次loop()之间运行
因此，如果你loop中有延时程序，会延迟该事件的响应。
造成数个字节的数据都可以被接收。
*/
void serialEvent()
{
    while (Serial.available())
    {
        // 读取新的字节
        char inChar = (char)Serial.read();
        // 将新读取到的字节添加到inputString字符串中
        inputString += inChar;
        // 如果收到换行符，则设置一个标记
        // 再在loop()中检查这个标记，用以执行相关操作
        if (inChar == '\n')
        {
            stringComplete = true;
        }
    }
}