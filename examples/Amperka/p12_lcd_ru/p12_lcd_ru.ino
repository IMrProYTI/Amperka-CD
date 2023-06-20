
#include <LiquidCrystal.h>

int backlight = 3;
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup() 
{
    pinMode(backlight, OUTPUT);
    digitalWrite(backlight, HIGH);

    lcd.begin(16, 2);
    // Печатаем сообщение "Здравствуй, мир!"
    lcd.print("\xa4\xe3""pa\xb3""c\xbf\xb3\x79\xb9, "
              "\xbc\xb8""p!");
}

void loop()
{
    // Переходим на вторую строку
    lcd.setCursor(0, 1);   

    // Пишем количество секунд
    lcd.print(millis() / 1000);

    delay(1000);
}
