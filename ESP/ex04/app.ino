#include "WifiUtil.h"

const char SSID[] = "KT_GiGA_2G_Wave2_A8D7";
const char PASSWORD[] = "zf3cbb5696";
WifiUtil wifi(2, 3);
WiFiEspClient client;
void setup()
{
    Serial.begin(9600);
    wifi.init(SSID, PASSWORD);
    request();
}
void loop()
{
    response();
}

char server[] = "arduino.cc";

void request()
{
    // if you get a connection, report back via serial
    if (client.connect(server, 80))
    {
        Serial.println("Connected to server");
        // Make a HTTP request
        client.println("GET /asciilogo.txt HTTP/1.1");
        client.println("Host: arduino.cc");
        client.println("Connection: close");
        client.println();
    }
}
void response()
{
    while (client.available())
    {
        char c = client.read();
        Serial.write(c);
    }
}