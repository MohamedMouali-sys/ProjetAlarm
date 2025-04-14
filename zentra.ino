#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
LiquidCrystal_I2C lcd(0x27,20,2);
RTC_DS3231 RTC;
int val;
//les alarmes (Minute,Heure) enregistré en mémoire:
int HA1,MA1,HA2,MA2,HA3,MA3,HA4,MA4,HA5,MA5;
int HA6,MA6,HA7,MA7,HA8,MA8,HA9,MA9,HA10,MA10;
int HA11,MA11,HA12,MA12,HA13,MA13,HA14,MA14,HA15,MA15;
int HA16,MA16,HA17,MA17,HA18,MA18,HA19,MA19,HA20,MA20;
int HA21,MA21,HA22,MA22,HA23,MA23,HA24,MA24,HA25,MA25;
int HA26,MA26,HA27,MA27,HA28,MA28;
int HA29,MA29,HA30,MA30,HA31,MA31,HA32,MA32,HA33,MA33;
int HA34,MA34,HA35,MA35,HA36,MA36,HA37,MA37,HA38,MA38;
int HA39,MA39,HA40,MA40,HA41,MA41,HA42,MA42;
//------------------------------------------------------------------
//////////////////////////////////////////////////////////////////////
byte CLOCHE[]={
  B00000,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B01110,
  B00100
};
//////////////////////////////////شاشة البدء /////////////////////////
String scrollingmessage = "        PROJET:ALARM " ;
int ii = 0;
String toShow;
byte face[]={
  B00000,
  B01001,
  B01001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000
};
//-----------------------
int R=11;
int Heur;
int Min;
int Annee;
int Mois;
int Jour;
int menu =0;
int Heur1,Min1;
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(R,OUTPUT);
  digitalWrite(R,LOW);
  ////////////////////////////  برمجة شاشة البدء //////////////////////////////
   lcd.setCursor(2,0);  
  lcd.print("PROJET:ALARM");
  lcd.setCursor(4,1);  
  lcd.print("BONJOUR"); 
  
  lcd.createChar(1, face);
  lcd.setCursor(2 ,1);
  lcd.write(byte(1));

  lcd.setCursor(12 ,1);
  lcd.write(byte(1));                                                                                                       
  delay(800);                                                                                         
  //lcd.home();
  
  lcd.setCursor(1, 0);                                                                      
  for (int timeCounter = 0; timeCounter < 26; timeCounter++) 
{                  
  digitalWrite(R,LOW);             
  lcd.home();
  lcd.setCursor(1, 0);                                                
  toShow = scrollingmessage.substring(ii,ii+16);                             
  lcd.print(toShow);                                            
  ii = ii + 1;  
  delay(100);                                                    
}   
 delay(1500);
 lcd.clear();                           
//////////////////////// انتهاء برمجة شاشة البدء /////////////////////////////////////
  // Quante colonne e righe ha il display: 
  lcd.begin(16, 2);
  lcd.clear();
  Wire.begin();
  RTC.begin();
   if (RTC.lostPower()) {
    Serial.println("RTC lost power, lets set the time!");
    // following line sets the RTC to the date & time this sketch was compiled
    RTC.adjust(DateTime(F(__DATE__), F(__TIME__)));
    // This line sets the RTC with an explicit date & time, for example to set
    // January 21, 2014 at 3am you would call:
    // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));
  }
 // RTC.adjust(DateTime(__DATE__, __TIME__));
  int menu=0;
}
 
void loop()
{
  val=analogRead(A2);
  DateTime now = RTC.now();
  
//reglage d'heur
  if(between(val,230,380))
  {
   menu=menu+1;
  }
// **********liste 
  if (menu==0)
  {
    DisplayDateTime();
    delay (1000);
  }
  if (menu==1)
  {
    DisplaySetHour();
  }
  if (menu==2)
  {
    DisplaySetMinute();
  }
  if (menu==3)
  {
    DisplaySetYear();
  }
  if (menu==4)
  {
    DisplaySetMonth();
  }
  if (menu==5)
  {
    DisplaySetDay();
  }
  //alarm 1:
  if (menu==6)
  {
    HA1=Halarm(1,"L->J");
    EEPROM.write(0,HA1);
  }
  if (menu==7)
  {
    MA1=Malarm(1,"L->J");
    EEPROM.write(1,MA1);
  }
  //alarm2: 
  if (menu==8)
  {
    HA2=Halarm(2,"L->J");
    EEPROM.write(2,HA2);
  }
  if (menu==9)
  {
    MA2=Malarm(2,"L->J");
    EEPROM.write(3,MA2);
  }
  //alarm 3:
  if (menu==10)
  {
    HA3=Halarm(3,"L->J");
    EEPROM.write(4,HA3);
  }
  if (menu==11)
  {
    MA3=Malarm(3,"L->J");
    EEPROM.write(5,MA3);
  }
  //alarm 4:
  if (menu==12)
  {
    HA4=Halarm(4,"L->J");
    EEPROM.write(6,HA4);
  }
  if (menu==13)
  {
    MA4=Malarm(4,"L->J");
    EEPROM.write(7,MA4);
  }
  //alarm 5:
  if (menu==14)
  {
    HA5=Halarm(5,"L->J");
    EEPROM.write(8,HA5);
  }
  if (menu==15)
  {
    MA5=Malarm(5,"L->J ");
    EEPROM.write(9,MA5);
  }
  //alarm 6:
  if (menu==16)
  {
    HA6=Halarm(6,"L->J");
    EEPROM.write(10,HA6);
  }
  if (menu==17)
  {
    MA6=Malarm(6,"L->J");
    EEPROM.write(11,MA6);
  }
  //alarm7:
  if (menu==18)
  {
    HA7=Halarm(7,"L->J");
    EEPROM.write(12,HA7);
  }
  if (menu==19)
  {
    MA7=Malarm(7,"L->J");
    EEPROM.write(13,MA7);
  }
//alarm 8:

   if (menu==20)
  {
    HA8=Halarm(8,"L->J");
    EEPROM.write(14,HA8);
  }
  if (menu==21)
  {
    MA8=Malarm(8,"L->J");
    EEPROM.write(15,MA8);
  }
//alarm 9:

   if (menu==22)
  {
    HA9=Halarm(9,"L->J");
    EEPROM.write(16,HA9);
  }
  if (menu==23)
  {
    MA9=Malarm(9,"L->J");
    EEPROM.write(17,MA9);
  }
//alarm 10:
   if (menu==24)
  {
    HA10=Halarm(10,"L->J");
    EEPROM.write(18,HA10);
  }
  if (menu==25)
  {
    MA10=Malarm(10,"L->J");
    EEPROM.write(19,MA10);
  }
//alarm 11
if (menu==26)
  {
    HA11=Halarm(11,"L->J");
    EEPROM.write(20,HA11);
  }
  if (menu==27)
  {
    MA11=Malarm(11,"L->J");
    EEPROM.write(21,MA11);
  }
//alarm 12
if (menu==28)
  {
    HA12=Halarm(12,"L->J");
    EEPROM.write(22,HA12);
  }
  if (menu==29)
  {
    MA12=Malarm(12,"L->J");
    EEPROM.write(23,MA12);
  }
//alarm 13
if (menu==30)
  {
    HA13=Halarm(13,"L->J");
    EEPROM.write(24,HA13);
  }
  if (menu==31)
  {
    MA13=Malarm(13,"L->J");
    EEPROM.write(25,MA13);
  }
//alarm 14
if (menu==32)
  {
    HA14=Halarm(14,"L->J");
    EEPROM.write(26,HA14);
  }
  if (menu==33)
  {
    MA14=Malarm(14,"L->J");
    EEPROM.write(27,MA14);
  } 


 //LES ALARMES DE Vendredi :
 //alarm 1:
  if (menu==34)
  {
    HA15=Halarm(1,"Vendredi");
    EEPROM.write(28,HA15);
  }
  if (menu==35)
  {
    MA15=Malarm(1,"Vendredi");
    EEPROM.write(29,MA15);
  }
  //alarm2: 
  if (menu==36)
  {
    HA16=Halarm(2,"Vendredi");
    EEPROM.write(30,HA16);
  }
  if (menu==37)
  {
    MA16=Malarm(2,"Vendredi");
    EEPROM.write(31,MA16);
  }
  //alarm 3:
  if (menu==38)
  {
    HA17=Halarm(3,"Vendredi");
    EEPROM.write(32,HA17);
  }
  if (menu==39)
  {
    MA17=Malarm(3,"Vendredi");
    EEPROM.write(33,MA17);
  }
  //alarm 4:
  if (menu==40)
  {
    HA18=Halarm(4,"Vendredi");
    EEPROM.write(34,HA18);
  }
  if (menu==41)
  {
    MA18=Malarm(4,"Vendredi");
    EEPROM.write(35,MA18);
  }
  //alarm 5:
  if (menu==42)
  {
    HA19=Halarm(5,"Vendredi");
    EEPROM.write(36,HA19);
  }
  if (menu==43)
  {
    MA19=Malarm(5,"Vendredi");
    EEPROM.write(37,MA19);
  }
  //alarm 6:
  if (menu==44)
  {
    HA20=Halarm(6,"Vendredi");
    EEPROM.write(38,HA20);
  }
  if (menu==45)
  {
    MA20=Malarm(6,"Vendredi");
    EEPROM.write(39,MA20);
  }
  //alarm7:
  if (menu==46)
  {
    HA21=Halarm(7,"Vendredi");
    EEPROM.write(40,HA21);
  }
  if (menu==47)
  {
    MA21=Malarm(7,"Vendredi");
    EEPROM.write(41,MA21);
  }
//alarm 8:

   if (menu==48)
  {
    HA22=Halarm(8,"Vendredi");
    EEPROM.write(42,HA22);
  }
  if (menu==49)
  {
    MA22=Malarm(8,"Vendredi");
    EEPROM.write(43,MA22);
  }
//alarm 9:

   if (menu==50)
  {
    HA23=Halarm(9,"Vendredi");
    EEPROM.write(44,HA23);
  }
  if (menu==51)
  {
    MA23=Malarm(9,"Vendredi");
    EEPROM.write(45,MA23);
  }
//alarm 10:
   if (menu==52)
  {
    HA24=Halarm(10,"Vendredi");
    EEPROM.write(46,HA24);
  }
  if (menu==53)
  {
    MA24=Malarm(10,"Vendredi");
    EEPROM.write(47,MA24);
  }
//alarm 11
if (menu==54)
  {
    HA25=Halarm(11,"Vendredi");
    EEPROM.write(48,HA25);
  }
  if (menu==55)
  {
    MA25=Malarm(11,"Vendredi");
    EEPROM.write(49,MA25);
  }
//alarm 12
if (menu==56)
  {
    HA26=Halarm(12,"Vendredi");
    EEPROM.write(50,HA26);
  }
  if (menu==57)
  {
    MA26=Malarm(12,"Vendredi");
    EEPROM.write(51,MA26);
  }
//alarm 13
if (menu==58)
  {
    HA27=Halarm(13,"Vendredi");
    EEPROM.write(52,HA27);
  }
  if (menu==59)
  {
    MA27=Malarm(13,"Vendredi");
    EEPROM.write(53,MA27);
  }
//alarm 14
if (menu==60)
  {
    HA28=Halarm(14,"Vendredi");
    EEPROM.write(54,HA28);
  }
  if (menu==61)
  {
    MA28=Malarm(14,"Vendredi");
    EEPROM.write(55,MA28);
  } 
 //********FIN ALARME Vendredi 

 //***************ALARME Samedi**********
 //alarm 1:
  if (menu==62)
  {
    HA29=Halarm(1,"Samedi");
    EEPROM.write(56,HA29);
  }
  if (menu==63)
  {
    MA29=Malarm(1,"Samedi");
    EEPROM.write(57,MA29);
  }
  //alarm2: 
  if (menu==64)
  {
    HA30=Halarm(2,"Samedi");
    EEPROM.write(58,HA30);
  }
  if (menu==65)
  {
    MA30=Malarm(2,"Samedi");
    EEPROM.write(59,MA30);
  }
  //alarm 3:
  if (menu==66)
  {
    HA31=Halarm(3,"Samedi");
    EEPROM.write(60,HA31);
  }
  if (menu==67)
  {
    MA31=Malarm(3,"Samedi");
    EEPROM.write(61,MA31);
  }
  //alarm 4:
  if (menu==68)
  {
    HA32=Halarm(4,"Samedi");
    EEPROM.write(62,HA32);
  }
  if (menu==69)
  {
    MA32=Malarm(4,"Samedi");
    EEPROM.write(63,MA32);
  }
  //alarm 5:
  if (menu==70)
  {
    HA33=Halarm(5,"Samedi");
    EEPROM.write(64,HA33);
  }
  if (menu==71)
  {
    MA33=Malarm(5,"Samedi");
    EEPROM.write(65,MA33);
  }
  //alarm 6:
  if (menu==72)
  {
    HA34=Halarm(6,"Samedi");
    EEPROM.write(66,HA34);
  }
  if (menu==73)
  {
    MA34=Malarm(6,"Samedi");
    EEPROM.write(67,MA34);
  }
  //alarm7:
  if (menu==74)
  {
    HA35=Halarm(7,"Samedi");
    EEPROM.write(68,HA35);
  }
  if (menu==75)
  {
    MA35=Malarm(7,"Samedi");
    EEPROM.write(69,MA35);
  }
//alarm 8:

   if (menu==76)
  {
    HA36=Halarm(8,"Samedi");
    EEPROM.write(70,HA36);
  }
  if (menu==77)
  {
    MA36=Malarm(8,"Samedi");
    EEPROM.write(71,MA36);
  }
//alarm 9:

   if (menu==78)
  {
    HA37=Halarm(9,"Samedi");
    EEPROM.write(72,HA37);
  }
  if (menu==79)
  {
    MA37=Malarm(9,"Samedi");
    EEPROM.write(73,MA37);
  }
//alarm 10:
   if (menu==80)
  {
    HA38=Halarm(10,"Samedi");
    EEPROM.write(74,HA38);
  }
  if (menu==81)
  {
    MA38=Malarm(10,"Samedi");
    EEPROM.write(75,MA38);
  }
//alarm 11
if (menu==82)
  {
    HA39=Halarm(11,"Samedi");
    EEPROM.write(76,HA39);
  }
  if (menu==83)
  {
    MA39=Malarm(11,"Samedi");
    EEPROM.write(77,MA39);
  }
//alarm 12
if (menu==84)
  {
    HA40=Halarm(12,"Samedi");
    EEPROM.write(78,HA40);
  }
  if (menu==85)
  {
    MA40=Malarm(12,"Samedi");
    EEPROM.write(79,MA40);
  }
//alarm 13
if (menu==86)
  {
    HA41=Halarm(13,"Samedi");
    EEPROM.write(80,HA41);
  }
  if (menu==87)
  {
    MA41=Malarm(13,"Samedi");
    EEPROM.write(81,MA41);
  }
//alarm 14
if (menu==88)
  {
    HA42=Halarm(14,"Samedi");
    EEPROM.write(82,HA42);
  }
  if (menu==89)
  {
    MA42=Malarm(14,"Samedi");
    EEPROM.write(83,MA42);
  } 
 //************FIN ALARM Samedi
  if (menu==90)
  {
    DateActuel(); 
    delay(500);
    menu=0;
  }
  //Pour aller a la date actuel
if(between(val,550,650)){
                    DateActuel(); 
                    delay(500);
                    menu=0;}
//pour effacer les alarmes: 
 if(between(val,700,890)){
                        for(int i=0;i<255;i++)
                        {EEPROM.write(i,61);delay(10);}
                        delay(10);
                        lcd.setCursor(15, 1);
                        lcd.print("C");
                        delay(2000);
                        lcd.setCursor(15, 1);
                        lcd.print("");}
//retour 
if(between(val,900,1050) && menu>0){ menu=menu-1; delay(100);}                                               
  delay(100);
//******************* Alarme de LUNDI<-------------->JEUDI***********
  if(((now.dayOfTheWeek() == 1) || (now.dayOfTheWeek() == 2) || (now.dayOfTheWeek() == 3) || (now.dayOfTheWeek() == 4))&& now.second()<8){ 
       if (now.hour() ==EEPROM.read(0) && now.minute() ==EEPROM.read(1)|| now.hour() ==EEPROM.read(2) && now.minute() ==EEPROM.read(3)||
          now.hour() ==EEPROM.read(4) && now.minute() ==EEPROM.read(5)|| now.hour() ==EEPROM.read(6) && now.minute() ==EEPROM.read(7)||
          now.hour() ==EEPROM.read(8) && now.minute() ==EEPROM.read(9)|| now.hour() ==EEPROM.read(10) && now.minute() ==EEPROM.read(11)||
          now.hour() ==EEPROM.read(12) && now.minute() ==EEPROM.read(13)|| now.hour() ==EEPROM.read(14) && now.minute() ==EEPROM.read(15)||
          now.hour() ==EEPROM.read(16) && now.minute() ==EEPROM.read(17)|| now.hour() ==EEPROM.read(18) && now.minute() ==EEPROM.read(19)||
          now.hour() ==EEPROM.read(20) && now.minute() ==EEPROM.read(21)|| now.hour() ==EEPROM.read(22) && now.minute() ==EEPROM.read(23)||
          now.hour() ==EEPROM.read(24) && now.minute() ==EEPROM.read(25)|| now.hour() ==EEPROM.read(26) && now.minute() ==EEPROM.read(27))
                       {
                                     digitalWrite(R,HIGH);
                                     lcd.createChar(2, CLOCHE);
                                     lcd.setCursor(13 ,1);
                                     lcd.write(byte(2));
                                     delay(7000);
                                     digitalWrite(R,LOW);
                                     RTC.adjust(DateTime(Annee,Mois,Jour,Heur,Min,8));
                                     
                                     
                       }
       
        else{ lcd.setCursor(13, 1); lcd.print(' ');}
    }

//******************* Alarme de Vendredi***********
if((now.dayOfTheWeek() == 5) && now.second()<8){ 
       if (now.hour() ==EEPROM.read(28) && now.minute() ==EEPROM.read(29)|| now.hour() ==EEPROM.read(30) && now.minute() ==EEPROM.read(31)||
          now.hour() ==EEPROM.read(32) && now.minute() ==EEPROM.read(33)|| now.hour() ==EEPROM.read(34) && now.minute() ==EEPROM.read(35)||
          now.hour() ==EEPROM.read(36) && now.minute() ==EEPROM.read(37)|| now.hour() ==EEPROM.read(38) && now.minute() ==EEPROM.read(39)||
          now.hour() ==EEPROM.read(40) && now.minute() ==EEPROM.read(41)|| now.hour() ==EEPROM.read(42) && now.minute() ==EEPROM.read(43)||
          now.hour() ==EEPROM.read(44) && now.minute() ==EEPROM.read(45)|| now.hour() ==EEPROM.read(46) && now.minute() ==EEPROM.read(47)||
          now.hour() ==EEPROM.read(48) && now.minute() ==EEPROM.read(49)|| now.hour() ==EEPROM.read(50) && now.minute() ==EEPROM.read(51)||
          now.hour() ==EEPROM.read(52) && now.minute() ==EEPROM.read(53)|| now.hour() ==EEPROM.read(54) && now.minute() ==EEPROM.read(55))
                       {
                                     digitalWrite(R,HIGH);
                                     lcd.createChar(2, CLOCHE);
                                     lcd.setCursor(13 ,1);
                                     lcd.write(byte(2));
                                     delay(7000);
                                     digitalWrite(R,LOW);
                                     RTC.adjust(DateTime(Annee,Mois,Jour,Heur,Min,8));
                       }
       
        else{ lcd.setCursor(13, 1); lcd.print(' ');}
    }
//******************* Alarme de Samedi***********
  if((now.dayOfTheWeek() == 6) && now.second()<8){ 
       if (now.hour() ==EEPROM.read(56) && now.minute() ==EEPROM.read(57)|| now.hour() ==EEPROM.read(58) && now.minute() ==EEPROM.read(59)||
          now.hour() ==EEPROM.read(60) && now.minute() ==EEPROM.read(61)|| now.hour() ==EEPROM.read(62) && now.minute() ==EEPROM.read(63)||
          now.hour() ==EEPROM.read(64) && now.minute() ==EEPROM.read(65)|| now.hour() ==EEPROM.read(66) && now.minute() ==EEPROM.read(67)||
          now.hour() ==EEPROM.read(68) && now.minute() ==EEPROM.read(69)|| now.hour() ==EEPROM.read(70) && now.minute() ==EEPROM.read(71)||
          now.hour() ==EEPROM.read(72) && now.minute() ==EEPROM.read(73)|| now.hour() ==EEPROM.read(74) && now.minute() ==EEPROM.read(75)||
          now.hour() ==EEPROM.read(76) && now.minute() ==EEPROM.read(77)|| now.hour() ==EEPROM.read(78) && now.minute() ==EEPROM.read(79)||
          now.hour() ==EEPROM.read(80) && now.minute() ==EEPROM.read(81)|| now.hour() ==EEPROM.read(82) && now.minute() ==EEPROM.read(83))
                       {
                                     digitalWrite(R,HIGH);
                                     lcd.createChar(2, CLOCHE);
                                     lcd.setCursor(13 ,1);
                                     lcd.write(byte(2));
                                     delay(7000);
                                     digitalWrite(R,LOW);
                                     RTC.adjust(DateTime(Annee,Mois,Jour,Heur,Min,8));
                       }
       
        else{ lcd.setCursor(13, 1); lcd.print(' ');}
    }  
}//end loop
void DisplayDateTime ()
{
// mostriamo la data e l'ora correnti
  DateTime now = RTC.now();
  lcd.clear();
  lcd.setCursor(0, 1);
  lcd.print("Time:");
  if (now.hour()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.hour(), DEC);
  Heur=now.hour();
  lcd.print(":");
  if (now.minute()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.minute(), DEC);
  Min=now.minute();
  lcd.print(":");
  if (now.second()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.second(), DEC);

  lcd.setCursor(0, 0);
switch(now.dayOfTheWeek())
    {
    case 1:  lcd.print("Lun:");  break;
    case 2:  lcd.print("Mar:");  break;
    case 3:  lcd.print("Merc:");  break;
    case 4:  lcd.print("Jeu:");  break;
    case 5:  lcd.print("Ven:"); break;
    case 6:  lcd.print("Sam:");  break;
    case 0:  lcd.print("Dim:");  break;
    default: lcd.print("Error");
    }
  if (now.day()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.day(), DEC);
  Jour=now.day();
  lcd.print("/");
  if (now.month()<=9)
  {
    lcd.print("0");
  }
  lcd.print(now.month(), DEC);
  Mois=now.month();
  lcd.print("/");
  lcd.print(now.year(), DEC);
  Annee=now.year();
}

void DisplaySetHour()
{
// Nouveauzione dell'ora
  lcd.clear();
  DateTime now = RTC.now();
  int ora=now.hour();
  if(between(val,400,500))
  {
    if(Heur==23)
    {
      Heur=0;
    }
    else
    {
      Heur=Heur+1;
    }
  }
   if(between(val,100,200))
  {
    if(Heur==0)
    {
      Heur=23;
    }
    else
    {
      Heur=Heur-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Nouveau Heure:");
  lcd.setCursor(0,1);
  lcd.print(Heur,DEC);
  delay(200);
}

void DisplaySetMinute()
{
  lcd.clear();
  if(between(val,400,500))
  {
    if (Min==59)
    {
      Min=0;
    }
    else
    {
      Min=Min+1;
    }
  }
   if(between(val,100,200))
  {
    if (Min==0)
    {
      Min=59;
    }
    else
    {
      Min=Min-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Nouveau Minute:");
  lcd.setCursor(0,1);
  lcd.print(Min,DEC);
  delay(200);
}
  
void DisplaySetYear()
{
  lcd.clear();
  if(between(val,400,500))
  {    
    Annee=Annee+1;
  }
   if(between(val,100,200))
  {
    Annee=Annee-1;
  }
  lcd.setCursor(0,0);
  lcd.print("Nouveau Annee:");
  lcd.setCursor(0,1);
  lcd.print(Annee,DEC);
  delay(200);
}

void DisplaySetMonth()
{
  lcd.clear();
  if(between(val,400,500))
  {
    if (Mois==12)
    {
      Mois=1;
    }
    else
    {
      Mois=Mois+1;
    }
  }
   if(between(val,100,200))
  {
    if (Mois==1)
    {
      Mois=12;
    }
    else
    {
      Mois=Mois-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Nouveau Mois:");
  lcd.setCursor(0,1);
  lcd.print(Mois,DEC);
  delay(200);
}

void DisplaySetDay()
{
  lcd.clear();
  if(between(val,400,500))
  {
    if (Jour==31)
    {
      Jour=1;
    }
    else
    {
      Jour=Jour+1;
    }
  }
   if(between(val,100,200))
  {
    if (Jour==1)
    {
      Jour=31;
    }
    else
    {
      Jour=Jour-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Nouveau Jour:");
  lcd.setCursor(0,1);
  lcd.print(Jour,DEC);
  delay(200);
}

void DateActuel()
{
   lcd.clear();
  lcd.setCursor(0,0);
  lcd.setCursor(0,1);
  RTC.adjust(DateTime(Annee,Mois,Jour,Heur,Min,0));
  delay(200);
}
bool between(int val,int a,int b)
 {
    if(a<val && val<b) return true;
    else return false;
 }
 int Halarm(int a,String b){
  lcd.clear();
  if(between(val,400,500))
  {
    if(Heur1==23)
    {
      Heur1=0;
    }
    else
    {
      Heur1=Heur1+1;
    }
  }
   if(between(val,100,200))
  {
    if(Heur1==0)
    {
      Heur1=23;
    }
    else
    {
      Heur1=Heur1-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print(b);
  lcd.print(":Alarme");
  lcd.print(a);
  lcd.setCursor(0,1);
  lcd.print("Heur : ");
  lcd.print(Heur1,DEC);
  delay(100);
  return Heur1;}
  int Malarm(int a,String b){
   lcd.clear();
  if(between(val,400,500))
  {
    if (Min1==59)
    {
      Min1=0;
    }
    else
    {
      Min1=Min1+1;
    }
  }
   if(between(val,100,200))
  {
    if (Min1==0)
    {
      Min1=59;
    }
    else
    {
      Min1=Min1-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print(b);
  lcd.print(":Alarme");
  lcd.print(a);
  lcd.setCursor(0,1);
  lcd.print("Min : ");
  lcd.print(Min1,DEC);
  delay(100);
  return Min1; 
  }
