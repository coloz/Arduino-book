/*
OpenJumper Leonardo Example
使用摇杆扩展板模拟USB鼠标
http://www.openjumper.com/
http://x.openjumper.com/joystick-shield/
*/

//摇杆硬件定义
int enableButton = 7;    // 摇杆按键，用作鼠标功能使能按键
int upButton = 6;       // 上方按键，模拟滚轮向上
int downButton = 3;     // 下方按键，模拟滚轮向下
int leftButton = 5;       // 左按键，模拟鼠标左键
int rightButton = 4;      // 右按键，模拟鼠标右键
int xAxis = A1;         // 遥感X轴
int yAxis = A0;         // 遥感Y轴

int mouseSensitivity = 12; //鼠标灵敏度
int wheelSensitivity = 1;  //滚轮灵敏度

boolean enable = false;  //模拟鼠标功能是否可用
boolean lastEnableButtonState = HIGH;  // 上一次使能按键读值

void setup() {
  //初始化各个按键
  pinMode(enableButton,INPUT);
  pinMode(upButton,INPUT);
  pinMode(downButton,INPUT);
  pinMode(leftButton,INPUT);
  pinMode(rightButton,INPUT);
  // 开始控制鼠标
  Mouse.begin();
}

void loop() {
  // 使能按键按一次使能，再按一次不使能
  boolean EnableButtonState = digitalRead(enableButton);
  if( (EnableButtonState == LOW) && (EnableButtonState != lastEnableButtonState) ) {
    enable=!enable; 
  }
lastEnableButtonState=EnableButtonState;

  if (enable) {
    // 读取鼠标偏移值
    int x = readAxis(xAxis);
    int y = readAxis(yAxis);
// 读取鼠标滚轮值
    int wheel=0;
    if(digitalRead(upButton)==LOW){
      wheel=wheelSensitivity;
    }
    else if(digitalRead(downButton)==LOW){
      wheel=-wheelSensitivity;
}
// 移动鼠标位置或滚轮
    Mouse.move(x, y, wheel);
    //点击鼠标左右键
ifClickButton(leftButton,MOUSE_LEFT);  
ifClickButton(rightButton,MOUSE_RIGHT); 
// 延时一段时间，可以通过该值调整鼠标移动速度
    delay(10);
  }
}
//读取摇杆数据
// 即摇杆电位器的偏移量
int readAxis(int thisAxis) { 
  int reading = analogRead(thisAxis);
  // 将读出的模拟值，缩小到一定范围
  reading = map(reading, 0, 1023, 0, mouseSensitivity);
  // 计算出一个鼠标偏移量
  int distance = reading - (mouseSensitivity/2);
  int threshold = mouseSensitivity/4;
//如果电位器偏移量较小则不移动鼠标
if (abs(distance) < threshold) {
    distance = 0;
  } 
  // 返回鼠标偏移量
  return distance;
}
//判断按键是否被按下
void ifClickButton(int Buttonpin,uint8_t Button) {
  if (digitalRead(Buttonpin) == LOW){
    if (!Mouse.isPressed(Button)) {
      Mouse.press(Button); 
    }
  }
  else 
    if (Mouse.isPressed(Button)) {
      Mouse.release(Button);
    }
}