#include <iostream>
#include <cstdlib>

using namespace std;

void show_help()
{
    cout << "******* Data Structure ******" << endl;
    cout << " 1----------�ж϶����Ƿ�Ϊ��" << endl;
    cout << " 2----------����еĶ�ͷԪ��" << endl;
    cout << " 3----------��Ӳ���" << endl;
    cout << " 4----------���Ӳ���" << endl;
    cout << " 5----------���ٶ���" << endl;
    cout << "    �˳�������0" << endl;
}

//#define  MAXSIZE    100;

//typedef int stackSize;
typedef int QElemType;

typedef struct QNode {
    QElemType data;
    struct QNode* next;
}QNode, * QueuePtr;

//���е���ʽ�洢�ṹ
typedef struct {
    QueuePtr  front;  // ��ͷָ��
    QueuePtr  rear;   // ��βָ��
}LinkQueue;           // ������

//���еĳ�ʼ��
void InitQueue(LinkQueue& Q) {
    // ����һ���ն��� Q
    Q.front = Q.rear = new QNode;
    Q.front->next = NULL;
}

//���ٶ���
void  DestroyQueue(LinkQueue& Q) {
    //���ٶ���Q
    while (Q.front) {
        Q.rear = Q.front->next;
        delete Q.front;
        Q.front = Q.rear;
    }
}

//�ж��������Ƿ�Ϊ��
bool QueueEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

//����еĶ�ͷԪ��
int GetHead(LinkQueue Q, QElemType& e) {
    if (Q.front == Q.rear) return 0;
    e = Q.front->next->data;
    return 1;
}

//��Ӳ���
void EnQueue(LinkQueue& Q, QElemType  e) {
    //����Ԫ��eΪQ���µĶ���βԪ��
    QueuePtr p = new QNode;
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;  // �޸�β����ָ��
    Q.rear = p;        // �ƶ���βָ��
}

//���Ӳ���
int DeQueue(LinkQueue& Q, QElemType& e) {
    // �����в��գ���ɾ��Q�Ķ�ͷԪ�أ���e������ֵ,������1�����򷵻�-1
    if (Q.front == Q.rear)   return 0; // ����Ϊ��
    QueuePtr p = Q.front->next; e = p->data;      // ���ر�ɾԪ��
    Q.front->next = p->next;            // �޸�ͷ���ָ��
    if (Q.rear == p)   Q.rear = Q.front;
    delete p;                           // �ͷű�ɾ���
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
        cout << "������Զ��еĲ�����";
        cin >> operate_code;
        if (operate_code == '1')
        {
            if (QueueEmpty(Q)) {
                cout << "�ö���Ϊ��" << endl;
            }
            else {
                cout << "�ö���Ϊ�ǿ�" << endl;
            }
        }
        else if (operate_code == '2')
        {
            QElemType e;
            if (GetHead(Q, e)) {
                cout << "�ö��е�ͷԪ��Ϊ��";
                cout << e << endl;
            }
            else {
                cout << "�������Ϸ�" << endl;
            }
        }
        else if (operate_code == '3')
        {
            QElemType e;
            cout << "��������Ҫ��ӵ�Ԫ�أ�";
            cin >> e;
            EnQueue(Q, e);
            cout << "��ӳɹ�" << endl;
        }
        else if (operate_code == '4')
        {
            QElemType e;
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

