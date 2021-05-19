#include <iostream>
using namespace std;

class A
{
    int v; // default 값으로 private 지정

protected:
    int t;

public:
    int p;
    void f()
    {
        v = 1;
        t = 2;
        p = 3;
    }
};

class B : public A
{
public:
    void g()
    {
        //v=10; 컴파일에러. 접근 제한
        t = 12;
        p = 13;
    }
};

class other
{
public:
    void fun()
    {
        A obj;
        //obj.v = 100; compile error. v is private
        //obj.t = 200; compile error. t is protected
        obj.p = 300;

        B obj2;
        //함수 f, g 는 public 이므로 ok
        obj2.f();
        obj2.g();
    }
};

int main()
{
    other o;
    o.fun();
}