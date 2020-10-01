#pragma once

#include <Arduino.h>

class Ultra{
    protected:
        int echo;
        int trig;
        
    public:
        Ultra(int echo, int trig);
        int read(); //거리를 측정하는 기능

};