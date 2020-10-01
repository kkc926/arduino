#include <LiquidCrystal_I2C.h>
#include "PWMLed.h"
#include <AnalogSensor.h>


PWMLed led(3);

AnalogSensor poten(A0, 0, 180);

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
    Serial.begin(9600);
    lcd.init();          // LCD 초기화 // 안하면 출력안됨.
    lcd.backlight();     // 백라이트 켜기
    lcd.clear();
}

void loop(){
    char buf[17];

    int brightness = poten.read();
    led.set(brightness);

    sprintf(buf, "bright : %4d", brightness);
    lcd.setCursor(0,0);
    lcd.print(buf);


}