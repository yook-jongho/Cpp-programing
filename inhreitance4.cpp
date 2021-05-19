#include <iostream>
using namespace std;
class ParentClass
{
public:
    const static int x = 100; // 정적 상수 정의는 초기화가 가능하다.
};
class ChildClass1 : public ParentClass
{ // public: x
};
class ChildClass2 : private ParentClass //private으로 상속 = 접근 지정자가 private
{                                       // private : x
};

class GrandChild1 : private ChildClass1
{
};
class GrandChild2 : public ChildClass2
{
};
int main()
{
    ChildClass1 obj1;
    ChildClass2 obj2;
    cout << obj1.x << endl; // 가능: x는 public으로 유지된다.
    cout << obj2.x << endl; // 오류!!! 불가능: x는 public에서 private로 변경되었다.
    return 0;
}