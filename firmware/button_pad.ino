byte readKeypad(){

	for (byte r=0; r < KEYPAD_ROWS; r++) {
		pinMode(keypadRowPins[r],INPUT_PULLUP);
	}

	for (byte c=0; c < KEYPAD_COLS; c++) {
		pinMode(keypadColPins[c], OUTPUT);
		digitalWrite(keypadColPins[c], LOW);	
		for (byte r=0; r < KEYPAD_ROWS; r++) {
		if(digitalRead(keypadRowPins[r]) == LOW){
                  digitalWrite(keypadColPins[c],HIGH);
		  pinMode(keypadColPins[c],INPUT);
                  return (r * KEYPAD_COLS + c + 1);
                  }
                }
		digitalWrite(keypadColPins[c],HIGH);
		pinMode(keypadColPins[c],INPUT);
	}
return (BUTTON_NONE);
}//readKeypad()


//////
void setColor(int ledPin, int color[]){

  digitalWrite(LED_RED_PIN, LOW);
  digitalWrite(LED_GREEN_PIN, LOW);
  digitalWrite(LED_BLUE_PIN, LOW);

  analogWrite(ledPin, 255-color[0]);
  digitalWrite(LED_RED_PIN, HIGH);
  delayMicroseconds(300);
  digitalWrite(LED_RED_PIN, LOW);

  analogWrite(ledPin, 255-color[1]);
  digitalWrite(LED_GREEN_PIN, HIGH);
  delayMicroseconds(300);
  digitalWrite(LED_GREEN_PIN, LOW);

  analogWrite(ledPin, 255-color[2]);
  digitalWrite(LED_BLUE_PIN, HIGH);
  delayMicroseconds(300);
  digitalWrite(LED_BLUE_PIN, LOW);
}//setColor()


