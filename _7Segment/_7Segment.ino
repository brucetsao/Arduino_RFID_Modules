// 七段顯示器製作倒數功能 (vturnon)
#define apin 22
#define bpin 24
#define cpin 26
#define dpin 28
#define epin 30
#define fpin 32
#define gpin 34
#define dotpin 36
#define turnon LOW
#define turnoff HIGH


void setup() {               
  pinMode(apin, OUTPUT);  
  pinMode(bpin, OUTPUT);
  pinMode(cpin, OUTPUT);
  pinMode(dpin, OUTPUT);
  pinMode(epin, OUTPUT);
  pinMode(fpin, OUTPUT);
  pinMode(gpin, OUTPUT);
  pinMode(dotpin, OUTPUT);
  digitalWrite(dotpin, turnoff);  // 關閉小數點
}

void loop() {
  // 顯示數字 '9'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnoff);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '8'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnon);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '7'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnoff);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnoff);
  digitalWrite(gpin, turnoff);
  delay(1000);
  // 顯示數字 '6'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnoff);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnon);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '5'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnoff);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '4'
  digitalWrite(apin, turnoff);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnoff);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '3'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnoff);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '2'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnoff);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnon);
  digitalWrite(fpin, turnoff);
  digitalWrite(gpin, turnon);
  delay(1000);
  // 顯示數字 '1'
  digitalWrite(apin, turnoff);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnoff);
  digitalWrite(epin, turnoff);
  digitalWrite(fpin, turnoff);
  digitalWrite(gpin, turnoff);
  delay(1000);
  // 顯示數字 '0'
  digitalWrite(apin, turnon);
  digitalWrite(bpin, turnon);
  digitalWrite(cpin, turnon);
  digitalWrite(dpin, turnon);
  digitalWrite(epin, turnon);
  digitalWrite(fpin, turnon);
  digitalWrite(gpin, turnoff);  
  // 暫停 4 秒鐘
  delay(4000);
}
 
