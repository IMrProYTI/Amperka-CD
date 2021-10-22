
int buttonPin = 2; // пин с кнопкой
int ledPin = 13; // пин со светодиодом

// состояние светодиода
boolean ledState = HIGH;

// предыдущее состояние кнопки
boolean lastButtonState = LOW; 

void setup() 
{
    pinMode(ledPin, OUTPUT);      
    pinMode(buttonPin, INPUT);     
}

void loop() 
{
    // считываем показание кнопки
    boolean reading = digitalRead(buttonPin); 

    // Если кнопка зажата, и при этом в предыдущий
    // раз она была отжата, значит «клик» произошёл
    // именно сейчас. Меняем состояние светодиода.
    if (reading && !lastButtonState) {
        ledState = !ledState;
        digitalWrite(ledPin, ledState);
    }

    // запоминаем состояние кнопки для последующего
    // прогона цикла loop
    lastButtonState = reading;  
}
