const int redPin = 11;
const int greenPin = 10;
const int bluePin = 9;

void setup(){
    randomSeed(analogRead(A0)); //analogRead는 0~1023까지 리턴해줌 digitalRead는 0~1만
                                //임의의 값을 설정함
    analogWrite(redPin,255);
    delay(1000);
    analogWrite(redPin,0);
    analogWrite(greenPin,255);
    delay(1000);
    analogWrite(greenPin,0);
    analogWrite(bluePin,255);
    delay(1000);
}

void loop(){
    analogWrite(redPin,random(256));
    analogWrite(greenPin,random(256));
    analogWrite(bluePin,random(256));
    delay(100);
}