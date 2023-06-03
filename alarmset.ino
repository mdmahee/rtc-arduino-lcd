/*Function to set alarm time and feed time into Internal eeprom*/

void time()                             
{

/*lcd.clear();
      lcd.setCursor(0,0);
    lcd.print("Set Event Time ");         Serial.print("Set Event Time ");
        lcd.print(HOUR);    Serial.print(HOUR);
    lcd.print(":");    Serial.print(":");
    lcd.print(MINUT);    Serial.print(MINUT);
    lcd.print(":");    Serial.print(":");
    lcd.print(SECOND);    Serial.print(SECOND);

*/

  
  int temp=1,minuts=0,hours=0,seconds=0;
  
    while(temp==1)
    {
     if(digitalRead(INC)==0)   //inc bt pressed
     {
      HOUR++;
      if(HOUR==24)
      {
       HOUR=0;
      }
      while(digitalRead(INC)==0);
     }
     
    lcd.clear();
    lcd.print("Set Event Hour ");         Serial.print("Set Event Hour ");
   //lcd.print(x); 
    lcd.setCursor(0,1);
    lcd.print(HOUR);    Serial.print(HOUR);
      Serial.println();
    delay(100);
    
    if(digitalRead(next)==0)      //next bt pressed
    {
      hours1=HOUR;
      EEPROM.write(11,hours1);
     temp=2;
     while(digitalRead(next)==0);
    }
    }
    
    while(temp==2)
    {
     if(digitalRead(INC)==0)
     {
      MINUT++;
      if(MINUT==60)
      {MINUT=0;}
      while(digitalRead(INC)==0);
     }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Set Minute");    Serial.print("set MINUT");    
    lcd.setCursor(0,1);
    lcd.print(MINUT);    Serial.print(MINUT);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       minut=MINUT;
       EEPROM.write(12, minut);  //add++
       temp=3;
       while(digitalRead(next)==0);
      }
    }









 while(temp==3)
    {
     if(digitalRead(INC)==0)
     {
      DAY++;
      if(DAY==32)
      {DAY=0;}
      while(digitalRead(INC)==0);
     }
  /*  lcd.clear();
    lcd.print("Set Event Date"); Serial.print("set event date");
    lcd.print(DAY); Serial.print(DAY);
    lcd.print("."); Serial.print(".");
    lcd.print(MONTH); Serial.print(MONTH);
    lcd.print("."); Serial.print(".");
    lcd.print(YR); Serial.print(YR);
    delay(1000);
    */
    lcd.clear();
    lcd.print("Set Event Day ");         Serial.print("Set Event Day ");
    lcd.setCursor(0,1);
    lcd.print(DAY); Serial.print(DAY);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       day1=DAY;
       EEPROM.write(13, day1);
       temp=4;
       while(digitalRead(next)==0);
      }
    }


 while(temp==4)
    {
     if(digitalRead(INC)==0)
     {
      MONTH++;
      if(MONTH==13)
      {MONTH=0;}
      while(digitalRead(INC)==0);
     }
    lcd.clear();
        lcd.setCursor(0,0);
    lcd.print("Set Event month"); Serial.print("set event month");
    lcd.setCursor(0,1);
    lcd.print(MONTH); Serial.print(MONTH);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       month1=MONTH;
       EEPROM.write(14, month1);
       temp=5;
       while(digitalRead(next)==0);
      }
    }


 while(temp==5)
    {
     if(digitalRead(INC)==0)
     {
      YR++;
      if(YR==100)
      {YR=0;}
      while(digitalRead(INC)==0);
     }
    lcd.clear();
        lcd.setCursor(0,0);
    lcd.print("Set Event year"); Serial.print("set event year");
    lcd.setCursor(0,1);
    lcd.print(YR); Serial.print(YR);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       yr1=YR;
       EEPROM.write(15, yr1);
       temp=6;
       while(digitalRead(next)==0);
      }
    }


 while(temp==6)
    {
     if(digitalRead(INC)==0)
     {
      TTIME++;
      if(TTIME==60)
      {TTIME=0;}
      while(digitalRead(INC)==0);
     }
    lcd.clear();
    lcd.print("Set Event T:Time"); Serial.print("set event T:Time");
    lcd.setCursor(0,1);
    lcd.print(TTIME); Serial.print(TTIME);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       ttime=TTIME;
       EEPROM.write(16, ttime);
       temp=7;
       while(digitalRead(next)==0);
      }
    }

 while(temp==7)
    {
     if(digitalRead(INC)==0)
     {
      DSTATUS++;
      if(DSTATUS==2)
      {DSTATUS=0;}
      while(digitalRead(INC)==0);
     }
    lcd.clear();
    lcd.print("Set Device Status"); Serial.print("Set Device Status");
    lcd.setCursor(0,1);
    lcd.print(DSTATUS); Serial.print(DSTATUS);
      Serial.println();

    delay(100);
      if(digitalRead(next)==0)
      {
       dstatus=DSTATUS;
       EEPROM.write(17, dstatus);
       temp=0;
       while(digitalRead(next)==0);
      }
    }








    
    delay(1000);
}
