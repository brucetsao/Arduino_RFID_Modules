int ledpin=11;//定義數字11 接口
int inpin=7;//定義數字7 接口
int val;//定義變量val
void setup()
{
pinMode(ledpin,OUTPUT);//定義小燈接口為輸出接口
pinMode(inpin,INPUT);//定義按鍵接口為輸入接口
}
void loop()
{
val=digitalRead(inpin);//讀取數字7 口電平值賦給val
if(val==LOW)//檢測按鍵是否按下，按鍵按下時小燈亮起
{ digitalWrite(ledpin,LOW);}
else
{ digitalWrite(ledpin,HIGH);}
}

