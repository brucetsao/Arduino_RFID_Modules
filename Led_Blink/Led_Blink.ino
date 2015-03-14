int ledPin = 10; //定義數字10 接口
void setup()
{
pinMode(ledPin, OUTPUT);//定義小燈接口為輸出接口
}
void loop()
{
digitalWrite(ledPin, HIGH); //點亮小燈
delay(1000); //延時1 秒
digitalWrite(ledPin, LOW); //熄滅小燈
delay(1000); // 延時1 秒
}

