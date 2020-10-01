int pin_LED = 7;

boolean LED_state = false;


void setup() {
  // put your setup code here, to run once:
  pinMode(pin_LED, OUTPUT);
  digitalWrite(pin_LED, LED_state);
}

void loop() {
  // put your main code here, to run repeatedly:
  LED_state = !LED_state;
  digitalWrite(pin_LED, LED_state);
  delay(300);
}
