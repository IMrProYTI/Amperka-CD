
int leftDirPin = 4;
int leftSpeedPin = 5;

int rightDirPin = 7;
int rightSpeedPin = 6;

int runSpeed = 50;

void setup()
{
    pinMode(leftDirPin, OUTPUT);
    pinMode(leftSpeedPin, OUTPUT);
    pinMode(rightDirPin, OUTPUT);
    pinMode(rightSpeedPin, OUTPUT);

    // Установим оба канала на одинаковую скорость…
    analogWrite(leftSpeedPin, runSpeed);
    analogWrite(rightSpeedPin, runSpeed);

    // …но правый пусть будет крутиться вперёд,
    // а левый - назад. Так, платформа должна
    // крутиться на месте, поворачивая всё время
    // налево, т.е. против часовой стрелки
    digitalWrite(leftDirPin, LOW);
    digitalWrite(rightDirPin, HIGH);
}

void loop()
{
}
