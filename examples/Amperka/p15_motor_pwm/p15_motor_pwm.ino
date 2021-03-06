
int motorPin = 12; // Пин с транзистором
int potPin = A0; // Пин с потенциометром

void setup() 
{
    // Инициализируем пин, к которому подключён
    // транзистор, как работающий на вывод
    pinMode(motorPin, OUTPUT);  
}

void loop() 
{
    // Считываем значение потенциометра
    // и делим его на 4, т.к. значение analogRead
    // варьируется от 0 до 1023, а значение
    // ШИМ-сигнала от 0 до 255
    int val = analogRead(potPin) / 4;

    // Подаём на двигатель значение потенциометра
    analogWrite(motorPin, val);
}
