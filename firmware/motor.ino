//////
boolean motorRunForward(int motorPinA, int motorPinB, int motorSpeed, int motorPinEnable){
if (isFrontLimitSwitchActive == true){
    return false;
    }
if (motorSpeed == MOTOR_STOP){
   digitalWrite(motorPinEnable, LOW); 
   }else{
        digitalWrite(motorPinEnable, HIGH);   
        digitalWrite(motorPinB, LOW);  
        analogWrite(motorPinA, motorSpeed);
        }
return true;  
}//motorRunForward()



//////
boolean motorRunBackward(int motorPinA, int motorPinB, int motorSpeed, int motorPinEnable){
if (isRearLimitSwitchActive == true){
    return false;
    }
if (motorSpeed == MOTOR_STOP){
   digitalWrite(motorPinEnable, LOW); 
   }else{
        digitalWrite(motorPinEnable, HIGH);   
        digitalWrite(motorPinA, LOW);  
        analogWrite(motorPinB, motorSpeed);
        }
return true;  
}//motorRunBackward()
