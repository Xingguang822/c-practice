#include<iostream>
using namespace std;
#define MAXTSIZE 100
#define MAXSIZE 100
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
	char c;
}TElemtype;
typedef TElemtype sqbitree[MAXTSIZE];
typedef sqbitree bt;
typedef struct btnode
{
	TElemtype date;
	btnode* lchild, * rchild;
}btnode, * bitree;
int createbitree(bitree& T)//二叉树算法的建立
{
	char ch;
	scanf_s(&ch);
	if (ch == '#')T = NULL;
	else
	{
		if (!(T = new btnode))exit(OVERFLOW);
		T->date.c = ch;
		createbitree(T->lchild);
		createbitree(T->rchild);
	}
	return OK;
}
int copy(bitree T, bitree& NEWT)//二叉树的复制
{
	if (T == NULL)
	{
		NEWT = NULL;
		return 0;
	}
	else
	{
		NEWT = new btnode;
		NEWT->date = T->date;
		copy(T->lchild, NEWT->lchild);
		copy(T->rchild, NEWT->rchild);
	}
}
int depth(bitree T)//二叉树的深度
{
	if (T == NULL)return 0;
	else
	{
		int m = depth(T->lchild);
		int n = depth(T->rchild);
		if (m > n)return (m + 1);
		else return(n + 1);
	}
}
int nodecount(bitree T)//二叉树的结点数
{
	if (T == NULL)return 0;
	else return  nodecount(T->lchild) + nodecount(T->rchild) + 1;
}
int leafcount(bitree T)//二叉树的叶子节点数
{
	if (T == NULL)return 0;
	if (T->lchild == NULL && T->rchild == NULL)return 1;
	else return leafcount(T->lchild) + leafcount(T->rchild);
}
int main()
{
	system("pause");
	return 0;
}