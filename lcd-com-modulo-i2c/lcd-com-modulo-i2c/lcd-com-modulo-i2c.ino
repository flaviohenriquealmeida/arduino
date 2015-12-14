#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x3F

LiquidCrystal_I2C lcd(I2C_ADDR,2,1,0,4,5,6,7,3, POSITIVE);

void setup()
{

  lcd.begin(16, 2); 
  delay(2000);//Aguarda 1 seg antes de acessar as informações do sensor
}
 
void loop() {
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("Arduino e Cia !!");
  lcd.setCursor(0,1);
  lcd.print("LCD e modulo I2C");
  delay(1000);
  lcd.setBacklight(LOW);
  delay(1000);
}
