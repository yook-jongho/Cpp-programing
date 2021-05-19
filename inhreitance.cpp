#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Car
{
public:
    int speed;
    int gear;
    string color;
    void setGear(int newGear)
    {
        gear = newGear;
    }
    void speedUp(int increment)
    {
        speed += increment;
    }
    void speedDown(int decrement)
    {
        speed -= decrement;
    }
};

class SportsCar : public Car
{
    bool turbo;

public:
    void setTurbo(bool newValue)
    {
        turbo = newValue;
    }
};

int main()
{
    Car c1;
    SportsCar c2;

    c1.setGear(2);
    c1.speed = 100;
    c1.speedUp(20);
    c1.speedDown(30);

    //c1.setTurbo(true); 컴파일 에러. 부모클래스는 자식클래스의 변수,함수들을 사용할 수 없다.
    //자식클래스는 부모클래스의 맴버변수, 함수를 사용할 수 있다.
    //is-a 관계 : ~은 ~이다. ex) 자동차는 탈것이다. 상속가능.
    //has-a 관계: ~은 ~를 가지고 있다. ex) 도서관은 책을 가지고 있다. 상속불가능.

    c2.setGear(2);
    c2.speed = 100;
    c2.speedUp(20);
    c2.speedDown(30);
    c2.setTurbo(true);

    return 0;
}