#include "Button.h"

Button::Button(int pin) : pin(pin){
    pinMode(pin, INPUT_PULLUP); //하드웨어는 풀업
    state_previous = true;
    callback=NULL; //아무것도 지칭안할때 null씀
}

int Button::read(){
    return !digitalRead(pin); //소프트웨어는 풀다운으로 운영해야 확장성에 좋음 따라서 !를 붙임
}

void Button::setCallback(void(*callback)()){
    this->callback = callback;
}

int Button::check(){
    state_current=digitalRead(pin);
    if(!state_current){ //누른경우
        if(state_previous == true){
            state_previous=false;
            if(callback != NULL){
                
                callback();
            }
            
        }
        delay(5);
    
    }
    else
    {
        state_previous=true;
    }
}