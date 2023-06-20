
int brightness = 255; // текущее значение яркости
int fadeAmount = 5;   // скорость затухания

// пины, на которых расположен светодиод
int leds[3] = {9, 10, 11}; 
                           
// индексы пинов, с которыми мы работаем
// в текущий момент
int curPin[2] = {0, 1};

void setup()  
{
    for(int i = 0; i < 3; i++)
        pinMode(leds[i], OUTPUT);
}

void loop()  
{
    // подаём на два разных пина значение равное
    // brightness и 255-brightness
    analogWrite(leds[curPin[0]], brightness);   
    analogWrite(leds[curPin[1]], 255 - brightness);

    // уменьшаем значение brightness
    // на скорость затухания
    brightness = brightness - fadeAmount; 

    // когда значение brightness становится равным
    // нулю, меняем номера пинов, с которыми мы
    // работаем
    if (brightness == 0) {
        curPin[0] = (curPin[0] + 1) % 3;
        curPin[1] = (curPin[1] + 1) % 3;
        brightness = 255;
    }

    delay(30);                            
}
