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
//栈的链式表示
typedef struct stacknode
{
	SElemtype date;
	stacknode* next;
}*linkstack;
int intstack(linkstack& S)//构造一个空栈
{
	S = NULL;
	return OK;
}
int stackempty(linkstack S)//判断栈是否为空
{
	if (S == NULL)return OK;
	else return FALSE;
}
int pushstack(linkstack& S, SElemtype e)//入栈
{
	linkstack p = new stacknode;
	p->date = e; p->next = S;
	S = p;
	return OK;
}
int pushstack(linkstack& S, SElemtype& e)//出栈
{
	if (!S)return ERROR;
	e = S->date;
	linkstack q = S;
	S = S->next;
	delete q;
	return OK;
}
SElemtype gettop(linkstack S)//得到栈顶元素
{
	if (S)
		return S->date;
}
int main()
{
	return 0;
}