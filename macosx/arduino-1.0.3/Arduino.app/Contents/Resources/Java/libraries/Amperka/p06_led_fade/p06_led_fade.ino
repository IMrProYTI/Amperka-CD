
int brightness = 0; // изначальная яркость светодиода
int fadeAmount = 5; // скорость затухания/нарастания 
                    // яркости

void setup()
{
    // инициализируем пин 9, как работающий на выход
    pinMode(9, OUTPUT);
}

void loop()
{
    // изменяем яркость светодиода
    analogWrite(9, brightness);    

    // на каждом шаге увеличиваем яркость
    // на скорость затухания
    brightness = brightness + fadeAmount;

    // в конце затухания меняем его на 
    // нарастание яркости и наоборот
    if (brightness == 0 || brightness == 255)
        fadeAmount = -fadeAmount;

    // ждём 30 миллисекунд   
    delay(30);                            
}
