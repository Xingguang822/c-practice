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
	btnode* lchild, *rchild;
}btnode,*bitree;
int preordertraverse(bitree T)//先序遍历二叉树的递归算法，时间复杂度O(n)，空间复杂度O（n）
{
	if (!T)return OK;
	else
	{
		printf("%c", T->date);
		preordertraverse(T->lchild);
		preordertraverse(T->rchild);
	}
}
int inordertraverse(bitree T)//中序遍历二叉树的递归算法，时间复杂度O(n)，空间复杂度O（n）
{
	if (!T)return OK;
	else
	{
		preordertraverse(T->lchild);
		printf("%c", T->date);
		preordertraverse(T->rchild);
	}
}
int postordertraverse(bitree T)//后序遍历二叉树的递归算法，时间复杂度O(n)，空间复杂度O（n）
{
	if (!T)return OK;
	else
	{
		preordertraverse(T->lchild);
		preordertraverse(T->rchild);
		printf("%c", T->date);
	}
}
//栈的顺序表示
typedef struct
{
	TElemtype* top;
	TElemtype* base;
	int stacksize;
}Sqstack;
int initstack(Sqstack& S)//构造一个空栈
{
	S.base = new TElemtype[MAXSIZE];
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
int push(Sqstack& S, bitree T)//入栈
{
	if (S.top - S.base == S.stacksize)return ERROR;
	*S.top++ = T->date ;
	return OK;
}int pop(Sqstack& S, bitree& T)//出栈
{
	if (S.top == S.base)return ERROR;
	T->date= *--S.top;
	return OK;
}
int inordertraverse(bitree T)//中序遍历二叉树的非递归算法
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
typedef struct sqqueue
{
	TElemtype* base;
	int front;
	int rear;
};
int initqueue(sqqueue& Q)//初始化顺序队
{
	Q.base = new TElemtype[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queueempty(sqqueue Q)//判断顺序队是否为空
{
	if (Q.front == Q.rear)
		return TRUE;
	return ERROR;
}
int enqueue(sqqueue& Q, bitree T)//入顺序队
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = T->date ;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, bitree &T)//出顺序队
{
	if (Q.front == Q.rear)return ERROR;
	T->date = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
void levelorder(bitree& T)//二叉树层次遍历算法
{
	btnode* p; sqqueue qu;
	initqueue(qu);
	enqueue(qu, T);
	while (!queueempty(qu))
	{
		dequeue(qu, p);
		printf("%c", p->date);
		if (p->lchild != NULL)enqueue(qu, p->lchild );
		if (p->rchild != NULL)enqueue(qu, p->rchild);
	}
}
int createbitree(bitree& T)//二叉树算法的建立
{
	char ch;
	scanf_s(&ch);
	if (ch =='#')T = NULL;
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
		NEWT->date=T->date;
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