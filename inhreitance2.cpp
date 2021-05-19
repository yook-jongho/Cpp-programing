//접근 지정자 : public , private, protected
//private: 자식 클래스도 부모 클래스의 private 맴버는 사용x
//protected: 외부 함수, 클래스에서 접근 금지. 단 자식 클래스는 접근 허용.
//public : 모두 접근 가능.

#include <iostream>
using namespace std;

class home
{
private:
    int money = 0;

protected:
    int home_password = 0;

public:
    int playground = 0;
};

class sonHome : public home
{
    void func()
    {
        //h.money.. 접근 불가
        home_password = 1; // 접근 가능
        playground = 0;    // 접근 가능
    }
};

class anotherHome
{
    void fuc()
    {
        home h;
        //h.money.. 접근 불가
        //h.home_password..  접근 불가

        h.playground; //접근 가능
    }
};

int main()
{
    return 0;
}