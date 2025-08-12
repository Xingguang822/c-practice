#include<iostream>
using namespace std;
#define MAXTSIZE 100
#define MAXSIZE 100
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
//ջ��˳���ʾ
typedef struct
{
	TElemtype* top;
	TElemtype* base;
	int stacksize;
}Sqstack;
int initstack(Sqstack& S)//����һ����ջ
{
	S.base = new TElemtype[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
int stackempty(Sqstack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.top == S.base)
		return TRUE;
	else return FALSE;
}
int push(Sqstack& S, bitree T)//��ջ
{
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = T->date;
	return OK;
}int pop(Sqstack& S, bitree& T)//��ջ
{
	if (S.top == S.base)return ERROR;
	T->date = *--S.top;
	return OK;
}
int inordertraverse(bitree T)//��������������ķǵݹ��㷨
{
	bitree p, q; p = T;
	Sqstack S;
	initstack(S);
	while (p || !stackempty(S))
	{
		if (p)
		{
			push(S, p); p = p->lchild;
		}
		else
		{
			pop(S, q);
			printf("%c", q->date);
			p = q->rchild;
		}
	}
	return OK;
}
int main()
{
	system("pause");
	return 0;
}