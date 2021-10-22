
int buttonPin = 2; // пин с кнопкой
int ledPin = 13;  // пин со светодиодом

// состояние кнопки: зажата/отжата
boolean buttonState = LOW; 

void setup()
{
    pinMode(ledPin, OUTPUT);      

    // настраиваем пин с кнопкой как вход
    pinMode(buttonPin, INPUT);     
}

void loop()
{
    // считываем показания кнопки
    buttonState = digitalRead(buttonPin); 

    if (buttonState == HIGH) {     
        // если кнопка нажата включаем светодиод
        digitalWrite(ledPin, HIGH);  
    } else {
        // если кнопка отжата включаем светодиод
        digitalWrite(ledPin, LOW);
    }
}
