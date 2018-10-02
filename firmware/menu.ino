void bluetoothMode(){
  //tft.clrScr();
  displayClear();
  delay(MENU_PAUSE);
  tft.print("BLUETOOTH MODE", LCD_BLUETOOTH_MENU); 
  int val = 0;
  
  while(buttonPressed == BUTTON_NONE){
    val = BLUETOOTH.read();
    //Serial.println(val);
    if ( val == 0){
      motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
      motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ",LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val > MOTOR_MIN_SPEED){
      currentSpeed = val;
      tft.print("              ",LCD_BLUETOOTH_MEMO);
      tft.print("speed - " + String(currentSpeed), LCD_BLUETOOTH_MEMO);
    }
    if (val == 1){
      motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ",LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 2){
      motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 3){
      motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 4){
      motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 6){
      motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
      motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 7){
      motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);;
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
    if ( val == 8){
      motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
      motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }  
    if ( val == 9){
      motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
      motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
      tft.print("              ", LCD_BLUETOOTH_MEMO);
      tft.print(tagStringMemo [val], LCD_BLUETOOTH_MEMO);
    }
  }  
  displayClear();
  //tft.clrScr();
delay(MENU_PAUSE);
}//bluetoothMode()



//////
void adjustTags(){
  //tft.clrScr();
  displayClear();
  tft.print("ADJUST TAGs", LCD_TAG_MENU);
  delay(MENU_PAUSE);
  String tagString = TAG_NONE;
  //Serial.println("adjustTags");
  int index = 0;
  while(index < TAG_AMOUNT && buttonPressed == BUTTON_NONE){   
 //  for (index = 0; index < TAG_AMOUNT; index++){
  //tft.clrScr();
  tft.print(tagStringMemo[index], LCD_TAG_MEMO); 
  while(tagString == TAG_NONE){
    tagString = getTagString(); 
    resetReader();  
  }
  //          Serial.println(tagString);
  tags[index] = tagString;
  tft.print(tags[index], LCD_TAG_VALUE); 
  tagString = TAG_NONE;
//  delay(SETUP_PAUSE);
  index++;  
// }
  } 
displayClear();
//tft.clrScr();
//  Serial.println("Save to EEPROM");
  for (int i = 0; i < (TAG_AMOUNT * TAG_LENGTH); i = i + TAG_LENGTH){
    saveTagToEeprom(tags[i/TAG_LENGTH], EEPROM_START_ADDRESS + i);  
  }
//  Serial.println("exit");
delay(MENU_PAUSE);
}//adjustTags()



//////
void playSequence(){
//tft.clrScr();
displayClear();
tft.print("PLAY SEQUENCE", LCD_PLAY_MENU);
delay(MENU_PAUSE);
int val;

  
int index = 0;
while(index < sequenceLength && buttonPressed == BUTTON_NONE){ 
 // for (int i=0; i < sequenceLength; i++){
   //      lcd.print(tagCharMemo[tagSequence[i]]);  
   //      lcd.print(" ");
  tft.print("              ", LCD_PLAY_SEQUENCE);
  tft.print(tagStringMemo[tagSequence[index]], LCD_PLAY_SEQUENCE);
  val = tagSequence[index];
  if ( val == 0){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
  }
  if (val == 1){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 2){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 3){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 4){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 6){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 7){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
  }
  if ( val == 8){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
  }  
  if ( val == 9){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
  }      
         
  delay(sequenceStep);
  index++;  
 // } 
}
//   while(buttonPressed != BUTTON_PLAY){
//  }  
   
  motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
  motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);

displayClear();           
//  tft.clrScr();
delay(MENU_PAUSE);          
}//playSequence()



//////
void setSequence(){
 displayClear();
// tft.clrScr();
 tft.print("SET SEQUENCE", LCD_SEQUENCE_MENU);
 delay(MENU_PAUSE);
 String tagString = TAG_NONE;
 for (int i=0; i < TAG_SEQUENCE; i++){
   tagSequence[i] = 0; 
 }
 
 motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_MIN_SPEED, LEFT_MOTOR_PIN_ENABLE);
 motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_MIN_SPEED, RIGHT_MOTOR_PIN_ENABLE);
    
 int index = 0;
 while(index < TAG_SEQUENCE && buttonPressed == BUTTON_NONE){
   //tft.clrScr();
   tft.print("USE TAG " + String (index+1) + "/" + String (TAG_SEQUENCE), LCD_SEQUENCE_MEMO); 
   while(tagString == TAG_NONE){
     tagString = getTagString();  
     resetReader();
   }  
   for(int i=0; i < TAG_AMOUNT; i++){
     if (tags[i] == tagString){
       tagSequence[index] = i;  
       tft.print(tags[i], LCD_SEQUENCE_MEMO); 
       tft.print("             ", LCD_SEQUENCE_TAG); 
       tft.print(tagStringMemo[i], LCD_SEQUENCE_TAG); 
       delay(MENU_PAUSE);
       index++;
     }
   }  
   tagString = TAG_NONE;
 }  
  
 motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
 motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE); 
  
 sequenceLength = index;

 displayClear();
 delay(MENU_PAUSE);
}//setSequence()
