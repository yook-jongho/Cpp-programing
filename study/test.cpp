#include <iostream>
using namespace std;
class A
{
public:
    A()
    {
        cout << this << " : A class address" << endl;
    }
    void address()
    {
        cout << this << " : A.address() 의 address\n";
    }
};

class B : public A
{
public:
    B()
    {
        cout << this << " : B class address\n";
    }
    void address()
    {
        cout << this << " : B.address()의 address\n";
    }
    void Bmethod()
    {
        cout << "B만 쓸 수 있습니다.\n";
    }
};

int main()
{
    A *a = new B(); // upcasting. 선언 시, A, B의 생성자 출력
    a->address();
    cout << endl;
    B *b = (B *)a; // downcasting.
    b->address();  // 주소값이 같을 수 밖에 없다. a가 가르키는 곳으로 가기 때문에.
    b->Bmethod();

    B bc;
    A &acs = bc; // ==> A *acs = new B(); 과는 좀 다른데, *은 주소값에 해당되는 값을 참조, &은 주소값을 가지고 온다.
                 // &acs에는 bc의 주소값을 가르키게 된다. type은 물론 A 타입. bc는 B type이므로 upcasting이 일어난다.
    A *ac = &bc; // 안 될 이유가 없다. 포인터 변수는 주소값을 저장하고, &bc는 bc의 주소값이기 때문이다.
    A *ac = bc;  // compile error. 주소값을 담을 수가 없다.
    acs.address();
    return 0;
}