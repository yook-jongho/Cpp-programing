//pure virtual function : 함수 헤더만 존재하고 함수 몸체는 없는 함수
//abstract class : 순수 가상 함수를 하나라도 가지고 있는 클래스. -> 객체를 생성할 수 없는 클래스
//virtual 반환형 함수이름(매개변수 리스트) = 0;
#include <iostream>
using namespace std;

class Animal
{
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual void speak() = 0;
};

class Lion : public Animal
{
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
    //Animal a; compile error. because of abstract class.
    Lion *pt = new Lion();
    pt->eat();   //why compile error..?
    pt->move();  //why compile error..?
    pt->speak(); //why compile error..?
    return 0;
}