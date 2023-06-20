
int soundPin = 13; // Номер пина с пищалкой
int dotDelay = 50; // Время длительности «точки»

char theword[] = "sos";

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


// Слово
void morseWord(char theword[])
{
    int len = strlen(theword);
    for(int i  = 0; i < len; ++i)
        morseLetter(theword[i]);
    wordEnd();
}

// Буква
void morseLetter(char c)
{
    // не красивая, но компактная запись уже
    // встречавшегося выражения для сопоставления
    // букв и их кодов в азбуке Морзе
    switch(c) {
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
        case 'u': dot();dot();dash(); break;   
        case 'v': dot();dot();dot();dash(); break;   
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
}

void loop()
{
    morseWord(theword);
}
