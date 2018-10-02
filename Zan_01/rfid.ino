
boolean tagCheckSum(String tagString) {
  boolean res = false;
  unsigned int b1,b2,b3,b4,b5,checksum;
  char charBuf[13];
  tagString.toCharArray(charBuf, 13); 
  sscanf(charBuf , "%2x%2x%2x%2x%2x%2x", &b1, &b2, &b3, &b4, &b5, &checksum);
  if ( (b1 ^ b2 ^ b3 ^ b4 ^ b5) == checksum ) {
      return true;
      }else{
      return false;
      } 
}//tagCheckSum()

 
///// 
String getTagString(){
  String tagString = "", tempTagString = "";
  char c;
   
  if (rfid.isListening()) {
    while(rfid.available()){
        c=rfid.read(); 
        tempTagString = tempTagString + c;
      if (tempTagString.length() == 14 ){ 
        if ((tempTagString[0]==2) && (tempTagString[13]==3)) {
          tempTagString = tempTagString.substring(1,13); 
          if (tagCheckSum(tempTagString) == true ){ 
              tagString = tempTagString;
          
          }
        }
        tempTagString="";
      }
    }//while()
  }

if (tagString != lastTagString){
  // if (tagString != ""){ 
     lastTagString = tagString;
   //   }
    return (tagString);
    
    }else{
    return ("");
   }
}//getTagString()
