int val;//定義變數val
int ledpin=8 ;//定義Led pin8
int potpin=1;//定義可便電組類比介面0

void setup()
{
pinMode(ledpin,OUTPUT);
//設置數位接腳13為輸出介面，Arduino 上我們用到的I/O 口都要進行類似這樣的定義。
}
void loop()
{
 digitalWrite( ledpin,HIGH) ;
 delay(200);
 digitalWrite( ledpin,LOW) ;
 delay(400);
 
 
}



