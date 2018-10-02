//////
void adjustTags(){
  lcd.clear();
  delay(MENU_PAUSE);
  String tagString = tags[TAG_NONE];
  int index;
   for (index = 1; index < TAG_AMOUNT; index++){
   lcd.clear();
   lcd.setCursor(LCD_TAG_MENU); 
   lcd.print(tagStringMemo[index]); 
   lcd.display();
     while(tagString == tags[TAG_NONE]){
            tagString = getTagString();   
            }
        tags[index] = tagString;
  //      Serial.println(tagString+" == "+tags[index]+" - "+index);
        lcd.setCursor(LCD_TAG_MEMO); 
        lcd.print(tags[index]); 
        tagString = tags[TAG_NONE];
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
  
  lcd.setCursor(LCD_PLAY_MENU); 
  lcd.print("SEQUENCE"); 
  lcd.display();
  lcd.setCursor(LCD_PLAY_SEQUENCE);
  
  for (int i=0; i < sequenceLength; i++){
         lcd.print((char)tagCharMemo[tagSequence[i]]);  
         lcd.print(" ");
         lcd.display();
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
 String tagString = tags[TAG_NONE];
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
    for(int i=1; i < TAG_AMOUNT; i++){
    }
         while(tagString == tags[TAG_NONE]){
              tagString = getTagString();  
              }  
                 for(int i=1; i < TAG_AMOUNT; i++){
        
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
  tagString = tags[TAG_NONE];
  }  
 sequenceLength = index;
}//setSequence()


//////
void timerIsr() {
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
  
   buttonPressed = BUTTON_NONE;
    
}//timeIsr()
