int potpin=0;//定義類比介面0
int ledpin=11;//定義數位介面11（PWM 輸出）
int val=0;// 暫存來自感測器的變數數值
void setup()
{
pinMode(ledpin,OUTPUT);//定義數位介面11 為輸出
Serial.begin(9600);//設置串列傳輸速率為9600
//注意：類比介面自動設置為輸入
}
void loop()
{
val=analogRead(potpin);// 讀取感測器的模擬值並賦值給val
Serial.println(val);//顯示val 變數
analogWrite(ledpin,val/4);// 打開LED 並設置亮度（PWM 輸__________出最大值255）
delay(10);//延時0.01 秒
}


