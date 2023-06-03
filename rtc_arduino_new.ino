/* ----- C Program for Arduino based Alarm Clock ---- */

#include <Wire.h>
#include<EEPROM.h>
#include <RTClib.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 8, 7, 6, 5); 
RTC_DS1307 RTC;
int temp,inc,hours1,minut,day1,month1,yr1,add=11,ttime=1,dstatus;

int next=2;    
int INC=3;
int set_mad=4;

#define buzzer A2
#define relay A3

int HOUR,MINUT,SECOND,DAY,MONTH,YR,TTIME=1,DSTATUS;

  int tem[18];

int vdata;
float volt;
 
void setup()
{
 Wire.begin();
 RTC.begin();
 lcd.begin(16,2);
 pinMode(INC, INPUT);
 pinMode(next, INPUT);
 pinMode(set_mad, INPUT);
 pinMode(buzzer, OUTPUT);
 pinMode(relay, OUTPUT);
  digitalWrite(relay, HIGH);
 digitalWrite(buzzer, LOW);

 digitalWrite(next, HIGH);
 digitalWrite(set_mad, HIGH);
 digitalWrite(INC, HIGH);

 Serial.begin(9600);
 
   lcd.setCursor(0,0);
   lcd.print("Auto IED Mng:Sys");
   lcd.setCursor(0,1);
   lcd.print("   Sappers 43   ");
    delay(5000);

   digitalWrite(relay,HIGH);
   delay(500);
   
   digitalWrite(buzzer,HIGH);
   delay(100);
   digitalWrite(buzzer,LOW);
   delay(500);
   digitalWrite(buzzer,HIGH);
   delay(500); 
   digitalWrite(buzzer,LOW);

    
 if(!RTC.isrunning())
 {
 RTC.adjust(DateTime(__DATE__,__TIME__));
 }
}
 
void loop()
{
   int temp=0,val=1,temp4;
   
   DateTime now = RTC.now();


   
   if(digitalRead(set_mad) == 0)      //set Alarm time  BT pressed
   { 
     lcd.setCursor(0,0);
     lcd.print("Set Event Time");     Serial.print("  Set Event Time");
    delay(2000);
    defualtt();
    time();
    delay(1000);


    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("    Event"); Serial.print("  Event time ");
    lcd.setCursor(0,1);
    lcd.print(" has been set"); Serial.print(" has been set  ");
    delay(2000);
  }


  
 lcd.clear();
 lcd.setCursor(0,0);
// lcd.print("T:"); Serial.print("   T:");
// lcd.setCursor(2,0);
 lcd.print(HOUR=now.hour(),DEC);  Serial.print(HOUR=now.hour(),DEC); 
 lcd.print(":"); Serial.print(":");
 lcd.print(MINUT=now.minute(),DEC); Serial.print(MINUT=now.minute(),DEC);
 lcd.print(":"); Serial.print(":");
 lcd.print(SECOND=now.second(),DEC); Serial.print(SECOND=now.second(),DEC);

 lcd.setCursor(0,1);
 //lcd.print("D:"); Serial.print("  D: ");
 lcd.print(DAY=now.day(),DEC);    Serial.print(now.day(),DEC);
 lcd.print(".");    Serial.print(".");
 lcd.print(MONTH=now.month(),DEC);    Serial.print(now.month(),DEC);
 lcd.print(".");   Serial.print(".");
 lcd.print(YR=(now.year()-2000),DEC); Serial.print((now.year()-2000),DEC); 
 Serial.print("      ");

 vdata=analogRead(A1);
 volt = vdata * 5.0 / 1023.0;
 lcd.setCursor(12,0);
  lcd.print(volt); Serial.print(volt);
 lcd.setCursor(15,0);
 lcd.print("V"); Serial.print("   V=");

 lcd.setCursor(8,0);
 lcd.print("Dn"); Serial.print("   Dn=");
 lcd.print(1); Serial.print(1);
 
 lcd.setCursor(8,1);
 lcd.print("Ds"); Serial.print("   Ds=");
 lcd.print(DSTATUS); Serial.print(DSTATUS);

 lcd.setCursor(12,1);
 lcd.print("Tt"); Serial.print("   Tt=");
 lcd.print(TTIME); Serial.print(TTIME);





/*  for(int i=11;i<18;i++)
  {
    tem[i]=EEPROM.read(i);
    Serial.print("  ");
    Serial.print(tem[i]);
  }
*/

//TTIME=tem[16];TTIME=TTIME;TTIME==TTIME;
//DSTATUS=tem[17];DSTATUS=DSTATUS;DSTATUS==DSTATUS;

  Serial.println();
 
 match();


 
 delay(200);
}
