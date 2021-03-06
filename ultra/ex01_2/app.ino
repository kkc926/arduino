#include <MiniCom.h>

MiniCom com;

int echoPin = 2;
int triggerPin = 3;

void checkDistance(){
    //trigger 핀으로 10us의 펄스를 발생
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);

    //echo핀 입력으로부터 거리를 cm단위로 계산
        int distance = pulseIn(echoPin, HIGH) / 58;
   com.print(0,"Distance" ,distance);
}
void setup()
{   com.init();
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
    com.setInterval(1000,checkDistance);
}
void loop()
{
    com.run();
}