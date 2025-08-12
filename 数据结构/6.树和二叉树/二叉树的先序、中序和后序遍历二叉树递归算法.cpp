#include<iostream>
using namespace std;
#define MAXTSIZE 100
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
int preordertraverse(bitree T)//��������������ĵݹ��㷨��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O��n��
{
	if (!T)return OK;
	else
	{
		printf("%c", T->date);
		preordertraverse(T->lchild);
		preordertraverse(T->rchild);
	}
}
int inordertraverse(bitree T)//��������������ĵݹ��㷨��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O��n��
{
	if (!T)return OK;
	else
	{
		preordertraverse(T->lchild);
		printf("%c", T->date);
		preordertraverse(T->rchild);
	}
}
int postordertraverse(bitree T)//��������������ĵݹ��㷨��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O��n��
{
	if (!T)return OK;
	else
	{
		preordertraverse(T->lchild);
		preordertraverse(T->rchild);
		printf("%c", T->date);
	}
}
int main()
{
	system("pause");
	return 0;
}