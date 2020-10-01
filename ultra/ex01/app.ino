int echoPin = 2;
int triggerPin = 3;


void setup()
{
    Serial.begin(9600);
    pinMode(echoPin, INPUT);
    pinMode(triggerPin, OUTPUT);
}
void loop()
{
    // trigger 핀으로 10us의 펄스를 발생
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    // echo 핀 입력으로부터 거리르 cm 단위로 계산
    int distance = pulseIn(echoPin, HIGH) / 58;
    Serial.println("Distance(cm) = " + String(distance));
    delay(1000);
}