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
   buttonPressed = readKeypad();
}//timeIsr()
