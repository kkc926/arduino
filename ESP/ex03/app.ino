#include "WifiUtil.h"
const char SSID[] = "KT_GiGA_2G_Wave2_A8D7";
const char PASSWORD[] = "zf3cbb5696";

WifiUtil wifi(2, 3);
void setup()
{
    Serial.begin(9600);
    wifi.init(SSID, PASSWORD);
}
void loop()
{
    if (wifi.check())
    { // WIFI 연결 확인
        ;
    }
}