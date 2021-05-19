//생성자 호출 순서는 부모- 자식 순,
//소멸자 호출 순서는 자식-부모 순.
#include <iostream>
using namespace std;

class shape
{
    int x, y;

public:
    shape(int x = 0, int y = 0) : x(x), y(y)
    {
        cout << this << " : Shape()" << endl;
    }
    ~shape()
    {
        cout << this << " : ~shape()\n";
    }
    void print()
    {
        cout << x << "," << y << endl;
    }
};

class rectangle : public shape
{
    int width, height;

public:
    rectangle(int x = 0, int y = 0, int w = 0, int h = 0) // : Shape(x,y) => 슈퍼클래스 생성자를 명시적 호출
    {
        width = w;
        height = h;
        cout << this << " : rectangle()" << endl;
    }
    ~rectangle()
    {
        cout << this << " : ~rectangle()" << endl;
    }

    void print()
    {
        shape::print();
    }
};

class point
{
    int r1, r2;

public:
    point(int r1 = 0, int r2 = 0) : r1(r1)
    {
        this->r2 = r2;
        cout << this << " : point()\n";
    }
    ~point()
    {
        cout << this << " : ~point()\n";
    }
};

class circle
{
    point center;
    int radius;

public:
    circle(int x, int y, int r) : center(x, y), radius(r) // center(x,y) => 맴버 객체의 생성자를 명시적 호출.
    {
        cout << this << " : circle()\n";
    }
    ~circle()
    {
        cout << this << " : ~circle()\n";
    }
};
int main()
{
    rectangle r;
    circle c(4, 5, 6);
    return 0;
}