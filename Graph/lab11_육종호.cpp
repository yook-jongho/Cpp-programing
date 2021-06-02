/*
이름 : 육종호
학번 : 20181650
program : lab11_육종호.cpp
*/
#include <iostream>
#include <vector>

using namespace std;

class prim
{
public:
    int size = 0;
    int total = 0;
    int lowcost[10];
    int closest[10];
    int Data[][100];
    void getData(int data[][100], int size)
    {
        this->size = size;
        cout << "      ";
        for (int i = 1; i < size; i++)
            cout << "v" << i << "   ";

        cout << endl;
        for (int i = 1; i < size; i++)
        {
            cout << "v" << i << "   ";
            for (int j = 1; j < size; j++)
            {
                Data[i][j] = data[i][j];
                if (Data[i][j] < 100)
                {
                    cout << " ";
                    if (Data[i][j] < 10)
                    {
                        cout << " ";
                    }
                }
                cout << Data[i][j] << "  ";
            }
            cout << endl;
        }
    }
    void MST()
    {
        vector<int> T;
        int k = 0;
        int min = 0;

        for (int i = 1; i < size; i++)
        {
            lowcost[i] = Data[1][i];
            closest[i] = 1;
        }
        cout << endl;
        while (T.size() < size - 2)
        {
            for (int i = 1; i < size; i++)
            {
                min = lowcost[i];
                k = i;
                for (int j = 1; j < size; j++)
                {
                    if (lowcost[j] < min)
                    {
                        min = lowcost[j];
                        k = j;
                    }
                }
            }
            cout << closest[k] << " - " << k << endl;
            total = total + lowcost[k];
            lowcost[k] = 101;
            Data[k][closest[k]] = 101;

            for (int i = 1; i < size; i++)
            {
                if (lowcost[i] < 101)
                {
                    lowcost[i] = Data[k][i];
                    closest[i] = k;
                }
            }
            T.push_back(k);
        }
    }
};

int main()
{
    int cost[][100] = {
        {},
        {0, 100, 6, 1, 5, 100, 100},
        {0, 6, 100, 4, 100, 3, 100},
        {0, 1, 4, 100, 5, 6, 5},
        {0, 5, 100, 5, 100, 100, 2},
        {0, 100, 3, 6, 100, 100, 6},
        {0, 100, 100, 5, 2, 6, 100},
    };
    cout << "*******  Weigthed Graph  *******" << endl;
    prim P;
    P.getData(cost, 7);
    cout << endl;
    cout << "*****  Minimal Spanning Tree  *****\n";
    P.MST();
    cout << "Total = " << P.total << endl;
    return 0;
}