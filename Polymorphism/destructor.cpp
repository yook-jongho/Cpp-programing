//소멸자
//소멸자 클래스를 상속받은 클레스는 반드시 상위 클래스의 메소드를 오버라이딩하여 구현하여야 한다.
#include <iostream>
using namespace std;

class Animal
{
public:
    Animal() { cout << "Animal 생성자" << endl; }
    virtual ~Animal() { cout << "Animal 소멸자" << endl; }
    virtual void speak() = 0;
};

class Dog : public Animal
{
public:
    Dog() { cout << "Dog 생성자" << endl; }
    ~Dog() { cout << "Dog 소멸자" << endl; }
    void speak() { cout << "멍멍" << endl; }
};

class Cat : public Animal
{
public:
    Cat() { cout << "Cat 생성자" << endl; }
    ~Cat() { cout << "Cat 소멸자" << endl; }
    void speak() { cout << "야옹" << endl; }
};

int main()
{
    Animal *a1 = new Dog(); //객체의 포인터가 super class type.
    a1->speak();            //virtual 함수일 경우 동적 바인딩으로 인해 Dog에 있는 speak 출력.
    delete a1;              //소멸자를 virtual로 선언하지 않으면, super class의 소멸자만 실행된다.
    Animal *a2 = new Cat();
    a2->speak();
    delete a2;
    return 0;
}