//가상함수. 각 객체에 맞는 함수를 호출. --> overridding인 경우에만 사용가능?
#include <iostream>
using namespace std;

class shape
{
protected:
    int x, y;

public:
    void setOrigin(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    virtual void draw() //virtual. 가상함수로 지정하면, 종류에 따라 서로 다른 draw 함수가 호출된다.
    {
        cout << "shape " << x << ", " << y;
    }
};

class rectangle : public shape
{
    int w, h;

public:
    void setwidth(int w) { this->w = w; }
    void setheight(int h) { this->h = h; }
    void draw()
    {
        shape::draw();
        cout << " rectangle : " << w << " x " << h;
    }
};

class Circle : public shape
{
    int radius;

public:
    void setradius(int r)
    {
        radius = r;
    }
    void draw()
    {
        shape::draw();
        cout << " cricle : " << radius;
    }
};
int main()
{
    rectangle r;
    r.setOrigin(1, 1);
    r.setwidth(3);
    r.draw();
    cout << endl;

    Circle c;
    c.setOrigin(4, 4);
    c.setradius(5);
    c.draw();
    cout << endl;

    shape *ps;
    ps = &r; //shape -> rectangle
    ps->draw();
    cout << endl;

    ps = &c; //shape -> Circle
    ps->draw();
    cout << endl;

    shape &s1 = r; //shape -> rectangle
    s1.draw();
    cout << endl;

    shape &s2 = c; //shape -> Circle
    s2.draw();
    cout << endl;
    return 0;
}