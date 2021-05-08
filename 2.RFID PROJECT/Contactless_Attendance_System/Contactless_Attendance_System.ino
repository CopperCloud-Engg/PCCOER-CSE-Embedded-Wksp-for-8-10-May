#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN    9     //9          // Configurable, see typical pin layout above
#define SS_PIN     10    //10         // Configurable, see typical pin layout above
#define BUZZER_PIN     13

MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance
int statuss = 0;
int out = 0;

void setup() {
	Serial.begin(9600);		// Initialize serial communications with the PC
	//while (!Serial);		// Do nothing if no serial port is opened (added for Arduinos based on ATMEGA32U4)
	SPI.begin();			// Init SPI bus
	pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);delay(400);
	mfrc522.PCD_Init();		// Init MFRC522
	delay(4);				// Optional delay. Some board do need more time after init to be ready, see Readme
	
	//mfrc522.PCD_DumpVersionToSerial();	// Show details of PCD - MFRC522 Card Reader details
	//Serial.println(F("Scan PICC to see UID, SAK, type, and data blocks..."));
}

void loop() {
	// Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
	if ( ! mfrc522.PICC_IsNewCardPresent()) {
		return;
	}

	// Select one of the cards
	if ( ! mfrc522.PICC_ReadCardSerial()) {
		return;
	}

	// Dump debug info about the card; PICC_HaltA() is automatically called
	//mfrc522.PICC_DumpToSerial(&(mfrc522.uid));
    //Show UID on serial monitor
  Serial.println();
  Serial.print(" UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  Serial.println();
  if (content.substring(1) == "E7 1B 5C 2C") //change UID of the card that you want to give access
  {
    Serial.println(" Access Granted ");
    Serial.println(" Mr.Circuit is Present ");
    digitalWrite(BUZZER_PIN, HIGH);delay(400);
    digitalWrite(BUZZER_PIN, LOW);
    delay(1000);
    Serial.println(" Have FUN ");
    Serial.println();
    statuss = 1;
  }
  
  else   {
    Serial.println(" Access Denied ");
    delay(3000);
  }
  Serial.println(content);
  delay(1000);
}
 
