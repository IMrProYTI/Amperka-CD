
int pin1 = 11;
int pin2 = 12;

void setup()
{
    pinMode(pin1, OUTPUT);
    pinMode(pin2, OUTPUT);
}

void loop() 
{
   digitalWrite(pin2, LOW);
   digitalWrite(pin1, HIGH);
   delay(500);

   digitalWrite(pin1, LOW);
   digitalWrite(pin2, HIGH);
   delay(500);
}
