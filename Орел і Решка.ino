/* 
Підключення схеми: 
Екран - Ардуїно
GND   - GND
VCC   - 5V
SCL   - A5
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);  // Устанавливаем дисплей

// ВСТУП
short timeStart1 = 250;
short timeStart2 = 500;
short timeStart3 = 3000;

// ЗАПУСК
long randNumber;

void setup()
{
  // ВСТУП
  lcd.init();                     
  lcd.backlight();
  lcd.setCursor(4,0);
  lcd.print("E");
    delay(timeStart1);
  lcd.print("L");
    delay(timeStart1);
  lcd.print("E");
    delay(timeStart1);
  lcd.print("K");
    delay(timeStart1);
  lcd.print("T");
    delay(timeStart1);
  lcd.print("R");
    delay(timeStart1);
  lcd.print("O");
    delay(timeStart2);
  lcd.setCursor(6, 1);
  lcd.print("C");
  delay(timeStart1);
  lcd.print("E");
  delay(timeStart1);
  lcd.print("N");
  delay(timeStart1);
  lcd.print("T");
  delay(timeStart3);

  // ЗАПУСК
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  
  // СТВОРЕННЯ РАНДОМУ
  Serial.begin(9600);
  randomSeed(analogRead(0));
  randNumber = random(2);
  
  // ВИВЕДЕННЯ ВІДПОВІДІ
  if (randNumber == 0){
    lcd.setCursor(6, 0);
    lcd.print("OREL");
  }
  else if (randNumber == 1){
    lcd.setCursor(5, 1);
    lcd.print("RESHKA");
  }
  else {
    lcd.setCursor(4, 1);
    lcd.print("ERROR");
  }
}
