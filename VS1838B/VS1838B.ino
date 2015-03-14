//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "buttoncode.h"
#include <IRremote.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

int RECV_PIN = 2 ;
IRrecv irrecv(RECV_PIN);
decode_results results;


void setup()
{
  lcd.init();                      // initialize the lcd

  // Print a message to the LCD.
  lcd.backlight();
  lcd.print("Hello, world!");
  Serial.begin(9600);

  irrecv.enableIRIn(); 


}

void loop()
{
  // 將游標設到 　第一行, 　第二列
  // (注意: 　第二列第五行，因為是從 0 開始數起):
  lcd.setCursor(5, 1);
  
if (irrecv.decode(&results)) 
  {
   if (results.value == CH1) 
       {
           Serial.println("CH-"); 
       }

     if (results.value == CH) 
       {
         Serial.println("CH"); 
         }

       if (results.value == CH2) 
       {
           Serial.println("CH+"); 
       }

     if (results.value == PREV) 
       {
           Serial.println("PREV");
       }

     if (results.value == NEXT) 
       {
         Serial.println("NEXT");
         }

     if (results.value == PLAYPAUSE) 
       {
           Serial.println("PLAY/PAUSE");
       }

     if (results.value == VOL1) 
         {
             Serial.println("VOL-");
         }

     if (results.value == VOL2) 
       {
         Serial.println("VOL+");
       }

     if (results.value == EQ) 
       {
           Serial.println("EQ"); 
       }

     if (results.value == BUTON0) 
       {
           Serial.println("BUTON0"); 
         }

     if (results.value == BUTON100) 
         {
             Serial.println("BUTON100+"); 
         }

     if (results.value == BUTON200) 
         {
             Serial.println("BUTON200+"); 
         }

       if (results.value == BUTON1) 
         {
             Serial.println("BUTON1"); 
         }

       if (results.value == BUTON2) 
           {
               Serial.println("BUTON2"); 
           }

       if (results.value == BUTON3) 
           {
               Serial.println("BUTON3"); 
             }

         if (results.value == BUTON4) 
             {
                 Serial.println("BUTON4"); 
             }

         if (results.value == BUTON5) 
             {
               Serial.println("BUTON5"); 
             }

         if (results.value == BUTON6) 
             {
                 Serial.println("BUTON6"); 
             }

         if (results.value == BUTON7) 
             {
               Serial.println("BUTON7"); 
             }

         if (results.value == BUTON8) 
             {
                 Serial.println("BUTON8"); 
             }
            if (results.value == BUTON9) 
               {
                     Serial.println("BUTON9"); 
                 }
         irrecv.resume();
       }

    }

