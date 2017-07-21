/*
Melody

Plays a melody 
This example code is in the public domain.
http://arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// 记录曲子的音符
int melody[] = {
    NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};

// 音符持续时间  4为四分音符， 8为八分音符
int noteDurations[] = {
    4, 8, 8, 4, 4, 4, 4, 4};

void setup()
{
  // 遍历整个曲子的音符
  for (int thisNote = 0; thisNote < 8; thisNote++)
  {

    // noteDurations[]数组中存储的是音符的类型
    // 我们需要将其换算为音符持续时间，方法如下：
    // 音符持续时间=1000ms / 音符类型
    //例如，四分音符=1000 / 4，8分音符 = 1000/8
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // 为了能辨别出不同的音调，你需要在两个音调间设置一定的延时
    // 增加30%延时时间是比较合适的
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // 停止发声
    noTone(8);
  }
}

void loop()
{
  // 程序并不重复，因此这里为空
}