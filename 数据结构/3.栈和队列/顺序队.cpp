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
int initqueue(sqqueue& Q)//初始化顺序队
{
	Q.base = new QElemtype[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queuelength(sqqueue Q)//求顺序队的长度
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}
int enqueue(sqqueue& Q, QElemtype x)//入顺序队
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, QElemtype& x)//出顺序队
{
	if (Q.front == Q.rear)return ERROR;
	x = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
QElemtype gettop(sqqueue Q)//得到顺序队的队头元素
{
	if (Q.front != Q.rear)
		return Q.base[Q.front];
}
int main()
{
	system("pause");
	return 0;
}