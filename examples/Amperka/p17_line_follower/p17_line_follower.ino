
int leftLinePin = 10;
int rightLinePin = 11;

int leftDirPin = 4;
int leftSpeedPin = 5;

int rightDirPin = 7;
int rightSpeedPin = 6;

int runSpeed = 50;

void setupMotorShield()
{
    pinMode(leftDirPin, OUTPUT);
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightDirPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);
}

void go()
{
    analogWrite(leftSpeedPin, runSpeed);
    analogWrite(rightSpeedPin, runSpeed);
}

void stop()
{
    analogWrite(leftSpeedPin, 0);
    analogWrite(rightSpeedPin, 0);
}

void goForward()
{
    digitalWrite(leftDirPin, HIGH);
    digitalWrite(rightDirPin, HIGH);
    go();
}

void turnLeft()
{
    digitalWrite(leftDirPin, LOW);
    digitalWrite(rightDirPin, HIGH);
    go();
}

void turnRight()
{
    digitalWrite(leftDirPin, HIGH);
    digitalWrite(rightDirPin, LOW);
    go();
}

void setup()
{
    setupMotorShield();
}

void loop()
{
    // Считываем данные с сенсоров
    boolean whiteLeft = digitalRead(leftLinePin);
    boolean whiteRight = digitalRead(rightLinePin);

    if (whiteLeft && whiteRight) {
        // Под обоими датчиками белый цвет. Видимо
        // линия прямо под нами. Полный вперёд!
        goForward();
    } else if (!whiteLeft && !whiteRight) {
        // Что-то не то: под обоими датчиками чёрный
        // цвет. Видимо мы выехали за пределы трассы.
        // Лучше остановиться
        stop();
    } else if (whiteRight) {
        // Под левым датчиком — чёрный, под правым —
        // белый. Чтобы выровняться, нужно начать
        // поворот налево
        turnLeft();
    } else {
        // Последний оставшийся вариант. Под левым
        // датчиком — белый, под правым — чёрный.
        // Чтобы выровняться, нужно начать поворот
        // направо
        turnRight();
    }
}
