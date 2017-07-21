/*
  Keyboard logout

 This sketch demonstrates the Keyboard library.

 When you connect pin 2 to ground, it performs a logout.  
 It uses keyboard combinations to do this, as follows:

 On Windows, CTRL-ALT-DEL followed by ALT-l
 On Ubuntu, CTRL-ALT-DEL, and ENTER
 On OSX, CMD-SHIFT-q

 To wake: Spacebar. 

 Circuit:
 * Arduino Leonardo or Micro
 * wire to connect D2 to ground.

 created 6 Mar 2012
 modified 27 Mar 2012
 by Tom Igoe

 This example is in the public domain

 http://www.arduino.cc/en/Tutorial/KeyboardLogout
 */

#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

//设置你的操作系统
int platform = WINDOWS;

void setup() {
  // 将2号引脚设置为输入状态
//并开启内部上拉电阻
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  while (digitalRead(2) == HIGH) {
    // 等待2号引脚变成低电平
    delay(500);
  }
  delay(1000);

  switch (platform) {
  case OSX:
   Keyboard.press(KEY_LEFT_GUI);
   // Shift+Q组合按键
   Keyboard.press(KEY_LEFT_SHIFT); 
   Keyboard.press('Q');
    delay(100);
    Keyboard.releaseAll();
     //回车确认:
    Keyboard.write(KEY_RETURN);  
    break;
  case WINDOWS:
    // CTRL+ALT+DEL组合按键
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(100);
    Keyboard.releaseAll();
    //ALT+L组合按键:
    delay(2000);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press('l');
    Keyboard.releaseAll();
    break;
  case UBUNTU:
    // CTRL+ALT+DEL组合按键
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_DELETE);
    delay(1000);
    Keyboard.releaseAll();
    // 回车键确认登出
    Keyboard.write(KEY_RETURN);
    break;
  }
// 进入死循环，相当于结束程序
  while(true);
}