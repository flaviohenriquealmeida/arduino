#include <LiquidCrystal.h>
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

const int gasPin = 0;

int valGas = 0;
 
void setup()
{

  lcd.begin(16, 2); 
  lcd.setCursor(0, 0); 
  lcd.print("% Gas no ar"); 
  lcd.setCursor(0, 1);
}
 
void loop() {
  
  lcd.setCursor(1, 1);
  valGas = analogRead(gasPin);
  lcd.print(valGas); 
  delay(200); 
}

