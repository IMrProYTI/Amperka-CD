
int potPin = A2; // Аналоговый пин с потенциометром
int ledPin = 6;  // Цифровой пин со светодиодом
int val = 0;     // Значение потенциометра

void setup() 
{
    pinMode(ledPin, OUTPUT);
}

void loop() 
{
    // Считываем значение потенциометра
    val = analogRead(potPin);        

    // Т.к. значение аналогового сигнала варьируется
    // от 0 до 1023, а ШИМ-сигнала - от 0 до 255,
    // поделим полученное значение на 4
    val /= 4;

    // Подаём на светодиод ШИМ-сигнал,
    // пропорциональный сигналу с потенциометра
    analogWrite(ledPin, val);      
}
