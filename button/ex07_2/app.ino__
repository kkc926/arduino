#include "Led.h"

Led led(4);

boolean state_previous = true;
boolean state_current;
int count = 0;
void setup()
{
    Serial.begin(9600);

}

void work()
{    led.toggle();

}
void loop()
{

    led.set(!state_current);
}