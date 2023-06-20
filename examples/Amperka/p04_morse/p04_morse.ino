
int ledPin = 13; // Номер пина со светодиодом
int dotDelay = 200; // Время длительности «точки»

// Точка
void dot()
{
    digitalWrite(ledPin, HIGH);
    delay(dotDelay);
    digitalWrite(ledPin, LOW);
    delay(dotDelay);
}

// Тире
void dash()
{
    digitalWrite(ledPin, HIGH);
    delay(3 * dotDelay);
    digitalWrite(ledPin, LOW);
    delay(dotDelay);
}

// Конец буквы
void letterEnd() 
{
    delay(2 * dotDelay);
}

// Конец слова
void wordEnd()
{
    delay(6 * dotDelay);
}


// Буква S
void letterS()
{
    dot();
    dot();
    dot();
    letterEnd();
}

// Буква O
void letterO()
{
    dash();
    dash();
    dash();
    letterEnd();
}

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop(){
    letterS(); // Показываем букву S
    letterO(); // Показываем букву O
    letterS(); // Показываем букву S
    wordEnd(); // Делаем паузу между словами
}
