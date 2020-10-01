int pin_LED = 13;
boolean LED_state = false;
unsigned long time_previous, time_current;
unsigned long count = 0;
void setup()
{
    pinMode(pin_LED, OUTPUT);
    digitalWrite(pin_LED, LED_state);
    Serial.begin(9600);
    time_previous = millis(); //
}
void loop()
{
    time_current = millis(); //현재시간
    count++;
    // 1초 이상 시간이 경과한 경우
    if (time_current - time_previous >= 1000) //현재시간-과거시간
    {
        time_previous = time_current; //기준시간 변경
        LED_state = !LED_state;
        digitalWrite(pin_LED, LED_state);
        Serial.println(count);
        count = 0;
    }
}