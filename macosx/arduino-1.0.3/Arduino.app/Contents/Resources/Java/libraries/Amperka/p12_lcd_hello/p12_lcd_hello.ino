
// Подключаем библиотеку
#include <LiquidCrystal.h>

// При помощи пина 3 мы будем управлять подсветкой
int backlight = 3;    

// Инициализируем пины, по которым будет
// производиться обмен данными с дисплеем
LiquidCrystal lcd(4, 6, 10, 11, 12, 13);

void setup()
{
    // Включаем подсветку
    pinMode(backlight, OUTPUT);
    digitalWrite(backlight, HIGH); 

    // Выставляем количество колонок и строк
    lcd.begin(16, 2);

    // Выводим приветствие
    lcd.print("Hello world!");
}

void loop() 
{
}
