#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
typedef int keytype;
typedef int infotype;
typedef struct
{
	keytype key;
	infotype otherinfo;
}elemtype;
typedef struct bstnode
{
	elemtype date;
	bstnode* lchild, * rchild;
}bstnode, * bstree;
bstree searchBST(bstree T, keytype key)//二叉排序树的查找算法,若查找成功返回指向该数据元素结点的指针，否则返回空指针
{
	if (!T||key==T->date.key)return T;
	else if (key < T->date.key)return searchBST(T->lchild, key);
	else return searchBST(T->rchild, key);
}
int searchBST(bstree T, keytype key,bstree f,bstree &p)
//在根指针T所指的二叉排序树中递归的查找其关键字等于key的数据元素，若查找成功，则指针p指向该数据元素结点，返回TRUE；
//否则p指向查找路径上访问的最后一个节点并返回FALSE，f指向T的双亲，初始值为NULL
{
	if (!T) { p = f; return FALSE; }//查找不成功
	else if (key == T->date.key) { p = T; return TRUE; }//查找成功
	else if (key < T->date.key) return searchBST(T->lchild, key, T, p);//在左子树中继续寻找
	else return searchBST(T->rchild, key, T, p);//在右子树中继续寻找
}
int insertBST(bstree& T, elemtype e)//二叉排序树的插入
{
	bstree p = new bstnode;
	if (!searchBST(T, e.key, NULL, p))
	{
		bstree s = new bstnode;
		s->date = e; s->lchild = s->rchild = NULL;
		if (!p)T = s;//如果T为空树，s为T的根节点
		else if (e.key < p->date.key)p->lchild = s;
		else p->rchild = s;
		return TRUE;
	}
	else return FALSE;
}
int Delete(bstree& p)//删除操作过程
{
	if (!p->rchild)//右子树为空则只需重接它的左子树
		p = p->lchild;
	else if (!p->lchild)
		p = p->rchild;
	else//左右子树均不为空
	{
		bstree q = p, s = p->lchild;
		while (s->rchild) { q = s; s = s->rchild; }//转左然后向右到尽头
		p->date = s->date;//s指向被删节点的前驱
		if (q != p)q->rchild = s->lchild;//重接q的右子树
		else q->lchild = s->lchild;//重接q的左子树
		delete q, s;
	}
	return TRUE;
}
int deleteBSF(bstree& T, keytype key)
{
	if (!T)return FALSE;
	else
	{
		if (key == T->date.key)return Delete(T);
		else if (key < T->date.key)return deleteBSF(T->lchild, key);
		else return deleteBSF(T->rchild, key);
	}
}
int main()
{
	return 0;
}
//void secondoptimal(bitree T, TElemtype R[], float sw[], int low, int high)//由有序表R[low...high]及其累计权值表sw递归构造次优查找树T
//{
//	int i = low;
//	float min = abs(sw[high] - sw[low]),dw= sw[high] + sw[low-1];
//	for (int j = low + 1; j <= high; ++j)
//	{
//		i = j;
//		min = abs(dw - sw[j] - sw[i - 1]);//abs函数用于求一个整数的绝对值
//	}
//	T->date = R[i];
//	if (i == low)T->lchild = NULL;
//	else secondoptimal(T->lchild, R, sw, low, i - 1);
//	if (i == high)T->rchild = NULL;
//	else secondoptimal(T->rchild, R, sw, i + 1, high);
//}