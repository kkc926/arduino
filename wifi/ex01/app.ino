#include <SoftwareSerial.h>
#define BT_RXD 2
#define BT_TXD 3
SoftwareSerial softSerial(BT_RXD, BT_TXD);
void setup()
{
    Serial.begin(9600);
    // 펌웨어로 설정된 디폴트 속도는 115200 bps
    softSerial.begin(115200); // 펌웨어 설정에 따라 조정
    softSerial.setTimeout(5000);
    delay(1000);
}
void loop()
{
    if (Serial.available())
    { //pc->esp
        softSerial.write(Serial.read());
    }
    if (softSerial.available())
    { //esp->pc
        Serial.write(softSerial.read());
    }
}

//9600번 으로 AT으로 확인 가능
//AT+UART_DEF=9600,8,1,0,0 으로 9600으로 다운
//softSerial.begin(115200); ->begin(9600);

//AT+CWMODE=1
//AT+CWJAP="아이디","비밀번호"
//AT+CIFSR