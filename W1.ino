#include<LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
int t = 0;
int wordn = 0;
#define MAXword 40
#define ROW(x) (x / 2)
#define COL(x) (x % 20)


void setup() {
Serial.begin(9600);
Serial.println("04050343  04050794");
lcd.begin(20, 2); 

lcd.cursor(); // 游標
lcd.blink(); // 游標閃爍
/* t = 0;
lcd.setCursor(0, 0); // 游標位置
lcd.print("04050343 KATA"); 
lcd.setCursor(0, 1); // 游標位置
lcd.print("04050794 YU");
*/
lcd.home();
}
char val;
void loop() {

if (Serial.available()) 
{
  
  val = Serial.read();
  if(32 <= val && val <= 126)
  {
    if(wordn == MAXword)
    {
      wordn = 0;
      lcd.clear();
    }
    lcd.write(val);
    //Serial.println(val);
    wordn++;
    lcd.setCursor((wordn%20),(wordn/20));



    
    }// ASCII if
   
  }//avialable if



}
