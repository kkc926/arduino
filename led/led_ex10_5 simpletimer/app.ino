
#include <SimpleTimer.h>
int pin_LED1 = 3;
int pin_LED2 = 5;
int pin_LED3 = 7; 

SimpleTimer timer;

void blink_1000(){
    int state = digitalRead(pin_LED1); //현재 led가 켜져있으면 1을 state에 리턴해줌 꺼져있으면 0을 리턴
    digitalWrite(pin_LED1, !state);// 위의 값을 바꿔줌 켜있었으면 끔, 꺼있었으면 킴
}

void blink_500(){
int state = digitalRead(pin_LED2);
    digitalWrite(pin_LED2, !state);

}
void blink_200(){
int state = digitalRead(pin_LED3);
    digitalWrite(pin_LED3, !state);

}

void setup(){
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);
    timer.setInterval(1000,blink_1000);
    timer.setInterval(500,blink_500);
    timer.setInterval(200,blink_200);

}

 void loop(){
    timer.run();
 }