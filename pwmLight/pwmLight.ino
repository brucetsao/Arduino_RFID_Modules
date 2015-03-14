int val;//定義變數val
int ledpin=8 ;//定義Led pin8
int potpin=1;//定義可便電組類比介面0

void setup()
{
  Serial.begin(9600);//設置串列傳輸速率為9600
  
pinMode(ledpin,OUTPUT);
//設置數位接腳13為輸出介面，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
 val=analogRead(potpin);// 讀取感測器的模擬值並賦值給val
  Serial.println(val);//顯示val 變數
  analogWrite(ledpin,map(val,0,1023,0,255));// 打開LED 並設置亮度（PWM 輸__________出最大值255）
  delay(10);//延時0.01 秒

 
}



