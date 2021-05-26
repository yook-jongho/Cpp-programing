// program : lab10_육종호.cpp
// 이름 : 육종호
// 학번 : 20181650

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

class Node
{
private:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = 0;
    }
    friend class linkedQueue;
};

class linkedQueue
{
private:
    Node *front;
    Node *rear;
    bool visited[10] = {false};
    int size = 0;
    int graph[10][10] = {{0}};

public:
    linkedQueue()
    {
        front = 0;
        rear = 0;
    }
    ~linkedQueue();
    void enqueue(int);
    int dequeue();
    bool isEmpty();
    void BFS(int);
    void print_graph();
    void buildQueue(int data[][10], int size)
    {
        this->size = size;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                graph[i][j] = data[i][j];
            }
        }
    }
};

linkedQueue::~linkedQueue()
{
    Node *p;
    while (front != 0)
    {
        p = front;
        front = front->next;
        delete p;
    }
}

void linkedQueue::enqueue(int data)
{
    Node *temp = new Node(data);
    if (front == 0)
    {
        front = temp;
        rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

int linkedQueue::dequeue()
{
    Node *p;
    int num;
    num = front->data;
    p = front;
    if (front == rear)
    {
        front = 0;
        rear = 0;
    }
    else
        front = front->next;
    delete p;
    return num;
}

bool linkedQueue::isEmpty()
{
    if (front == 0)
        return true;
    else
        return false;
}

void linkedQueue::BFS(int v = 0)
{
    int j;
    visited[v] = true;
    enqueue(v);

    while (!isEmpty())
    {
        v = dequeue();
        cout << v << " ";

        for (j = 0; j < size; j++)
        {
            if (graph[v][j] && !visited[j])
            {
                visited[j] = true;
                enqueue(j);
            }
        }
    }
}

void linkedQueue::print_graph()
{
    cout << "    ";
    for (int i = 0; i < size; i++)
    {
        cout << "v" << i << " ";
    }
    cout << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "v" << i << "  ";
        for (int j = 0; j < size; j++)
        {
            cout << graph[i][j] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int graph1[10][10] = {
        {0, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 0, 1, 1, 1, 1}};

    linkedQueue Q1;
    Q1.buildQueue(graph1, 8);
    cout << " ***    Graph data 1    ***" << endl
         << endl;
    Q1.print_graph();
    cout << endl;
    cout << "Breadth first search result: ";
    Q1.BFS(0);
    cout << endl
         << endl
         << endl;

    int graph2[10][10] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 1, 1, 1, 0}};

    linkedQueue Q2;
    Q2.buildQueue(graph2, 6);
    cout << " ***    Graph data 2    ***" << endl
         << endl;
    Q2.print_graph();
    cout << endl;
    cout << "Breadth first search result: ";
    Q2.BFS(0);
}