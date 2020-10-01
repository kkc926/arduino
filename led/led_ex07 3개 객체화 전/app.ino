int pin_green = 1;
int pin_yellow = 4;
int pin_red = 7;
void setup()
{
    pinMode(pin_green,OUTPUT);
    pinMode(pin_yellow,OUTPUT);
    pinMode(pin_red,OUTPUT);

}

void go(int duration){
    digitalWrite(pin_red, LOW);
    digitalWrite(pin_yellow, LOW);
    digitalWrite(pin_green, HIGH);
    if(duration !=0){
        delay(duration);
    }

}


void stop(int duration=0){
   digitalWrite(pin_red, HIGH);
   digitalWrite(pin_yellow, LOW);
   digitalWrite(pin_green, LOW);
   if(duration !=0){
        delay(duration);
    }
}
void lefTurn(int duration=0){

   digitalWrite(pin_red, LOW);
   digitalWrite(pin_yellow, HIGH);
   digitalWrite(pin_green, HIGH);
   if(duration !=0){
        delay(duration);
    }
}

void blink(int pin, int duration){
    digitalWrite(pin, HIGH);
    delay(duration/2);
    digitalWrite(pin, LOW);
    delay(duration/2); //interval 한번에 켰껐을 해야하여 /2
}
void lefTurnWarning(int duration =0){

    digitalWrite(pin_red,LOW);
    digitalWrite(pin_yellow,HIGH);
    
    //5회점등
    int interval = duration /5;
    for (int i=0; i<5; i++){
        blink(pin_yellow,interval);
    }

}


// 5초간 직진신호
// 2초간 직진, 좌회전 동시신호
// 2초간 직진 및 좌회전 블링크
// 2초간 정지신호

void loop()
{
    go(5000);
    lefTurn(2000);
    lefTurnWarning(2000);
    stop(2000);
  
}