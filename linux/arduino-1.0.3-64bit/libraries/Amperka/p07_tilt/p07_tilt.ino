
int ledPin = 13;  // Пин со светодиодом
int switcher = 3; // Пин с датчиком наклона
boolean tilt;     // Наклонён ли датчик?
 
void setup()
{
    // Инициализируем пин со светодиодом 
    // как работающий на вывод
    pinMode(ledPin, OUTPUT);

    // Инициализируем пин с датчиком
    // как работающий на ввод
    pinMode(switcher, INPUT); 
}

void loop()
{
    // Читаем значение сенсора
    tilt = digitalRead(switcher);

    if (tilt == HIGH) { 
        // Включаем светодиод, если датчик наклонён
        digitalWrite(ledPin, HIGH);   
    } else {
        // Выключаем, если не наклонён
        digitalWrite(ledPin, LOW);    
    }
}
