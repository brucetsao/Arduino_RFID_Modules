int DI = 8; 
int RW = 9; 
int DB[] = { 45, 43, 41,39,37,35,33,31};//使用数组来定义总线需要的管脚 
int Enable = 10; 
  void LcdCommandWrite(int value) { 
// 定义所有引脚 
int i = 0; 
for (i=DB[0]; i <= DI; i++) //总线赋值 
{ 
digitalWrite(i,value & 01);//因为1602液晶信号识别是D7-D0(不是D0-D7)，这里是用来反转信号。 
value >>= 1; 
} 
digitalWrite(Enable,LOW); 
delayMicroseconds(1); 
digitalWrite(Enable,HIGH); 
delayMicroseconds(1); // 延时1ms 
digitalWrite(Enable,LOW); 
delayMicroseconds(1); // 延时1ms 
} 
  void LcdDataWrite(int value) { 
// 定义所有引脚 
int i = 0; 
digitalWrite(DI, HIGH); 
digitalWrite(RW, LOW); 
for (i=DB[0]; i <= DB[7]; i++) { 
digitalWrite(i,value & 01); 
value >>= 1; 
} 
digitalWrite(Enable,LOW); 
delayMicroseconds(1); 
digitalWrite(Enable,HIGH); 
delayMicroseconds(1); 
digitalWrite(Enable,LOW); 
delayMicroseconds(1); // 延时1ms 
} 
  
void setup (void) { 
int i = 0; 
for (i=Enable; i <= DI; i++) { 
pinMode(i,OUTPUT); 
} 
delay(100); 
// 短暂的停顿后初始化LCD 
// 用于LCD控制需要 
LcdCommandWrite(0x38); // 设置为8-bit接口，2行显示，5x7文字大小 
delay(64); 
LcdCommandWrite(0x38); // 设置为8-bit接口，2行显示，5x7文字大小 
delay(50); 
LcdCommandWrite(0x38); // 设置为8-bit接口，2行显示，5x7文字大小 
delay(20); 
LcdCommandWrite(0x06); // 输入方式设定 
// 自动增量，没有显示移位 
delay(20); 
LcdCommandWrite(0x0E); // 显示设置 
// 开启显示屏，光标显示，无闪烁 
delay(20); 
LcdCommandWrite(0x01); // 屏幕清空，光标位置归零 
delay(100); 
LcdCommandWrite(0x80); // 显示设置 
// 开启显示屏，光标显示，无闪烁 
delay(20); 
} 
  void loop (void) { 
LcdCommandWrite(0x01); // 屏幕清空，光标位置归零 
delay(10); 
LcdCommandWrite(0x80+3); 
delay(10); 
// 写入欢迎信息 
LcdDataWrite('W'); 
LcdDataWrite('e'); 
LcdDataWrite('l'); 
LcdDataWrite('c'); 
LcdDataWrite('o'); 
LcdDataWrite('m'); 
LcdDataWrite('e'); 
LcdDataWrite(' '); 
LcdDataWrite('t'); 
LcdDataWrite('o'); 
delay(10); 
LcdCommandWrite(0xc0+1); // 定义光标位置为第二行第二个位置 
delay(10); 
LcdDataWrite('Y'); 
LcdDataWrite('i'); 
LcdDataWrite('x'); 
LcdDataWrite('f'); 
LcdDataWrite('o'); 
LcdDataWrite('n'); 
LcdDataWrite('g'); 
LcdDataWrite('-'); 
LcdDataWrite('a'); 
LcdDataWrite('r'); 
LcdDataWrite('d'); 
LcdDataWrite('u'); 
LcdDataWrite('i'); 
LcdDataWrite('n'); 
LcdDataWrite('o'); 
delay(5000); 
LcdCommandWrite(0x01); // 屏幕清空，光标位置归零 
delay(10); 
LcdDataWrite('Q'); 
LcdDataWrite('Q'); 
LcdDataWrite(':');
LcdDataWrite('1'); 
LcdDataWrite('6'); 
LcdDataWrite('5'); 
LcdDataWrite('6'); 
LcdDataWrite('3'); 
LcdDataWrite('8'); 
LcdDataWrite('3'); 
LcdDataWrite('9'); 
LcdDataWrite('0');
LcdDataWrite('4');
delay(3000); 
} 

