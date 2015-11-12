#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN A0
#define DHTTYPE DHT11

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 
DHT dht(DHTPIN, DHTTYPE);
  
void setup()
{

  lcd.begin(16, 2); 
  delay(2000);//Aguarda 1 seg antes de acessar as informações do sensor
}
 
void loop() {
  lcd.clear();

  float temperatura = dht.readTemperature(); // padrão é celsius
  float humidade = dht.readHumidity();
  
  lcd.setCursor(0, 0); 
  lcd.print(temperatura);
  lcd.setCursor(0, 1); 
  lcd.print(humidade);
  delay(10000); 
}

