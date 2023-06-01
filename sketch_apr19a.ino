#include<LiquidCrystal.h>
LiquidCrystal lcd(2,3,4,5,6,7);

#define out 8
#define in 9
#define relay 10
#define metal 12

int count=0;

void IN()
{
count++;
lcd.clear();
lcd.print("Person In Room:");
lcd.setCursor(0,1);
lcd.print(count);
delay(1000);
}

void OUT()
{
if(count>0)
count--;
lcd.clear();
lcd.print("Person In Room:");
lcd.setCursor(0,1);
lcd.print(count);
delay(1000);
}

void setup()
{
lcd.begin(16,2);
lcd.print("Visitor Counter");
delay(2000);
pinMode(in, INPUT);
pinMode(out, INPUT);
pinMode(relay, OUTPUT);
pinMode(metal, INPUT);
lcd.clear();
lcd.print("Person In Room:");
lcd.setCursor(0,1);
lcd.print(count);

pinMode(A0, OUTPUT);

digitalWrite(relay, LOW);

}

void loop()
{

if(digitalRead(in)){
IN();}
if(digitalRead(out)){
OUT();}
if(digitalRead(metal))
digitalWrite(relay, LOW);
else
digitalWrite(relay, HIGH);


if(count==0)
{
lcd.clear();
//digitalWrite(relay, HIGH);
lcd.clear();
lcd.print("Nobody In Room");
lcd.setCursor(0,1);
lcd.print("Light Is Off");

digitalWrite(A0, LOW);
delay(1000);
} else {
  digitalWrite(A0, HIGH);
}

} 
