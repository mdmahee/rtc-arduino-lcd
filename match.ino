/* Function to chack medication time */

void match()
{
  int tem[18];
  for(int i=11;i<18;i++)
  {
    tem[i]=EEPROM.read(i);
    Serial.print("  ");
    Serial.print(tem[i]);
  }


/*
  for(int i=11;i<18;i++)
  {
    tem[i]=EEPROM.read(i);
    Serial.print("  ");
    Serial.print(tem[i]);
  }
 */ 

 
 if(DSTATUS==1)
 {  
  if(HOUR == tem[11] && MINUT == tem[12] && DAY == tem[13] && MONTH == tem[14] && YR == tem[15]&& TTIME == tem[16] && DSTATUS == tem[17]  ) 
  {
   beep();beep();beep();beep();
   lcd.clear();
   lcd.print("Event Happening");   Serial.print("Event Happening");
   lcd.setCursor(0,1);
   lcd.print("Event Happening");
   beep();beep();beep();beep();
  }
 }

else
 {  
  if(HOUR == tem[11] && MINUT == tem[12] && DAY == tem[13] && MONTH == tem[14] && YR == tem[15]&& TTIME == tem[16] && DSTATUS == tem[17]  ) 
  {
   
   lcd.clear();
   lcd.print("Event Happening"); Serial.print("Event Happening");
   lcd.setCursor(0,1);
   lcd.print("Device Nt Active");   Serial.print("Device Nt Active");

  
  }
 }

}
