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
typedef struct bithrnode
{
	int date;
	int ltag, rtag;
	bithrnode* lchild, * rchild;
}bithrnode,*bithrtree;
int inordertraverse(bithrtree T)//中序遍历二叉树的非递归算法
{
	bithrtree p = T->lchild;
	while (p != T)
	{
		while (p->ltag == 0)p = p->lchild;
		if (!p->date)return ERROR;
		while (p->rtag == 1 && p->rchild != T)
		{
			p = p->rchild; printf("%c", p->date);
		}
		p = p->rchild;
	}
	return OK;
}
void inthreading(bithrtree p)
{
	if (p)
	{
		bithrtree pre;
		inthreading(p->lchild);
		if (!p->lchild)
		{
			p->ltag = 1; p->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = 1;
			pre->rchild = p;
		}
		pre = p;
		inthreading(p->rchild);
	}
}
int inorderthreading(bithrtree& Thrt, bithrtree T)//中序遍历二叉树T，并将其中序线索化，Thrt指向头节点
{
	if (!(Thrt = new bithrnode))exit(OVERFLOW);
	Thrt->ltag = 0; Thrt->rtag = 1;
	Thrt->rchild = Thrt;
	if (!T)Thrt->lchild = Thrt;
	else
	{
		Thrt->lchild = T;
		bithrtree pre = Thrt;
		inthreading(T);
		pre->rchild = Thrt;
		pre->rtag = 1;
		Thrt->rchild = pre;
	}
	return OK;
}
int main()
{
	system("pause");
	return 0;
}