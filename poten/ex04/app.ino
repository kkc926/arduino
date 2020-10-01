#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int ledPin=3;
const int potentionmeterPin = A0;

int potentionmeterValue;
int brightness;

void setup()
{
    Serial.begin(9600);
    lcd.init();          // LCD 초기화 // 안하면 출력안됨.
    lcd.backlight();     // 백라이트 켜기
    lcd.setCursor(3, 0); // 커서 위치 설정 (x,y)
}

void loop(){

    char buf[17];

    potentionmeterValue = analogRead(potentionmeterPin);

    sprintf(buf, "org : %4d", potentionmeterValue);
    lcd.setCursor(0,0);
    lcd.print(buf);


    // brightness = map(potentionmeterValue,0,1023,0,255);
    brightness = map(potentionmeterValue,0,1023,255,0);

    sprintf(buf, "bright : %4d", brightness);
    lcd.setCursor(0,1);
    lcd.print(buf);

    analogWrite(ledPin, brightness);
}