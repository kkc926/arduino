#pragma once

#include <Arduino.h>
#include <Led.h>

class PWMLed : public Led { //Led.h 상속
protected:

    int value;

public:
    PWMLed(int pin);

    int getValue();
    void fadeIn(int step=1);//점점밝게
    void fadeOut(int step=1);//점점어둡게
    void set(int value);
};