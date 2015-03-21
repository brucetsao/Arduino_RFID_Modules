/*
 * Sample program showing how to read data from a PICC using a MFRC522 reader on the Arduino SPI interface.
 *----------------------------------------------------------------------------- empty_skull 
 * Aggiunti pin per arduino Mega
 * add pin configuration for arduino mega
 * http://mac86project.altervista.org/
 ----------------------------------------------------------------------------- Nicola Coppola
 * Pin layout should be as follows:
 * Signal     Pin              Pin               Pin
 *            Arduino Uno      Arduino Mega      MFRC522 board
 * ------------------------------------------------------------
 * Reset      9                5                 RST
 * SPI SS     10               53                SDA
 * SPI MOSI   11               51                MOSI
 * SPI MISO   12               50                MISO
 * SPI SCK    13               52                SCK
 *
 * The reader can be found on eBay for around 5 dollars. Search for "mf-rc522" on ebay.com. 
 */

#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);	// Create MFRC522 instance.
int RFIDIntrupNumber = 1;

void setup() {
    attachInterrupt(RFIDIntrupNumber, ReadRfidDump, CHANGE);
	Serial.begin(9600);	// Initialize serial communications with the PC
	SPI.begin();			// Init SPI bus
	mfrc522.PCD_Init();	// Init MFRC522 card
	Serial.println("Scan PICC to see UID and type...");
}

void loop() {
	// Look for new cards
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards

}

void ReadRfidDump()
{
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card. PICC_HaltA() is automatically called.
	mfrc522.PICC_DumpToSerial(&(mfrc522.uid));  
}

void ReadRfidID()
{
    if (rfid.isCard()) 
    {                                     //找尋卡片
          if (rfid.readCardSerial()) 
          {                       //取得卡片的ID+CRC校驗碼
                        //第0~3個byte:卡片ID
                        Serial.println(" ");
                        Serial.print("RFID Card Number is : ");
			Serial.print(rfid.serNum[0],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[1],HEX);
                        Serial.print(" , ");
			Serial.print(rfid.serNum[2],HEX);
                        Serial.print(" , ");
			Serial.println(rfid.serNum[3],HEX);
                        //第4個byte:CRC校驗位元
                        Serial.print("CRC is : ");
                        Serial.println(rfid.serNum[4],HEX);
          }
          
    }   
    rfid.halt();        //命令卡片進入休眠狀態
  //  delay(500);         //延時0.5秒 
}

