int buzzer=8;//設置控制蜂鳴器的數位IO腳
void setup() 
{ 
  pinMode(buzzer,OUTPUT);//設置數位IO腳模式，OUTPUT為輸出 
} 
void loop() 
{ 
  unsigned char i,j;//定義變數
  while(1) 
 { 
    for(i=0;i<80;i++)//輸出一個頻率的聲音
    { 
      digitalWrite(buzzer,HIGH);//發聲音
      delay(1);//延時1ms 
      digitalWrite(buzzer,LOW);//不發聲音
      delay(1);//延時1ms 
    } 
    for(i=0;i<100;i++)//輸出另一個頻率的聲音 
    { 
      digitalWrite(buzzer,HIGH);//發聲音
      delay(2);//延時2ms 
      digitalWrite(buzzer,LOW);//不發聲音
      delay(2);//延時2ms 
    } 
  } 
}

