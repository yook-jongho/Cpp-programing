#include <iostream>
using namespace std;
class Kvector
{
protected:
    int *m;
    int len;

public:
    static int total_len;
    Kvector(int sz = 0, int value = 0);
    Kvector(const Kvector &v);
    ~Kvector()
    {
        cout << this << " : ~Kvector() \n";
        delete[] m;
        total_len -= len;
    };
    Kvector &operator=(const Kvector &c);
    friend bool operator==(const Kvector &c, const Kvector &d);
    friend bool operator!=(const Kvector &c, const Kvector &d);
    int &operator[](int idx);
    const int &operator[](int idx) const { return m[idx]; }
    friend ostream &operator<<(ostream &os, const Kvector &c);
    void print() const
    {
        for (int i = 0; i < len; i++)
        {
            cout << m[i] << " ";
        }
        cout << endl;
    };
    void clear()
    {
        delete[] m;
        m = NULL;
        len = 0;
    };
    int size() { return len; };
};

Kvector::Kvector(int sz, int value)
{
    cout << this << " : Kvector(" << sz << ',' << value << ")\n";
    len = sz;
    total_len += len;
    if (sz == 0)
    {
        m = nullptr;
        return;
    }
    m = new int[sz];
    for (int i = 0; i < sz; i++)
    {
        m[i] = value;
    }
}

Kvector::Kvector(const Kvector &v)
{
    cout << this << " : Kvector(*" << &v << ")\n";
    len = v.len;
    total_len += len;
    m = new int[len];
    for (int i = 0; i < len; i++)
    {
        m[i] = v.m[i];
    }
}
int Kvector::total_len = 0;

Kvector &Kvector::operator=(const Kvector &c)
{
    if (this == &c)
    {
        return *this;
    }
    delete[] m;
    len = c.len;
    m = new int[len + 1];
    for (int i = 0; i < len; i++)
    {
        m[i] = c.m[i];
    }
    return *this;
}
bool operator==(const Kvector &c, const Kvector &d)
{
    return ((*c.m == *d.m) && (c.len == d.len) ? 1 : 0);
}
bool operator!=(const Kvector &c, const Kvector &d)
{
    return (!(c == d) ? 1 : 0);
}
int &Kvector::operator[](int idx)
{
    return m[idx];
}
ostream &operator<<(ostream &os, const Kvector &c)
{
    for (int i = 0; i < c.len; i++)
    {
        os << c.m[i] << " ";
    }
    return os;
}

#define N 3
class Avector : public Kvector
{
    char table[N];

public:
    Avector(int sz = 0, int v = 0, const char *t = "abc") : Kvector(sz, v)
    {
        cout << this << " : Avector(" << sz << "," << v << "," << t << ")\n";
        for (int i = 0; i < N; i++)
        {
            table[i] = t[i];
        }
    }
    void setTable(const char *t);
    friend ostream &operator<<(ostream &os, const Avector &v);
};
void Avector::setTable(const char *t)
{
    for (int i = 0; i < N; i++)
    {
        table[i] = t[i];
    }
}
ostream &operator<<(ostream &os, const Avector &v)
{
    for (int i = 0; i < 3; i++)
    {
        int a = v.m[i] % 3;
        os << v.table[a] << " ";
    }
    return os;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "usage : ./avector pqr\n";
        return 1;
    }

    Avector v1(3);
    v1.print();
    Avector v2(2, 1, "xyz");
    v2.print();
    Avector v3(v2);
    v3.print();
    cout << "v1 == v2 " << (v1 == v2) << endl;
    cout << "v3 == v2 " << (v3 == v2) << endl;
    v3 = v2 = v1;
    cout << "v1 : " << v1 << endl;
    v1.print();
    cout << "v2 : " << v2 << endl;
    v2.print();
    cout << "v3 : " << v3 << endl;
    v3.print();
    cout << "v3 != v2 " << (v3 != v2) << endl;
    v1[2] = 2;
    v2[0] = v1[2];
    v1.setTable(argv[1]);
    cout << "v1: " << v1 << "v2: " << v2
         << "v3: " << v3 << endl;
    v1.print();
    v2.print();
    v3.print();
    return 0;
}