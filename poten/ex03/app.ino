
const int ledPin=3;
const int potentionmeterPin = A0;

int potentionmeterValue;
int brightness;

void setup()
{
    Serial.begin(9600);
}

void loop(){
    potentionmeterValue = analogRead(potentionmeterPin);

    Serial.print("potentionmeter Value : ");
    Serial.println(potentionmeterValue);

    brightness = map(potentionmeterValue,0,1023,0,255);
    Serial.print("brightness value : ");
    Serial.println(brightness);

    analogWrite(ledPin, brightness);
}