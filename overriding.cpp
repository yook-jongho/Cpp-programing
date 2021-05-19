//중복 정의 : 같은 이름의 맴버 함수를 여러 개 정의하는 것 overloading
//재정의 : 부모 클래스에 있던 상속받은 멤버 함수를 다시 정의하는 것 overriding
//overriding 조건 : 부모클래스의 맴버함수와 동일한 이름, 반환형, 매개변수의 개수와 데이터 타입이 모두 일치.
#include <iostream>
using namespace std;

class Car
{
public:
    int fuel;
    int getfuel()
    {
        return 100;
    }
    void print()
    {
        cout << "car\n";
    }
};

class mycar : public Car
{
public:
    int fuel;
    int getfuel()
    {
        return 300;
    }
    void print()
    {
        Car::print();
        cout << "mycar\n";
    }
};
int main()
{
    mycar c;
    cout << "car fuel: " << c.Car::getfuel() << endl;           // 부모클래스의 getfuel 메소드 호출
    cout << "my car fuel(overriding): " << c.getfuel() << endl; //자식클래스의 getfuel 메소드 호출
    return 0;
}