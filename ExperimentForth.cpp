#include <iostream>
#include <cstdlib>

using namespace std;
# define MAXSIZE 100

//ѭ�����еĶ���
typedef struct SqQueue
{
    int* base;
    int front;
    int rear;
}SqQueue;
//���еĳ�ʼ��
void InitQueue(SqQueue& Q) {
    Q.base = new int[MAXSIZE];
    Q.front = Q.rear = 0;
}

//���ٶ���
void  DestroyQueue(SqQueue& Q) {
    //���ٶ���Q
    if (Q.base)
        delete[]Q.base;
    Q.base = NULL;
    Q.front = Q.rear=0;
    
}

//�ж��������Ƿ�Ϊ��
bool QueueEmpty(SqQueue& Q) {
    if (Q.front == Q.rear)
        return 1;
    else return 0;
}

//����еĶ�ͷԪ��
int GetHead(SqQueue Q) {
    if (Q.front != Q.rear)
        return Q.base[Q.front];
    else cout << "����Ϊ��" << endl;
}

//��Ӳ���
void EnQueue(SqQueue& Q, int e) {
    //����Ԫ��eΪQ���µĶ���βԪ��
   //����������ˣ�����ʾ����
    if ((Q.rear + 1) % MAXSIZE == Q.front)
        cout << "�����Ѿ����ˣ��޷�����Ԫ��" << endl;
    //�������δ������ô�������ݣ�Ȼ�󳤶ȼ�һ
    Q.base[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAXSIZE;
}

//���Ӳ���
int DeQueue(SqQueue& Q, int& e) {
    if (Q.front == Q.rear)
    {
        cout << "����Ϊ��" << endl;
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
    cout << " 1----------�ж϶����Ƿ�Ϊ��" << endl;
    cout << " 2----------����еĶ�ͷԪ��" << endl;
    cout << " 3----------��Ӳ���" << endl;
    cout << " 4----------���Ӳ���" << endl;
    cout << " 5----------���ٶ���" << endl;
    cout << " 6----------��ʼ������" << endl;
    cout << " 7----------���г���" << endl;
    cout << "    �˳�������0" << endl;
}

int main()
{
    char operate_code;
    show_help();

    SqQueue Q;
   

    while (1)
    {
        cout << "������Զ��еĲ�����";
        cin >> operate_code;
        if (operate_code == '1')
        {
            if (QueueEmpty(Q) == 1)
                cout << "����Ϊ��" << endl;
            else cout << "���зǿ�" << endl;
        }
        else if (operate_code == '2')
        {
            
            if (GetHead(Q)) {
                cout << "�ö��е�ͷԪ��Ϊ��";
                cout << GetHead(Q)<< endl;
            }
            else {
                cout << "�������Ϸ�" << endl;
            }
        }
        else if (operate_code == '3')
        {
            int e;
            cout << "��������Ҫ��ӵ�Ԫ�أ�";
            cin >> e;
            EnQueue(Q, e);
            cout << "��ӳɹ�" << endl;
        }
        else if (operate_code == '4')
        {
            int e;
            if (DeQueue(Q, e)) {
                cout << "���ӳɹ�����Ԫ��Ϊ��" << e << endl;
            }
            else {
                cout << "�������Ϸ�" << endl;
            }
        }
        else if (operate_code == '5')
        {
            DestroyQueue(Q);
            cout << "�ö����ѱ�����" << endl;
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
            cout << "\n��������󣡣���" << endl;
            show_help();
        }
    }

    return 0;
}

