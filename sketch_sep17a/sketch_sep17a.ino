#include <WiFiEsp.h>
#include <SoftwareSerial.h>
SoftwareSerial softSerial(2, 3);       // RX, TX
char ssid[] = "KT_GiGA_2G_Wave2_A8D7"; // your network SSID (name)
char pass[] = "zf3cbb5696";            // your network password
int status = WL_IDLE_STATUS;           // the Wifi radio's status

void setup()
{
    Serial.begin(115200);
    softSerial.begin(9600);
    WiFi.init(&softSerial);            /////중요
    if (WiFi.status() == WL_NO_SHIELD) //exp가 안꽂혀있다.
    {
        Serial.println("WiFi shield not present");
        while (true)
            ;
    }
    while (status != WL_CONNECTED)
    {
        Serial.print("Attempting to connect to WPA SSID: ");
        Serial.println(ssid);
        status = WiFi.begin(ssid, pass); ////////중요
    }
    Serial.println("You're connected to the network");
    printWifiStatus();
}
void loop()
{
}
void printWifiStatus()
{
    // print the SSID of the network you're attached to
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    // print your WiFi shield's IP address
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    // print the received signal strength
    long rssi = WiFi.RSSI();
    Serial.print("Signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
