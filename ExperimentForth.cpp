#include <iostream>
#include <cstdlib>

using namespace std;

void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << " 1----------判断队列是否为空" << endl;
    cout << " 2----------求队列的队头元素" << endl;
    cout << " 3----------入队操作" << endl;
    cout << " 4----------出队操作" << endl;
    cout << " 5----------销毁队列" << endl;
    cout << "    退出，输入0" << endl;
}

//#define  MAXSIZE    100;

//typedef int stackSize;
typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode* next;
}QNode, * QueuePtr;

//队列的链式存储结构
typedef struct {
    QueuePtr  front;  // 队头指针
    QueuePtr  rear;   // 队尾指针
}LinkQueue;           // 链队列

//队列的初始化
void InitQueue(LinkQueue& Q) {
    // 构造一个空队列 Q
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

//销毁队列
void  DestroyQueue(LinkQueue& Q) {
    //销毁队列Q
    while (Q.front) {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}

//判断链队列是否为空
bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

//求队列的队头元素
int GetHead(LinkQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return 0;
    e = Q.front->next->data;
    return 1;
}

//入队操作
void EnQueue(LinkQueue& Q, QElemType  e) {
    //插入元素e为Q的新的队列尾元素
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;  // 修改尾结点的指针
    Q.rear = p;        // 移动队尾指针
}

//出队操作
int DeQueue(LinkQueue& Q, QElemType& e) {
    // 若队列不空，则删除Q的队头元素，用e返回其值,并返回1；否则返回-1
    if (Q.front == Q.rear)   return 0; // 队列为空
    QueuePtr p = Q.front->next; e = p->data;      // 返回被删元素
    Q.front->next = p->next;            // 修改头结点指针
    if (Q.rear == p)   Q.rear = Q.front;
    delete p;                           // 释放被删结点
    return 1;
}

int main()
{
    char operate_code;
    show_help();

    LinkQueue Q;
    InitQueue(Q);

    while (1)
    {
        cout << "请输入对队列的操作：";
        cin >> operate_code;
        if (operate_code == '1')
        {
            if (QueueEmpty(Q)) {
                cout << "该队列为空" << endl;
            }
            else {
                cout << "该队列为非空" << endl;
            }
        }
        else if (operate_code == '2')
        {
            QElemType e;
            if (GetHead(Q, e)) {
                cout << "该队列的头元素为：";
                cout << e << endl;
            }
            else {
                cout << "操作不合法" << endl;
            }
        }
        else if (operate_code == '3')
        {
            QElemType e;
            cout << "请输入想要入队的元素：";
            cin >> e;
            EnQueue(Q, e);
            cout << "入队成功" << endl;
        }
        else if (operate_code == '4')
        {
            QElemType e;
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

