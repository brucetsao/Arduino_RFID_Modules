int buzzer = 9; //定義蜂鳴器的輸出引腳為9
int R_guangming = 0;//定義光敏電阻的輸入引腳
int val;	
void setup() 
{ 
pinMode(buzzer,OUTPUT);//設置連接蜂鳴器的引腳為輸出
} 
void voice_out(int del)//聲音的頻率控制函數
{
 delay(del);//通過改變延時來改變頻率，很簡單
 digitalWrite(buzzer,HIGH);
 delay(del);
 digitalWrite(buzzer,LOW);
}
void loop() 
{ 
  val=analogRead(R_guangming);  //讀取模擬接口0 的值，並將其賦給val
  if(val<700)
   {
    voice_out(val); //把讀到的val值傳給頻率控制函數
   }
}

