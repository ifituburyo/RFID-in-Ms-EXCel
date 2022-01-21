#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

String rfidCard;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.init();
  pinMode(2, OUTPUT);
  pinMode(3,OUTPUT);
}

void loop() {
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if (rfidCard == "170 151 176 67") {
        Serial.println("name of entree: Izera ifituburyo pacifique");
        Serial.println("Status:student");
        Serial.println("year of study : Y3 electrical and electronic engineering department");
         Serial.println("student's card number: 219002570 ");
        Serial.println("authorized authantications .....");
        Serial.println("Acess granted");
        digitalWrite(2, HIGH);
        digitalWrite(3,HIGH);
        delay(100);
        digitalWrite(2, LOW);
        digitalWrite(3,LOW);
       
      } 
      else if (rfidCard == "10 152 18 63")
      {
        Serial.println("name of entree:       mahoro amina ");
        Serial.println("Status:      Stuff member ");
        Serial.println("year of study :      Department of finance");
        Serial.println("badge number:           456789usd89");
        Serial.println("authorized authantication ");
        Serial.println("access granted");
        
        digitalWrite(2, HIGH);
        digitalWrite(3,HIGH);
        delay(100);
        digitalWrite(2, LOW);
        digitalWrite(3,LOW);
        
        }
        else if (rfidCard == "77 214 109 13")
        {
           Serial.println("name of entree:     obina muhiggwaa katuumi");
        Serial.println("Status:                   Guest ");
        Serial.println("year of study :      Visitor from international forum of science and engineering");
        Serial.println("badge number:      IFoSE:145");
         Serial.println("authorized authantication ");
        Serial.println("access granted");
          }
        else {
           Serial.println("name of the entree  :  unknown card  ");
           Serial.println(" do you need help,   please register or call for help @ tel: +250786560648");
           digitalWrite(2, HIGH);
           digitalWrite(3,HIGH);
           delay(1000);
           digitalWrite(2, LOW);
           digitalWrite(3,LOW);
           
        }
        
        
      }
      delay(1000);
    }
    rfid.halt();
  }
