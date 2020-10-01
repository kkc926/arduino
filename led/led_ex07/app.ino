#include <TraficLight.h>

TrafficLight lights(1,4,7);

void setup() //생성자에 설정이 되어있으므로
{


}
// 5초간 직진신호
// 2초간 직진, 좌회전 동시신호
// 2초간 직진 및 좌회전 블링크
// 2초간 정지신호

void loop()
{
    lights.run();
}