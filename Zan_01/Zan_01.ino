#include <TimerOne.h>
#include <SoftwareSerial.h> 
#include "setup.h"
#include "PCD8544.h"

//unsigned long lastTagMillis();
String lastTagString = "";
//
SoftwareSerial rfid = SoftwareSerial(SOFTWARE_RX_PIN, SOFTWARE_TX_PIN);
//
volatile byte buttonPressed = BUTTON_NONE;
//
PCD8544 lcd = PCD8544(7, 6, 5, 4, 3);
//
String tags[TAG_AMOUNT];
//
char tagCharMemo [TAG_AMOUNT] = {' ','F','B','L','R','P'};
String tagStringMemo [TAG_AMOUNT] = {
  "",
  "[F]orward",
  "[B]ackward",
  "[L]eft",
  "[R]ight",
  "re[P]eat"
};
//
byte tagSequence [TAG_SEQUENCE];
int sequenceLength = 0;


void setup() {
  Serial.begin(9600);
  rfid.begin(9600);  
  rfid.listen();

  pinMode(BUTTON_TAG_PIN, INPUT_PULLUP);
  pinMode(BUTTON_SET_PIN, INPUT_PULLUP);
  pinMode(BUTTON_PLAY_PIN, INPUT_PULLUP);

  pinMode(RFID_RESET_PIN, OUTPUT);
  digitalWrite(RFID_RESET_PIN, HIGH);
  
  lcd.init();
  lcd.setContrast(50);
  lcd.clear();

  Timer1.initialize(100000);
  Timer1.attachInterrupt(timerIsr);

for (int i=0; i<TAG_SEQUENCE; i++){
 tagSequence[i] = 0; 
}
tags[0] = "";

}//setup()


//////
void loop() {
   lcd.clear();
   lcd.setCursor(LCD_MAIN_MENU_MEMO); 
   lcd.print("Hit the button");
   lcd.setCursor(LCD_MAIN_MENU_TAG); 
   lcd.print("TAG adjastment");
   lcd.setCursor(LCD_MAIN_MENU_SET); 
   lcd.print("SET sequence");
   lcd.setCursor(LCD_MAIN_MENU_PLAY); 
   lcd.print("PLAY sequence");   
   //
  switch (buttonPressed) {
    case BUTTON_TAG: {
        adjustTags();
        /*
        for (int i = 1; i < TAG_AMOUNT; i++){
         lcd.setCursor(LCD_TAG_MEMO); 
         lcd.print(tags[i]);
         delay(MENU_PAUSE);
         lcd.display();
         }
        */
        break;
      }
    case BUTTON_SET: {
        setSequence();
        break;
      }
    case BUTTON_PLAY: {
        playSequence();
        break;
      }
  }
 // 
  lcd.display();
  delay(BUTTON_PAUSE);
}//loop()
