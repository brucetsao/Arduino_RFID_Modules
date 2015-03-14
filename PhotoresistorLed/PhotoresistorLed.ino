int potpin=0;//定義模擬接口0 連接光敏電阻
int ledpin=11;//定義數字接口11 輸出PWM 調節LED 亮度
int val=0;//定義變量val
void setup()
{
pinMode(ledpin,OUTPUT);//定義數字接口11 為輸出
Serial.begin(9600);//設置波特率為9600
}
void loop()
{
val=analogRead(potpin);//讀取傳感器的模擬值並賦值給val
Serial.println(val);//顯示val 變量數值
analogWrite(ledpin,val);// 打開LED 並設置亮度（PWM 輸出最大值255）
delay(10);//延時0.01 秒
}

