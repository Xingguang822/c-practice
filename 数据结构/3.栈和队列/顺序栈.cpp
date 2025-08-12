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
//栈的顺序表示
typedef struct
{
	SElemtype* top;
	SElemtype* base;
	int stacksize;
}Sqstack;
int intstack(Sqstack& S)//构造一个空栈
{
	S.base = new SElemtype[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
}
int stackempty(Sqstack S)//判断栈是否为空
{
	if (S.top == S.base)
		return TRUE;
	else return FALSE;
}
int stacklength(Sqstack S)//求栈的长度
{
	return (S.top - S.base);
}
int cleanstack(Sqstack& S)//清空栈
{
	if (S.base)S.top = S.base;
	return OK;
}
int destorystack(Sqstack& S)//销毁栈
{
	if (S.base)
	{
		delete S.base;
		S.stacksize = 0;
		S.base = S.top = NULL;
	}
	return OK;
}
int pushstack(Sqstack& S, SElemtype e)//入栈
{
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = e;
	return OK;
}int popstack(Sqstack& S, SElemtype& e)//出栈
{
	if (S.top == S.base)return ERROR;
	e = *--S.top;
	return OK;
}
int main()
{
	return 0;
}