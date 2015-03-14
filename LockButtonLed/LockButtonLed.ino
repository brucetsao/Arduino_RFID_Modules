int redled=8;     //紅色LED 輸出
int yellowled=7;  //黃色LED輸出
int greenled=6;   //綠色LED輸出
int redpin=5;     //紅色按鍵引腳
int yellowpin=4;  //黃色按鍵引腳
int greenpin=3;   //綠色按鍵引腳
int restpin=2;   //復位按鍵引腳定義
int red;
int yellow;
int green;
void setup()
{
pinMode(redled,OUTPUT);
pinMode(yellowled,OUTPUT);
pinMode(greenled,OUTPUT);
pinMode(redpin,INPUT);
pinMode(yellowpin,INPUT);
pinMode(greenpin,INPUT);
}
void loop()  //按鍵循環掃瞄。
{
red=digitalRead(redpin);
yellow=digitalRead(yellowpin);
green=digitalRead(greenpin);
if(red==LOW)RED_YES();    
if(yellow==LOW)YELLOW_YES();
if(green==LOW)GREEN_YES();
}

void RED_YES()//一直執行紅燈亮，直到復位鍵按下，結束循環
{
  while(digitalRead(restpin)==1)
  {
   digitalWrite(redled,HIGH);
   digitalWrite(greenled,LOW);
   digitalWrite(yellowled,LOW);
  }
  clear_led();
}
void YELLOW_YES()//一直執行黃燈亮，直到復位鍵按下，結束循環
{
  while(digitalRead(restpin)==1)
  {
  digitalWrite(redled,LOW);
  digitalWrite(greenled,LOW);
  digitalWrite(yellowled,HIGH);
  }
  clear_led();
}
void GREEN_YES()//一直執行綠燈亮，直到復位鍵按下，結束循環
{
  while(digitalRead(restpin)==1)
  {
  digitalWrite(redled,LOW);
  digitalWrite(greenled,HIGH);
  digitalWrite(yellowled,LOW);
  }
  clear_led();
}
void clear_led()//清除LED
{
  digitalWrite(redled,LOW);
  digitalWrite(greenled,LOW);
  digitalWrite(yellowled,LOW);
}

