int pin_LED1 = 4;
int pin_LED2 = 3;
int pin_button = 11;
boolean LED_state = false;
unsigned long time_previous, time_current;
void setup()
{
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED1, LED_state);
    digitalWrite(pin_LED2, false);
    pinMode(pin_button, INPUT_PULLUP);
    time_previous = millis();
}
void loop()
{
    time_current = millis();
    // 1초 이상 시간이 경과한 경우
    if (time_current - time_previous >= 1000)
    {
        LED_state = !LED_state;
        digitalWrite(pin_LED1, LED_state);
        time_previous = time_current;
    }
    // 버튼 상태를 읽어서 13번 핀에 연결된 LED에 표시
    digitalWrite(pin_LED2, !digitalRead(pin_button));
}