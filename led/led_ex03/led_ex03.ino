int pin_LED = 07;
void setup()
{
    pinMode(pin_LED, OUTPUT);
}
void loop()
{
    digitalWrite(pin_LED, HIGH);
    delay(500);
    digitalWrite(pin_LED, LOW);
    delay(500);
    digitalWrite(pin_LED, HIGH);
    delay(1000);
    digitalWrite(pin_LED, LOW);
    delay(1000);
    digitalWrite(pin_LED, HIGH);
    delay(2000);
    digitalWrite(pin_LED, LOW);
    delay(2000);
}
