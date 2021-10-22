
int leftDirPin = 4;
int leftSpeedPin = 5;

int rightDirPin = 7;
int rightSpeedPin = 6;

// С какой скоростью должен двигаться робот
// Диапазон, как всегда для analogWrite: [0, 255]
int runSpeed = 50;

void setup()
{
    // Управляющие пины на стороне Motor Shield сигнал
    // принимают, но на стороне Arduino они сигнал
    // выдают, поэтому мы должны сделать их выходами.
    pinMode(leftDirPin, OUTPUT);
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightDirPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);

    // Установим оба канала в одном направлении
    digitalWrite(leftDirPin, HIGH);
    digitalWrite(rightDirPin, HIGH);

    // Установим оба канала на одинаковую скорость
    analogWrite(leftSpeedPin, runSpeed);
    analogWrite(rightSpeedPin, runSpeed);
}

void loop()
{
}
