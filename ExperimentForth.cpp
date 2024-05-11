#include <iostream>
#include <cstdlib>

using namespace std;
# define MAXSIZE 100

//循环队列的定义
typedef struct SqQueue
{
    int* base;
    int front;
    int rear;
}SqQueue;
//队列的初始化
void InitQueue(SqQueue& Q) {
    Q.base = new int[MAXSIZE];
    Q.front = Q.rear = 0;
}

//销毁队列
void  DestroyQueue(SqQueue& Q) {
    //销毁队列Q
    if (Q.base)
        delete[]Q.base;
    Q.base = NULL;
    Q.front = Q.rear=0;
    
}

//判断链队列是否为空
bool QueueEmpty(SqQueue& Q) {
    if (Q.front == Q.rear)
        return 1;
    else return 0;
}

//求队列的队头元素
int GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];
    else cout << "队列为空" << endl;
}

//入队操作
void EnQueue(SqQueue& Q, int e) {
    //插入元素e为Q的新的队列尾元素
   //如果队列满了，就显示报错
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        cout << "队列已经满了，无法插入元素" << endl;
    //如果队列未满，那么存入数据，然后长度加一
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

//出队操作
int DeQueue(SqQueue& Q, int& e) {
    if (Q.front == Q.rear)
    {
        cout << "队列为空" << endl;
        return 0;
    }
    else
    {
        e = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXSIZE;
        return e;
    }
}

int Count(SqQueue& Q)
{
    return (Q.rear - Q.front + MAXSIZE)%MAXSIZE;
}
void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << " 1----------判断队列是否为空" << endl;
    cout << " 2----------求队列的队头元素" << endl;
    cout << " 3----------入队操作" << endl;
    cout << " 4----------出队操作" << endl;
    cout << " 5----------销毁队列" << endl;
    cout << " 6----------初始化队列" << endl;
    cout << " 7----------队列长度" << endl;
    cout << "    退出，输入0" << endl;
}

int main()
{
    char operate_code;
    show_help();

    SqQueue Q;
   

    while (1)
    {
        cout << "请输入对队列的操作：";
        cin >> operate_code;
        if (operate_code == '1')
        {
            if (QueueEmpty(Q) == 1)
                cout << "队列为空" << endl;
            else cout << "队列非空" << endl;
        }
        else if (operate_code == '2')
        {
            
            if (GetHead(Q)) {
                cout << "该队列的头元素为：";
                cout << GetHead(Q)<< endl;
            }
            else {
                cout << "操作不合法" << endl;
            }
        }
        else if (operate_code == '3')
        {
            int e;
            cout << "请输入想要入队的元素：";
            cin >> e;
            EnQueue(Q, e);
            cout << "入队成功" << endl;
        }
        else if (operate_code == '4')
        {
            int e;
            if (DeQueue(Q, e)) {
                cout << "出队成功，该元素为：" << e << endl;
            }
            else {
                cout << "操作不合法" << endl;
            }
        }
        else if (operate_code == '5')
        {
            DestroyQueue(Q);
            cout << "该队列已被销毁" << endl;
        }
        else if (operate_code == '6')
        {
            InitQueue(Q);
        }
        else if (operate_code == '7')
        {
            cout << Count(Q)<<endl;
        }
        else if (operate_code == '0')
        {
            break;
        }
        else
        {
            cout << "\n操作码错误！！！" << endl;
            show_help();
        }
    }

    return 0;
}

