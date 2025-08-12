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
int initqueue(linkqueue& Q)//初始化链队列
{
	Q.front = Q.rear = new qnode;
	if (Q.front)exit(OVERFLOW);
	Q.front->next = NULL;
	return OK;
}
int destoryqueue(linkqueue& Q)//销毁链队列
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
int enqueue(linkqueue& Q, QElemtype e)//进链队列
{
	queueptr q=new qnode;
	q->date = e;
	q->next = NULL;
	Q.rear->next = q;
	Q.rear = q;
	return OK;
}
int dequeue(linkqueue& Q, QElemtype& e)//出链队列
{
	if (Q.front == Q.rear)return ERROR;
	queueptr q = Q.front->next;
	e = q->date;
	Q.front->next = q->next;
	if (Q.rear == q)Q.rear = Q.front;
	delete q;
	return OK;
}
QElemtype gettop(linkqueue Q)//得到链队列的队头元素
{
	if (Q.front != Q.rear)
		return Q.front->next->date;
}
int main()
{
	system("pause");
	return 0;
}