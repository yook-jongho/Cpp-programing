//객체 간의 형변환
//upcasting : sub class -> super class. 명시하지 않아도 사용 가능. 절대적
//downcasting : super class -> sub class. 명시적 형변환 연산자를 사용해야 함
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
    void draw()
    {
        cout << "shape " << x << ", " << y << endl;
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
        cout << " rectangle : " << w << " x " << h << endl;
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
    void draw() //Overriding
    {
        shape::draw();
        cout << " cricle : " << radius << endl;
    }
};

void move(shape &s, int dx, int dy) //함수 매개변수는 super class 타입으로 선언.
{
    s.setOrigin(dx, dy);
}

int main()
{
    shape s;
    s.setOrigin(1, 2);
    s.draw();

    //shape S = new shape(); // compile error. c++에선 동적할당 시, pointer 사용.
    shape S = shape(); // 이렇게 선언하면 가능!

    //객체 포인터의 상향 형변환
    shape *se = new rectangle(); //shape형 포인터 변수 se가 객체 rectangle을 가르킴. => 상향형변환..?
    se->setOrigin(10, 10);
    se->draw();

    //객체 포인터의 하향 형변환
    rectangle *sr = (rectangle *)se; //rectangle형 포인터 변수 sr이 객체 se(rectangle)를 가르킴 => 하향형변환..?
    sr->setwidth(100);
    sr->setheight(100);
    sr->setOrigin(100, 100);
    sr->shape::draw(); //shape의 draw 호출. 부모 class의 draw를 호출하겠다.
    sr->draw();        //rectangle의 draw 호출. shape의 draw 호출 후, custom 메세지를 출력한다.
    cout << endl;

    rectangle r;
    r.setOrigin(1, 1);
    r.setwidth(3);
    r.draw();
    cout << endl;

    shape *ps = &r; //shape형 포인터 변수 ps가 rectangle형 변수 r(rectangle)을 가르킨다. 상향형변환 == shape *ps = new rectangle();
    ps->setOrigin(10, 10);
    //ps.setwidth(100);  compile error
    ps->draw();
    cout << endl;

    rectangle *pr;
    pr = (rectangle *)ps; //shape형 포인터변수 ps가 rectangle 로 하향형변환.
    pr->setOrigin(8, 8);
    pr->setwidth(16);
    pr->draw();
    cout << endl;

    ((Circle *)ps)->setradius(11); //shape형 포인터변수 ps가 Circle  로 하향형변환
    ((Circle *)ps)->draw();
    cout << endl;
    pr->draw();
    cout << endl;

    shape &S = r; // == Shape  *S = new rectangle();
    S.setOrigin(5, 5);
    //s.setwidth(7); compile error
    S.draw();
    cout << endl;

    move(S, 10, 20);
    S.draw();

    //rectangle& rr= (rectangle)s; compile error
    return 0;
}