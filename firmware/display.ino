//////
void displayReset(){
  tft.setColor(255, 0, 0);
  tft.fillRect(0, 0, 159, 13);

  tft.setColor(64, 64, 64);
  tft.fillRect(0, 114, 159, 127);
  tft.setColor(255, 255, 255);
  tft.setBackColor(255, 0, 0);
  tft.print(SYSTEM_MEMO, LCD_SYSTEM_MEMO);
  tft.setBackColor(64, 64, 64);
  tft.setColor(255,255,0);
  tft.print(VERSION_MEMO, LCD_VERSION_MEMO);
  
  tft.setColor(255,255,255);
  tft.setBackColor(0, 0, 0);
}//displayReset()


//////
void displayClear(){
  tft.setColor(0, 0, 0);
  tft.fillRect(0, 14, 159, 113);  
  tft.setColor(255,255,255);
  tft.setBackColor(0, 0, 0);
}//displayClear()
