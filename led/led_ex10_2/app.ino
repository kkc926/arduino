int pin_LED1 = 3;
int pin_LED2 = 5;
boolean LED_state = false;
unsigned long time_previous, time_current;
unsigned long count = 0;
void setup()
{
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED1, LED_state);
    digitalWrite(pin_LED2, LED_state);
    Serial.begin(9600);
    time_previous = millis(); //
}

 void blink_1000(){
     digitalWrite(pin_LED1, HIGH);
     delay(1000);
     digitalWrite(pin_LED1,LOW);
     delay(1000);
 }
 void blink_500(){
    digitalWrite(pin_LED2, HIGH);
    delay(500);
    digitalWrite(pin_LED2, LOW);
    delay(500);
    }

void loop()
{
    blink_1000();
    blink_500();
}