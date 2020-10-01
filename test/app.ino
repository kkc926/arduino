#include <Servo.h>
#include <Joystick.h>
#include <Led.h>
#include <MiniCom.h>

MiniCom com;
const int SERVO_PIN = 4;
Servo servo;
Joystick joy(A0, A1, 3);
bool mode = true;  // true : 주행모드 , false: 카메라 방향 모드
Led led(13);


void readJoystick() {
    joystick_value_t value = joy.read();
    if(mode) { //주행
        com.print(0,"x ","y ",value.x,value.y);
    } else {  //카메라
        servo.write(value.x); 
        com.print(0,"Angle",value.x);
    }
}

void changeMode() {
    mode = !mode;
    if(mode) { //주행
        joy.setRangeX(-255, 255); 
        led.off();
    } else { //카메라
        joy.setRangeX(0, 180); 
        led.on();
    }
}

void setup() {
    com.init();
    servo.attach(SERVO_PIN);
    joy.setRangeX(-255, 255);    
    joy.setRangeY(-255, 255);
    joy.setCallback(changeMode);
	com.setInterval(100, readJoystick);    
    led.off();
}

void loop() {
    joy.check();
    com.run();
}
