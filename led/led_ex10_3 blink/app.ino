int pin_LED1 = 3;
int pin_LED2 = 5;
boolean LED_state1 = false;
boolean LED_state2 = false;
unsigned long time_previous1, time_current1;
unsigned long time_previous2, time_current2;
unsigned long count = 0;
void setup()
{
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    digitalWrite(pin_LED1, LED_state1);
    digitalWrite(pin_LED2, LED_state2);
    Serial.begin(9600);
    time_previous1 = millis();   
    time_previous2 = millis();
    
    //
}


void loop()
{
    blink_1000();
    blink_500();
}

 void blink_1000(){ //delay함수를 안쓰고 블링크 하는법
     time_current1=millis();
     if(time_current1 - time_previous1 >=1000){
         time_previous1 = time_current1;
         LED_state1 = !LED_state1;
         digitalWrite(pin_LED1,LED_state1);
     }
 }
  void blink_500(){
     time_current2=millis();
     if(time_current2 - time_previous2 >=500){
         time_previous2 = time_current2;
         LED_state2 = !LED_state2;
         digitalWrite(pin_LED2,LED_state2);
     }
 }