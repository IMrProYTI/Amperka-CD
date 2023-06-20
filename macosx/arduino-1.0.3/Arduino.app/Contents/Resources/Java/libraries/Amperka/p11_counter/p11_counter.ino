
int clockPin = 8; // Пин, соединённый с ножкой Clock
int resetPin = 9; // Пин, соединённый с ножкой Reset

void setup() 
{
    pinMode(clockPin, OUTPUT);
    pinMode(resetPin, OUTPUT);   
    
    // Посылаем импульс на ножку Reset
    // для того, чтобы счётчик обнулился
    digitalWrite(resetPin, HIGH);
    digitalWrite(resetPin, LOW);
}

void loop(){
    // Посылаем импульс на ножку Clock
    // для того, чтобы добавить к счётчику единицу
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);
    // Ждём полсекунды
    delay(500);  
}
