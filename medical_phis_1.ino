#include <LiquidCrystal.h>
#define trigpin 13
#define echopin 11
#define buzzer 8
float time,spead_of_sound,temprature;
float distance=150; //initialize the distance in cm!!

LiquidCrystal lcd_1(12, 9, 5, 4, 3, 2);

void setup()
{
  pinMode(buzzer,OUTPUT);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  lcd_1.begin(16, 2);
  lcd_1.print("Temprature is:");
}

void loop()
{
  lcd_1.setCursor(0, 1);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2000); // Wait for 1000 millisecond(s) 
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10); // Wait for 1000 millisecond(s)
  digitalWrite(trigpin, LOW);
  time = pulseIn(echopin , HIGH);
  spead_of_sound = 20000*distance/time;
  //Serial.println(spead_of_sound);
  temprature = (spead_of_sound*spead_of_sound)/(1.4*287);
  //temprature=(spead_of_sound-331.4)/0.6;
  lcd_1.print(temprature-273);
  lcd_1.print(" C   ");
  if((temprature-273)>30||(temprature-273)<20)digitalWrite(buzzer,HIGH);
  else digitalWrite(buzzer,LOW);
  delay(1000); // Wait for 1000 millisecond(s)
}

