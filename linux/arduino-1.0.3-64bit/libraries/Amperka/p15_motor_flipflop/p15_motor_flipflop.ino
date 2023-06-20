
int motorPin = 12; // Пин с транзистором

void setup() 
{
    // Инициализируем пин, к которому подключён
    // транзистор, как работающий на вывод
    pinMode(motorPin, OUTPUT);  
}

void loop() 
{
    // Закрываем «кран» на 2 секунды
    digitalWrite(motorPin, LOW);
    delay(2000);  

    // Открываем «кран» на 2 секунды
    digitalWrite(motorPin, HIGH);
    delay(2000);
}
