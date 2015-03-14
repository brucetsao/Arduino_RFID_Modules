// 七段顯示器製作倒數功能 (vturnon)
#define ctlD1 7
#define ctlD2 6

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
#define digitalon HIGH
#define digitaloff LOW

void setup() {               
  pinMode(ctlD1, OUTPUT);  
  pinMode(ctlD2, OUTPUT);  
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
     int i ;
  for (i=0 ; i<99; i++)
         {
          showNumber(i) ;
         delay(50) ; 
         showNumber(-1) ;  

       } 
}
 
 void showNumber(int no)
 {
    if (no == -1)
   {
       ShowSegment(1, -1) ;
   }
   else
   {
      ShowSegment(1, (no/10)) ;
      delayMicroseconds(3000) ;
      ShowSegment(2, (no%10)) ;
      delayMicroseconds(3000) ;
   }
 }
 void ShowSegment(int digital, int number)
 {
     if (digital == 1)
         {
            digitalWrite(ctlD1, digitalon);
            digitalWrite(ctlD2, digitaloff);
         }
         else
         {
            digitalWrite(ctlD1, digitaloff);
            digitalWrite(ctlD2, digitalon);
         }
         
            
    switch (number)
      {
        case 9:
                 // 顯示數字 '9'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnoff);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnon);
           break ;
           
           case 8:
          // 顯示數字 '8'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnon);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnon);
          break ;
          
          case 7:
          // 顯示數字 '7'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnoff);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnoff);
          digitalWrite(gpin, turnoff);
          break ;
          
          case 6:
          // 顯示數字 '6'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnoff);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnon);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnon);
          break ;
          
          case 5:
          // 顯示數字 '5'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnoff);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnon);
          break ;
          
          case 4:
          // 顯示數字 '4'
          digitalWrite(apin, turnoff);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnoff);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnon);
          break ;
          
          case 3:
          // 顯示數字 '3'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnoff);
          digitalWrite(gpin, turnon);
          break ;
         
           case 2: 
          // 顯示數字 '2'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnoff);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnon);
          digitalWrite(fpin, turnoff);
          digitalWrite(gpin, turnon);
          break ;
          
          case 1:
          // 顯示數字 '1'
          digitalWrite(apin, turnoff);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnoff);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnoff);
          digitalWrite(gpin, turnoff);
          break ;
          
          case 0:
          // 顯示數字 '0'
          digitalWrite(apin, turnon);
          digitalWrite(bpin, turnon);
          digitalWrite(cpin, turnon);
          digitalWrite(dpin, turnon);
          digitalWrite(epin, turnon);
          digitalWrite(fpin, turnon);
          digitalWrite(gpin, turnoff);  
           break ;

          case -1:
          // all Off
          digitalWrite(apin, turnoff);
          digitalWrite(bpin, turnoff);
          digitalWrite(cpin, turnoff);
          digitalWrite(dpin, turnoff);
          digitalWrite(epin, turnoff);
          digitalWrite(fpin, turnoff);
          digitalWrite(gpin, turnoff);  
           break ;

      } 
 }
