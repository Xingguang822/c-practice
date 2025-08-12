#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXQSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct
{
	int a;
}QElemtype;
typedef struct sqqueue
{
	QElemtype* base;
	int front;
	int rear;
};
int initqueue(sqqueue& Q)//��ʼ��˳���
{
	Q.base = new QElemtype[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queuelength(sqqueue Q)//��˳��ӵĳ���
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
int enqueue(sqqueue& Q, QElemtype x)//��˳���
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, QElemtype& x)//��˳���
{
	if (Q.front == Q.rear)return ERROR;
	x = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
QElemtype gettop(sqqueue Q)//�õ�˳��ӵĶ�ͷԪ��
{
	if(Q.front !=Q.rear )
	return Q.base[Q.front];
}
typedef struct qnode
{
	QElemtype date;
	qnode* next;
}*queueptr;
typedef struct
{
	queueptr front;
	queueptr rear;
}linkqueue;
int initqueue(linkqueue& Q)//��ʼ��������
{
	Q.front = Q.rear = new qnode;
	if (Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
int destoryqueue(linkqueue& Q)//����������
{
	queueptr p;
	while (Q.front)
	{
		p = Q.front;
		Q.front = Q.front->next;
		delete p;
	}
	return OK;
}
int enqueue(linkqueue& Q, QElemtype e)//��������
{
	queueptr p;
	p->date = e; p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return OK;
}
int dequeue(linkqueue& Q, QElemtype& e)//��������
{
	if (Q.front == Q.rear)return ERROR;
	queueptr q = Q.front->next ;
	e = q->date;
	Q.front->next = q->next;
	if (Q.rear == q)Q.rear = Q.front;
	delete q;
	return OK;
}
QElemtype gettop(linkqueue Q)//�õ������еĶ�ͷԪ��
{
	if (Q.front != Q.rear)
		return Q.front->next ->date ;
}
int main()
{
	system("pause");
	return 0;
}