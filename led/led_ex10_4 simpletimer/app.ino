#include <SimpleTimer.h>

SimpleTimer timer; //정적할당

void printTest(){
    Serial.println("simple called by 1 sec");
}
void printTest2(){
    Serial.println("simple called by 0.5 sec");
}

 void setup() {
     Serial.begin(9600);
     
     timer.setInterval(1000,printTest);
     timer.setInterval(500,printTest2);
 }

 void loop(){
    timer.run();

 }
