#include <LiquidCrystal_I2C.h>
// I2C 주소, 칸 수(X), 줄 수(Y)
LiquidCrystal_I2C lcd(0x27, 16, 2); //디바이스의 주소 0x27번지, 16칸, 2줄
void setup()
{
    lcd.init();          // LCD 초기화 // 안하면 출력안됨.
    lcd.backlight();     // 백라이트 켜기
    lcd.setCursor(3, 0); // 커서 위치 설정 (x,y)
    // 문자열 출력
    lcd.print("Hello, world!");
}
void loop()
{
    lcd.backlight();
    delay(1000);
    lcd.noBacklight();
    delay(1000);
}