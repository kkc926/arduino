#include <SoftwareSerial.h>
#include <WiFiEsp.h>
#include <PubSubClient.h>
#include <SimpleTimer.h>
#include "WifiUtil.h"



const char ssid[] = "KT_GiGA_2G_Wave2_A8D7"; // 네트워크 SSID
const char password[] = "zf3cbb5696";        // 비밀번호
const char mqtt_server[] = "172.30.1.34";    // 서버 주소

// MQTT용 WiFi 클라이언트 객체 초기화
WiFiEspClient espClient;
PubSubClient client(espClient);
WifiUtil wifi(2, 3); // rx/tx 사용
SimpleTimer timer;

void callback(char *topic, byte *payload, unsigned int length)
{
    // payload[length] = NULL;
    // char *message = payload;
    char message[64];
    memcpy(message,payload, length);
    message[length]=NULL;


    if (strcmp("1", message) == 0)
    {
        digitalWrite(13, HIGH);
    }
    else
    {
        digitalWrite(13, LOW);
    }
    Serial.print(topic);
    Serial.print(" : ");
    Serial.println(message);
}
void mqtt_init()
{
    client.setServer(mqtt_server, 1883);
    // subscriber인경우 메시지 수신시 호출할 콜백 함수 등록
    client.setCallback(callback);
}

// MQTT 서버에 접속될 때까지 재접속 시도
void reconnect() //연결되면 true, 안되면 false
{
    while (!client.connected())
    {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) //여러개의 아두이노 사용시엔 ESP8266...을 다르게설정
        {
            Serial.println("connected");
            // subscriber로 등록
            client.subscribe("home/livingroom/led"); // 구독신청 <<<<<<------이게 핵심. subscribe로 됨
        }
        else
        {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            Serial.println(" try again in 5 seconds");
            delay(5000);
        }
    }
}

void publish()
{
    int state = !digitalRead(13);
    char message[10];
    sprintf(message, "%d", state);
    // 토픽 발행
    client.publish("home/livingroom/led", message);
}
// 2초 간격으로 publish

void setup()
{   Serial.begin(9600);
    wifi.init(ssid, password);
    mqtt_init();

    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    timer.setInterval(2000,publish);
}
void loop()
{
    if (!client.connected()) //mqtt가 연결 되어있지 않으면,
    {
        reconnect(); //재접속
    }
    client.loop();
    timer.run();
}