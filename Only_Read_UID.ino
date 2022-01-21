#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);  // Create MFRC522 instance.

int readsuccess;
byte readcard[6];
char str[32] = "";
String StrUID;

void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  SPI.begin();      // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  Serial.println("CLEARDATA");
  Serial.println("LABEL,Date,Time,RFID UID");
  delay(1000);
  
  Serial.println("Scan PICC to see UID...");
  Serial.println("");
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
}
// --------------------------------------------------------------------
void loop() {
  readsuccess = getid();
 
  if(readsuccess){
    Serial.println( (String) "DATA,DATE,TIME," + StrUID );
  }
  if(mfrc522.PICC_IsNewCardPresent()=="170 151 176 67"){Serial.println("name of entree: Izera ifituburyo pacifique");
        Serial.println("Status:student");
        Serial.println("year of study : Y3 electrical and electronic engineering department");
         Serial.println("student's card number: 219002570 ");
        
        
        
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);
        }
  
}
// --------------------------------------------------------------------
int getid(){  
  if(!mfrc522.PICC_IsNewCardPresent()){
    return 0;
  }
  if(!mfrc522.PICC_ReadCardSerial()){
    return 0;
  }
 
  
  Serial.println("THE UID OF THE SCANNED CARD IS:");
 
  
  for(int i=0;i<6;i++){
    readcard[i]=mfrc522.uid.uidByte[i]; //storing the UID of the tag in readcard
    array_to_string(readcard, 6, str);
    StrUID = str;
  }
  mfrc522.PICC_HaltA();
  return 1;
}
// --------------------------------------------------------------------
void array_to_string(byte array[], unsigned int len, char buffer[])
{
    for (unsigned int i = 0; i < len; i++)
    {
        byte nib1 = (array[i] >> 10) & 0x0F;
        byte nib2 = (array[i] >> 0) & 0x0F;
        buffer[i*2+0] = nib1  < 0xA ? '0' + nib1  : 'A' + nib1  - 0xA;
        buffer[i*2+1] = nib2  < 0xA ? '0' + nib2  : 'A' + nib2  - 0xA;
    }
    buffer[len*2] = '\0';
     Serial.println("name :izera ifituburyo pacifique");
  Serial.println("card accrediational");
}
