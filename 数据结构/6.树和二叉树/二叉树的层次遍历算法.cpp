#include<iostream>
using namespace std;
#define MAXTSIZE 100
#define MAXQSIZE 100
#define CHUNKSIZE 80
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct
{
	int a;
}TElemtype;
typedef TElemtype sqbitree[MAXTSIZE];
typedef sqbitree bt;
typedef struct btnode
{
	TElemtype date;
	btnode* lchild, * rchild;
}btnode, * bitree;
typedef struct sqqueue
{
	TElemtype* base;
	int front;
	int rear;
};
int initqueue(sqqueue& Q)//��ʼ��˳���
{
	Q.base = new TElemtype[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queueempty(sqqueue Q)//�ж�˳����Ƿ�Ϊ��
{
	if (Q.front == Q.rear)
		return TRUE;
	return ERROR;
}
int enqueue(sqqueue& Q, bitree T)//��˳���
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = T->date;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, bitree& T)//��˳���
{
	if (Q.front == Q.rear)return ERROR;
	T->date = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
void levelorder(bitree& T)//��������α����㷨
{
	btnode* p; sqqueue qu;
	initqueue(qu);
	enqueue(qu, T);
	while (!queueempty(qu))
	{
		dequeue(qu, p);
		printf("%c", p->date);
		if (p->lchild != NULL)enqueue(qu, p->lchild);
		if (p->rchild != NULL)enqueue(qu, p->rchild);
	}
}
int main()
{
	system("pause");
	return 0;
}