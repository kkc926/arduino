#include <MiniCom.h>
#include <Servo.h>
#include "Ultra.h"
#include <Led.h>
#include "Pulse.h"


MiniCom com;
Ultra ultra (2,3);
Led led(8);
Servo servo;
Pulse pulse(100,500);

int delayTimes[]={
    50,100,200,300,500,1000
};

void pulseCallback(int value){
    //LED 제어
    led.set(value);
}

void checkDistance(){
    int distance = ultra.read();
    com.print(0,"Distance" ,distance);
    if(distance<10){                    ///////low의길이와 디스턴스가 비례하도록 하여 신호 주기를 조절
        // led.on();
        //Pulse의 offDelay를 distance를 고려하여 조정
        int offDelay = map(distance,0,9,0,5);
        // int offDelay = map(distance,0,9,50,1000); //딜레이 타임을 균등하게 나눔, 거리에따라 조절이안됨 멀든 가깝든
        pulse.setDelay(10,delayTimes[offDelay]);
        servo.write(90);
        if(!pulse.getState()){ //처음 10cm이하로 됐을때
            pulse.play();
        }
    }else
    {   if(pulse.getState()){
        pulse.stop();
    }
        // led.off();
        servo.write(0);
    }
    
}
void setup()
{   com.init();
    servo.attach(9);
    servo.write(0);
    com.setInterval(1000,checkDistance);
    pulse.setCallback(pulseCallback);
}
void loop()
{
    com.run();
    pulse.run();
}