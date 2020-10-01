int LED = 3;
void setup()
{
    pinMode(LED, OUTPUT);
}
void loop()
{
    int readVal = analogRead(A0);
    int brightVal = readVal / 4; //아날로그는 1023// led 255이라 4로 나눔
    analogWrite(LED, brightVal);
    delay(10);
}
