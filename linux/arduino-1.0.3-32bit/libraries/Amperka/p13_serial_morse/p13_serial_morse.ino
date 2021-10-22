
int soundPin = 13; // Номер пина с пищалкой
int dotDelay = 50; // Время длительности «точки»

long time; // Вспомогательная переменная
int rate = 100; // Период колебания в микросекундах. 
                // Чем больше период, тем ниже частота

void sound(int duration)
{
     time = millis();
     while (millis() - time < duration) {
         digitalWrite(soundPin, HIGH);
         delayMicroseconds(rate);
         digitalWrite(soundPin, LOW);
         delayMicroseconds(rate);
     }
}

// Точка
void dot() 
{
    sound(dotDelay);
    delay(dotDelay);
}

// Тире
void dash() 
{
    sound(3 * dotDelay);
    delay(dotDelay);
}

// Окончание буквы
void letterEnd() 
{
    delay(2 * dotDelay);
}

// Окончание слова
void wordEnd() 
{
    delay(6 * dotDelay);
}

// Буква
void morseLetter(char c) 
{
    switch (c) {
        case 'a': dot();dash(); break;
        case 'b': dash();dot();dot();dot(); break;
        case 'c': dash();dot();dash();dot(); break;
        case 'd': dash();dot();dot(); break;
        case 'e': dot(); break;
        case 'f': dot();dot();dash();dot(); break;
        case 'g': dash();dash();dot(); break;
        case 'h': dot();dot();dot(); break;
        case 'i': dot();dot(); break;
        case 'j': dot();dash();dash();dash(); break;
        case 'k': dash();dot();dash(); break;
        case 'l': dot();dash();dot();dot(); break;
        case 'm': dash();dash(); break;
        case 'n': dash();dot(); break;
        case 'o': dash();dash();dash(); break;
        case 'p': dot();dash();dash();dot(); break;
        case 'q': dash();dash();dot();dash(); break;
        case 'r': dot();dash();dot(); break;
        case 's': dot();dot();dot(); break;
        case 't': dash(); break;
        case 'u': dot ();dot();dash(); break;
        case 'v': dot();dot();dot();dash(); break ;
        case 'w': dot();dash();dash(); break;
        case 'x': dash();dot();dot();dash(); break;
        case 'y': dash();dot();dash();dash(); break;
        case 'z': dash();dash();dot();dot(); break;
        case ' ': wordEnd(); break;
    }
    letterEnd();
}

void setup() 
{
    pinMode(soundPin, OUTPUT);
    Serial.begin(9600);
}

void loop() 
{
    // Если есть не считанный байт
    if (Serial.available() > 0) {
        // Считываем его... 
        char c = Serial.read();

        // ...и воспроизводим на азбуке Морзе
        morseLetter(c);
    }
}
