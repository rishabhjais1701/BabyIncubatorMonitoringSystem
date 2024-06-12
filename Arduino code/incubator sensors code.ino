#include <SoftwareSerial.h>
#include "DHT.h"
#include<LiquidCrystal.h>
#define RX 2
#define TX 3
#define dht_apin 11 // Analog Pin sensor is connected to
DHT dhtObject;
String AP = "Galaxy M51";       // AP NAME
String PASS = "PRAVIN@123"; // AP PASSWORD
String API = "6QDMSCNRKEK951YI";   // Write API KEY
String HOST = "api.thingspeak.com";
String PORT = "80";
int countTrueCommand;
int countTimeCommand; 
boolean found = false; 
int valSensor = 1;

const int rs = 13, en = 12, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
  
SoftwareSerial SER(RX,TX); 
  
void setup() 
{
  Serial.begin(9600);
  SER.begin(115200);
  lcd.begin(16,2);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  dhtObject.setup(11);
  sendCommand("AT",5,"OK");
  sendCommand("AT+CWMODE=1",5,"OK");
  sendCommand("AT+CWJAP=\""+ AP +"\",\""+ PASS +"\"",20,"OK");
}

void loop() {

  float temperature = dhtObject.getTemperature();
  float humidity = dhtObject.getHumidity();
  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.print(temperature);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY:");
  lcd.print(humidity);
  lcd.print("%");
    if(temperature>=37)
   {
      digitalWrite(8,LOW);//FAN
      digitalWrite(9,HIGH);
   }
   else if(temperature<27)
   {
      digitalWrite(8,HIGH);
      digitalWrite(9,LOW);//LIGHT
   }
   if(humidity<92)
   {
      digitalWrite(10,LOW);//HUMIDIFIER
   }
   else
   {
     digitalWrite(10,HIGH);
   }
  
 String getData = "GET /update?api_key="+ API +"&field1="+getTemperatureValue()+"&field2="+getHumidityValue();
 sendCommand("AT+CIPMUX=1",5,"OK");
 sendCommand("AT+CIPSTART=0,\"TCP\",\""+ HOST +"\","+ PORT,15,"OK");
 sendCommand("AT+CIPSEND=0," +String(getData.length()+4),4,">");
 SER.println(getData);
 delay(1500);
 countTrueCommand++;
 sendCommand("AT+CIPCLOSE=0",5,"OK");
 
}


String getTemperatureValue(){

   //delay(dhtObject.getMinimumSamplingPeriod());
   float temperature = dhtObject.getTemperature();
   Serial.print(" Temperature(C)= ");
   Serial.println(temperature); 
   return String(temperature); 
  
}


String getHumidityValue(){

   //delay(dhtObject.getMinimumSamplingPeriod());
   float humidity = dhtObject.getHumidity();
   Serial.print(" Humidity in %= ");
   Serial.println(humidity);
   return String(humidity); 
  
}

void sendCommand(String command, int maxTime, char readReplay[]) {
  Serial.print(countTrueCommand);
  Serial.print(". at command => ");
  Serial.print(command);
  Serial.print(" ");
  while(countTimeCommand < (maxTime*1))
  {
    SER.println(command);//at+cipsend
    if(SER.find(readReplay))//ok
    {
      found = true;
      break;
    }
  
    countTimeCommand++;
  }
  
  if(found == true)
  {
    Serial.println("SUCCESS");
    countTrueCommand++;
    countTimeCommand = 0;
  }
  
  if(found == false)
  {
    Serial.println("Fail");
    countTrueCommand = 0;
    countTimeCommand = 0;
  }
  
  found = false;
 }
