#include "Led.h"
#include "Button.h"

Led led(4);
Button btn(11);
void work()
{    led.toggle();

}

void setup()
{
    Serial.begin(9600);
   btn.setCallback(work);
}

// void(*포인터_변수명)(매개변수);
void (*workPtr)(); //매개변수 없고, 리턴타입이 void면 얘가 가리킴

void loop()
{

    btn.check();
}


