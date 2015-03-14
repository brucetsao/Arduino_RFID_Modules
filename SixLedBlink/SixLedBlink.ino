int BASE = 2 ;  //第一顆 LED 接的 I/O 腳
int NUM = 6;   //LED 的總數

void setup()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     pinMode(i, OUTPUT);   //設定數字I/O腳為輸出
   }
}

void loop()
{
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, LOW);    //設定數字I/O腳輸出為"低"，即逐漸關燈
     delay(200);        //延遲
   }
   for (int i = BASE; i < BASE + NUM; i ++) 
   {
     digitalWrite(i, HIGH);    //設定數字I/O腳輸出為"低"，即逐漸開燈
     delay(200);        //延遲
   }  
}

