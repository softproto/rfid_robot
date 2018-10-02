void bluetoothMode(){
  lcd.clear();
  delay(MENU_PAUSE);
  lcd.setCursor(LCD_BLUETOOTH_MENU); 
  lcd.print("BLUETOOTH MODE");
  lcd.display();
  int val = 0;
  
while(buttonPressed != BUTTON_BLUETOOTH){
    val = BLUETOOTH.read();
    if ( val == 0){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]);  
    }
    if ( val > MOTOR_MIN_SPEED){
    currentSpeed = val;
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("speed - ");
    lcd.print(currentSpeed);  
    }
    if (val == 1){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]);   
    }
    if ( val == 2){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]);  
    }
    if ( val == 3){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]); 
    }
    if ( val == 4){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]); 
    }
    if ( val == 6){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]); 
    }
    if ( val == 7){
    motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);;
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]); 
    }
    if ( val == 8){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]);  
    }  
    if ( val == 9){
    motorRunBackward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
    motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print("              "); 
    lcd.setCursor(LCD_BLUETOOTH_MEMO);
    lcd.print(tagStringMemo [val]);  
    }
    lcd.display();  
  }  
  lcd.clear();
  delay(MENU_PAUSE);
}//bluetoothMode()


//////
void adjustTags(){
  lcd.clear();
  delay(MENU_PAUSE);
  String tagString = TAG_NONE;
  int index;
   for (index = 0; index < TAG_AMOUNT; index++){
   lcd.clear();
   lcd.setCursor(LCD_TAG_MENU); 
   lcd.print(tagStringMemo[index]); 
   lcd.display();
     while(tagString == TAG_NONE){
            tagString = getTagString();   
            }
        tags[index] = tagString;
        lcd.setCursor(LCD_TAG_MEMO); 
        lcd.print(tags[index]); 
        tagString = TAG_NONE;
   lcd.display();
   delay(SETUP_PAUSE);
   }
   
lcd.clear();
delay(MENU_PAUSE);
}//adjustTags()


//////
void playSequence(){
  lcd.clear();
  delay(MENU_PAUSE);
  int val;
  
  lcd.setCursor(LCD_PLAY_MENU); 
  lcd.print("SEQUENCE"); 
  lcd.display();
  lcd.setCursor(LCD_PLAY_SEQUENCE);
  
  for (int i=0; i < sequenceLength; i++){
   //      lcd.print(tagCharMemo[tagSequence[i]]);  
   //      lcd.print(" ");
         lcd.setCursor(LCD_PLAY_SEQUENCE);
         lcd.print("              ");
         lcd.setCursor(LCD_PLAY_SEQUENCE);
         lcd.print(tagStringMemo[tagSequence[i]]);
         lcd.display();
   
   
   val = tagSequence[i];
    
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
        motorRunBackward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
        }
    if ( val == 6){
        motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, MOTOR_STOP, LEFT_MOTOR_PIN_ENABLE);
        motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, currentSpeed, RIGHT_MOTOR_PIN_ENABLE);;
        }
    if ( val == 7){
        motorRunForward(LEFT_MOTOR_PIN_A, LEFT_MOTOR_PIN_B, currentSpeed, LEFT_MOTOR_PIN_ENABLE);
        motorRunForward(RIGHT_MOTOR_PIN_A, RIGHT_MOTOR_PIN_B, MOTOR_STOP, RIGHT_MOTOR_PIN_ENABLE);;
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
         } 
 
   while(buttonPressed != BUTTON_PLAY){
   }  
           
  lcd.clear();
  delay(MENU_PAUSE);          
}//playSequence()


//////
void setSequence(){
 lcd.clear();
 delay(MENU_PAUSE);
 String tagString = TAG_NONE;
      for (int i=0; i < TAG_SEQUENCE; i++){
          tagSequence[i] = 0; 
          }
    
  int index = 0;
  while(index < TAG_SEQUENCE && buttonPressed != BUTTON_SET){
    lcd.clear();
    lcd.setCursor(LCD_SEQUENCE_MENU); 
    lcd.print("USE TAG ");
    lcd.print(index+1);    
    lcd.print("/");
    lcd.print(TAG_SEQUENCE);   
    lcd.display();
   
         while(tagString == TAG_NONE){
              tagString = getTagString();  
              }  
                 for(int i=0; i < TAG_AMOUNT; i++){
        
              if (tags[i] == tagString){
                  tagSequence[index] = i;  
                  lcd.setCursor(LCD_SEQUENCE_MEMO); 
                  lcd.print(tags[i]); 
                  lcd.setCursor(LCD_SEQUENCE_TAG); 
                  lcd.print("             ");
                  lcd.setCursor(LCD_SEQUENCE_TAG); 
                  lcd.print(tagStringMemo[i]);
                  lcd.display();
                  delay(SETUP_PAUSE);
                     index++;
                  }
              }  
  tagString = TAG_NONE;
  }  
 sequenceLength = index;
}//setSequence()


//////
void timerIsr() {
   if (digitalRead(REAR_LIMIT_SWITCH) == LOW && isRearLimitSwitchActive != true){
       isRearLimitSwitchActive = true;
       digitalWrite(RIGHT_MOTOR_PIN_ENABLE, LOW);
       digitalWrite(LEFT_MOTOR_PIN_ENABLE, LOW);
       }else{
           if (digitalRead(REAR_LIMIT_SWITCH) == HIGH){
               isRearLimitSwitchActive = false;
               }
           }
   if (digitalRead(FRONT_LIMIT_SWITCH) == LOW && isFrontLimitSwitchActive != true){
       isFrontLimitSwitchActive = true;
       digitalWrite(RIGHT_MOTOR_PIN_ENABLE, LOW);
       digitalWrite(LEFT_MOTOR_PIN_ENABLE, LOW);
       }else{
          if (digitalRead(FRONT_LIMIT_SWITCH) == HIGH){
             isFrontLimitSwitchActive = false;
             }
           }
  
   if (digitalRead(BUTTON_TAG_PIN) == LOW){
       buttonPressed = BUTTON_TAG;
       return;
       }
   if (digitalRead(BUTTON_SET_PIN) == LOW){
       buttonPressed = BUTTON_SET;
       return;
       } 
   if (digitalRead(BUTTON_PLAY_PIN) == LOW){
       buttonPressed = BUTTON_PLAY;
       return;
       }
   if (digitalRead(BUTTON_BLUETOOTH_PIN) == LOW){
       buttonPressed = BUTTON_BLUETOOTH;
       return;
       }
  
   buttonPressed = BUTTON_NONE;
    
}//timeIsr()
