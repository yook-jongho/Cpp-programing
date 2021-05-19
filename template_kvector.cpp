#include <iostream>
#include <string>
#ifndef __KVECTOR__
#define __KVECTOR__
using namespace std;

//class Team
class Team
{
    string name;
    int wins;

public:
    Team(const string &n = "teamX", int w = 0) : name(n), wins(w) {}
    Team &operator+=(const Team &rhs)
    {
        wins += rhs.wins;
        return *this;
    }
    ~Team();
    friend Team operator+(Team a, const Team &b);
    friend bool operator==(const Team &a, const Team &b);
    friend bool operator!=(const Team &a, const Team &b);
    friend ostream &operator<<(ostream &os, const Team &a);
};
Team::~Team() {}
Team operator+(Team a, const Team &b)
{
    a += b;
    return a;
}

bool operator==(const Team &a, const Team &b)
{
    return (a.name == b.name);
}

bool operator!=(const Team &a, const Team &b)
{
    return !(a == b);
}

ostream &operator<<(ostream &os, const Team &a)
{
    os << a.name << "(" << a.wins << ")";
    return os;
}

/*****************
//class Template
*****************/
template <class T>
class Kvector
{
protected:
    T *m;
    int len;

public:
    Kvector<T>(int sz = 0, T value = 0)
    {
        cout << this << " : Kvector(" << sz << ',' << value << ")\n";
        len = sz;
        if (sz == 0)
        {
            m = nullptr;
            return;
        }
        m = new T[sz];
        for (int i = 0; i < sz; i++)
        {
            m[i] = value;
        }
    }
    Kvector<T>(const Kvector<T> &v)
    {
        cout << this << " : Kvector(*" << &v << ")\n";
        len = v.len;
        m = new int[len];
        for (int i = 0; i < len; i++)
        {
            m[i] = v.m[i];
        }
    }
    virtual ~Kvector<T>()
    {
        cout << this << " : ~Kvector() \n";
        delete[] m;
    };
    virtual void print() const { cout << "Kvector\n"; }
    void clear()
    {
        delete[] m;
        m = nullptr;
        len = 0;
    }
    int size() { return len; }
    T sum() const
    {
        if (!len)
            return T();
        T s = m[0];
        for (int i = 1; i < len; i++)
            s += m[i];
        return s;
    }
    Kvector<T> &operator=(const Kvector<T> &v)
    {
        if (this == &v)
        {
            return *this;
        }
        delete[] m;
        len = v.len;
        m = new int[len + 1];
        for (int i = 0; i < len; i++)
        {
            m[i] = v.m[i];
        }
        return *this;
    }
    friend bool operator==(const Kvector<T> &v, const Kvector<T> &w)
    {
        return ((*v.m == *w.m) && (v.len == w.len) ? 1 : 0);
    }
    friend bool operator!=(const Kvector<T> &v, const Kvector<T> &w)
    {
        return (!(v == w) ? 1 : 0);
    }
    T &operator[](int idx) { return m[idx]; }
    const T &operator[](int idx) const { return m[idx]; }
    friend ostream &operator<<(ostream &os, const Kvector<T> &v)
    {
        for (int i = 0; i < v.len; i++)
        {
            os << v.m[i] << " ";
        }
        return os;
    }
};

template <class T>
bool operator==(const Kvector<T> &v, const Kvector<T> &w);
template <class T>
bool operator!=(const Kvector<T> &v, const Kvector<T> &w);
template <class T>
ostream &operator<<(ostream &os, const Kvector<T> &v);
#endif

int main(int argc, char *argv[])
{
    Kvector<int> v1(3, 0);
    cout << "v1 : " << v1 << endl;
    cout << "v1.sum() = " << v1.sum() << endl;

    Kvector<int *> v2(5, nullptr);
    int a[5] = {0, 1, 2, 3, 4};
    for (int i = 0; i < 5; i++)
    {
        v2[i] = &a[i];
    }
    cout << "v2 : " << v2 << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(v2[i]) << " ";
    }
    cout << endl;
    Kvector<Team> league1(2, Team()), league2(2, Team());
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    league1[0] = Team("Twins", 10);
    league1[1] = Team("Bears", 5);
    league2[0] = Team("Twins", 80);
    league2[1] = Team("Bears", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1 == league2 : " << (league1 == league2) << endl;
    league2[0] = Team("Bulls", 80);
    league2[1] = Team("Warriors", 81);
    cout << "league1 : " << league1 << endl;
    cout << "league2 : " << league2 << endl;
    cout << "league1.sum() : " << league1.sum() << endl;
    cout << "league2.sum() : " << league2.sum() << endl;
    return 0;
}
