//pure virtual function : 함수 헤더만 존재하고 함수 몸체는 없는 함수
//abstract class : 순수 가상 함수를 하나라도 가지고 있는 클래스. -> 객체를 생성할 수 없는 클래스
//virtual 반환형 함수이름(매개변수 리스트) = 0;
//추상 클래스를 상속받은 경우, 추상 클래스 내 모든 메소드를 오버라이딩하여 구현해야만 한다. 그렇지 않으면 compile error.
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal()
    {
        cout << "Animal Constructor" << endl;
    }
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual void speak() = 0;
};

class Lion : public Animal
{
public:
    void move()
    {
        cout << "사자의 move()" << endl;
    }
    void eat()
    {
        cout << "사자의 eat()" << endl;
    }
    void speak()
    {
        cout << "사자의 speak()" << endl;
    }
};

int main()
{
    //Animal a; compile error. because of abstract class. 추상클래스는 객체를 생성 할 수 없다.
    Lion *pt = new Lion();
    pt->eat();
    pt->move();
    pt->speak();
    return 0;
}