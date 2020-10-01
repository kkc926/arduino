#include "PWMLed.h"

PWMLed::PWMLed(int pin) : Led(pin), value(0){ //부모의 디폴트 생성자가 없을때 :Led(pin)을 안써주면 에러가남


}

int PWMLed::getValue(){
    return value;

}

//점점밝아지게
void PWMLed::fadeIn(int step){
    value += step;
    if (value>255){
        value = 0;
    }
    analogWrite(pin,value);

}

//점점어둡게
void PWMLed::fadeOut(int step){
    value -= step;
    if (value<0){
        value = 255;
    }
    analogWrite(pin,value);

}
//set override
void PWMLed::set(int value){
    analogWrite(pin,value);
}