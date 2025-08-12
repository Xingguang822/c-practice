#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAXSIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct
{
	int a;
}SElemtype;
//ջ��˳���ʾ
typedef struct
{
	SElemtype* top; 
	SElemtype* base;
	int stacksize;
}Sqstack;
int intstack(Sqstack& S)//����һ����ջ
{
	S.base = new SElemtype[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
int stackempty(Sqstack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S.top == S.base)
		return TRUE ;
	else return FALSE;
}
int stacklength(Sqstack S)//��ջ�ĳ���
{
	return (S.top - S.base);
}
int cleanstack(Sqstack& S)//���ջ
{
	if(S.base )S.top = S.base;
	return OK;
}
int destorystack(Sqstack& S)//����ջ
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}
int pushstack(Sqstack &S, SElemtype e)//��ջ
{
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++= e;
	return OK;
}int pushstack(Sqstack& S, SElemtype &e)//��ջ
{
	if (S.top==S.base )return ERROR;
	e=*--S.top;
	return OK;
}
//ջ����ʽ��ʾ
typedef struct stacknode
{
	SElemtype date;
	stacknode* next;
}*linkstack;
int intstack(linkstack & S)//����һ����ջ
{
	S = NULL;
	return OK;
}
int stackempty(linkstack S)//�ж�ջ�Ƿ�Ϊ��
{
	if (S==NULL)return OK;
	else return FALSE;
}
int pushstack(linkstack& S, SElemtype e)//��ջ
{
	linkstack p = new stacknode;
	p->date = e; p->next = S;
	S = p;
	return OK;
}
int pushstack(linkstack& S, SElemtype& e)//��ջ
{
	if (!S)return ERROR;
	e = S->date;
	linkstack q = S;
	S = S->next;
	delete q;
	return OK;
}
SElemtype gettop(linkstack S)//�õ�ջ��Ԫ��
{
	if (S)
		return S->date;
}
int main()
{
	return 0;
}