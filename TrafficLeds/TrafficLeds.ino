int redled =10; //定義數字10 接口
int yellowled =7; //定義數字7 接口
int greenled =4; //定義數字4 接口
void setup()
{
pinMode(redled, OUTPUT);//定義紅色Led接口為輸出接口
pinMode(yellowled, OUTPUT); //定義黃色Led接口為輸出接口
pinMode(greenled, OUTPUT); //定義綠色Led接口為輸出接口
}
void loop()
{
digitalWrite(greenled, HIGH);////點亮 綠燈
delay(5000);//延時5秒
digitalWrite(greenled, LOW); //熄滅 綠燈
for(int i=0;i<3;i++)//閃爍交替三次，黃燈閃爍效果
{
delay(500);//延時0.5 秒 
digitalWrite(yellowled, HIGH);//點亮  黃燈
delay(500);//延時0.5 秒
digitalWrite(yellowled, LOW);//熄滅  黃燈
} 
delay(500);//延時0.5 秒
digitalWrite(redled, HIGH);//點亮 紅燈
delay(5000);//延時5 秒
digitalWrite(redled, LOW);//熄滅 紅燈
}

