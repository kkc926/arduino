int speakerPin = 5;
void setup() {
}
void loop() {
tone(speakerPin, 7000, 1000);
delay(2000); //소리나는 1초, 안나는 1초 합쳐진 시간
}