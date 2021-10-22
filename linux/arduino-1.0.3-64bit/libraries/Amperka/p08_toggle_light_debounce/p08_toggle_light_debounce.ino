
int buttonPin = 2; // пин с кнопкой
int ledPin =  13; // пин со светодиодом

// состояние светодиода
boolean ledState = HIGH; 

// предыдущее состояние кнопки
boolean lastButtonState = LOW; 

void setup()
{
    pinMode(buttonPin, INPUT);
    pinMode(ledPin, OUTPUT);
}

void loop()
{
    // считываем показание кнопки
    boolean reading = digitalRead(buttonPin); 

    // если состояние кнопки изменилось,
    // ждём 100 мс и проверяем ещё раз
    if (reading != lastButtonState) {
        // ждём
        delay(100);

        // снова считываем показание кнопки
        reading = digitalRead(buttonPin); 

        // если текущее состояние снова не
        // равно предыдущему, значит это не шум
        if(reading != lastButtonState){
            // запоминаем новое состояние кнопки
            // для последующего прогона loop
            lastButtonState = reading;

            // если кнопка была-таки нажата, а не
            // отжата, изменяем состояние светодиода
            if (reading) {
                ledState = !ledState;
                digitalWrite(ledPin, ledState);
            }
        }
    }
}
