
int termPin = A5; // Аналоговый пин с термистором
int ledPin = 6;   // Цифровой пин со светодиодом

void setup()
{
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // Считываем показания термистора и сравниваем
    // их с пороговым значением, принятым за «холод»
    if (analogRead(termPin) < 400) {
        // Если температура низкая включаем светодиод
        digitalWrite(ledPin, HIGH);
    } else {
        // В противном случае - выключаем.
        digitalWrite(ledPin, LOW);
    }
}
