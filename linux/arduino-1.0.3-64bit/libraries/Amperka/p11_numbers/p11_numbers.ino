
int clockPin = 8; // Пин, соединённый с ножкой Clock
int resetPin = 9; // Пин, соединённый с ножкой Reset

void setup()
{
    pinMode(clockPin, OUTPUT);
    pinMode(resetPin, OUTPUT);
}
 
/*
    Функция, выводящая на индикатор заданное число
*/
void showNumber(int num) 
{
    // Посылаем импульс на ножку Reset
    // для того чтобы счётчик обнулился
    digitalWrite(resetPin, HIGH);
    digitalWrite(resetPin, LOW);


    // Подаём импульс на ножку драйвера Clock
    // пока счётчик, прибавляя по единице,
    // не накопит нужное нам число
    while (num--) {
        digitalWrite(clockPin, HIGH);
        digitalWrite(clockPin, LOW);    
    }
}

void loop()
{
    showNumber(4);
    delay(1000);  

    showNumber(8);
    delay(1000);  

    showNumber(15);
    delay(1000);  

    showNumber(16);
    delay(1000);  

    showNumber(23);
    delay(1000);  

    showNumber(42);
    delay(1000);  
}
