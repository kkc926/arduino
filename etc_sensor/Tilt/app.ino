int Led = 13;//기울이면 led에 불이들어옴
int buttonpin = 3;
int val;
void setup()
{
    pinMode(Led, OUTPUT);
    pinMode(buttonpin, INPUT);
}
void loop()
{
    val = digitalRead(buttonpin);
    if (val == HIGH)
    {
        digitalWrite(Led, HIGH);
    }
    else
    {
        digitalWrite(Led, LOW);
    }
}