int pin_LED1 = 3;
int pin_LED2 = 5;
int pin_LED3 = 6;

void setup(){
    pinMode(pin_LED1, OUTPUT);
    pinMode(pin_LED2, OUTPUT);
    pinMode(pin_LED3, OUTPUT);

}

void loop(){
    for(int i =0; i<= 255; i++){
        analogWrite(pin_LED1,i); //i->255
        delay(20);
    }
    for(int i=255; i>=0; i--){
        analogWrite(pin_LED1, i); //255->0
        delay(20);
    }
    for(int i =0; i<= 255; i++){
        analogWrite(pin_LED2,i); //i->255
        delay(20);
    }
    for(int i=255; i>=0; i--){
        analogWrite(pin_LED2, i); //255->0
        delay(20);
    }
    for(int i =0; i<= 255; i++){
        analogWrite(pin_LED3,i); //i->255
        delay(20);
    }
    for(int i=255; i>=0; i--){
        analogWrite(pin_LED3, i); //255->0
        delay(20);
    }


}