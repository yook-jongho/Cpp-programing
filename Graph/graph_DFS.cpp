/****************************
이름 : 육종호
학번 : 20181650
Program : homework4.cpp
Description : graph의 기본 연산 Depth First Search 구현
Algorithm : 
1. buildList 함수 : 각 라인 정점과 그 연결을 구현
2. print_graph 함수 : 각 라인의 정점과 그 연결고리를 출력
3. dfs 함수 : 정점의 방문여부를 검사해 처음 방문인 경우 출력.
*****************************/
#include <iostream>
#include <fstream>
using namespace std;

/*
Node class  : AdJlist에서 다음 값을 link 하기 위해 사용
variables:
        char data : char형 데이터 저장
        Node *link : 다음 노드를 가르킬 주소값 저장
*/
class Node
{
private:
    char data;
    Node *link;

public:
    Node(char value) // 생성자에서 data와 link 초기화.
    {
        data = value;
        link = '\0';
    }
    friend class ADJlist;
};

/*
class ADJlist : LinkedList를 구현하기 위한 클래스
variables: 
     Node* graph[10] : 그래프의 정점 값을 저장하기위한 배열
     bool visit[10]  : 그래프의 값을 방문한적이 있는 확인하는 배열
*/
class ADJlist
{
private:
    Node *head;
    Node *graph[10] = {NULL};   //NULL 초기화
    bool visited[10] = {false}; //false 초기화. 아직 방문하지 않았기 때문에

public:
    ADJlist() { head = 0; };
    void print_graph();
    void bulidList(char buffer[], int line);
    void dfs(int v);
};

/*
buildList 함수 : 각 라인 정점과 그 연결을 구현
variables :
        char temp : head에 라인의 정점 값을 전달하기 위해 선언
        Node *q : 정점에서부터 이동하며 연결하기 위해 선언
        Node *t : 다음 노드 받아주기 위해 선언
*/
void ADJlist::bulidList(char buffer[], int line)
{
    int i = 0;
    char temp = buffer[i++]; // 각 라인별 데이터로 인접리스트 생성
    head = new Node(temp);   // 각 리스트의 첫번째 head node 생성
    graph[line] = head;      // head 노드 저장

    Node *q = head; // q for moving
    while (buffer[i] != '\0')
    {
        temp = buffer[i++];
        Node *t = new Node(temp); // create next node 생성
        q->link = t;
        q = q->link; // & make singly linked ADJlist
    }
}

/*
print_graph 함수 : 각 라인의 정점과 그 연결고리를 출력
*/
void ADJlist::print_graph()
{
    Node *p;
    for (int i = 0; graph[i] != 0; i++)
    {
        cout << " graph[" << graph[i]->data << "] -> ";
        for (p = graph[i]->link; p != NULL; p = p->link)
        {
            cout << p->data << " ";
        }
        cout << endl;
    }
}
/*
dfs 함수 : 깊이 우선 탐색. 정점의 방문여부를 검사해 처음 방문인 경우 출력.
*/
void ADJlist::dfs(int v)
{
    Node *w;
    visited[v] = true; //시작정점 v 방문
    cout << v << " -> ";
    for (w = graph[v]; w != NULL; w = w->link) //정점에서부터 이동하면서 연결된 값이 NULL아닐 때까지
    {
        int index = (int)(w->data) - '0'; //w->data가 char형 이므로, int형으로의 변환과정
        if (!visited[index])              //visited[] 배열의 인덱스 값으로 int형이 들어가야하기 때문에.
        {
            dfs(index);
        }
    }
}

int main()
{
    //Graph1
    ADJlist list1;
    int line = 0;

    ifstream infile;
    char buffer[80];
    infile.open("Graph1.txt", ios::in);

    while (infile.getline(buffer, 80))
    {
        list1.bulidList(buffer, line);
        line++;
    }
    cout << "<< graph data 1 >>\n";
    list1.print_graph();
    cout << endl;
    cout << "depth first search result\n";
    list1.dfs(0);
    cout << endl
         << endl;

    line = 0; //line 초기화

    //Graph2
    ADJlist list2;
    ifstream infile2;
    char buffer2[80];
    infile2.open("Graph2.txt", ios::in);
    while (infile2.getline(buffer2, 80))
    {
        list2.bulidList(buffer2, line);
        line++;
    }
    cout << "<< graph data 2 >>\n";
    list2.print_graph();
    cout << endl;
    cout << "depth first search result\n";
    list2.dfs(0);
    return 0;
}