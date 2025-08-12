#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define LH 1 //左高
#define EH 0 //等高
#define RH -1 //右高
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
	int bf;
	bstnode* lchild, * rchild;
}bstnode, * bstree;
void R_Rotate(bstree& p)//LL型，作右旋处理
{
	bstree lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
}
void L_Rotate(bstree& p)//RR型，作左旋处理
{
	bstree rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}
void leftbalance(bstree& T)//左平衡旋转处理
{
	bstree lc = T->lchild;
	switch (lc->bf)
	{
	case LH://新结点插入在T的左孩子的左子树上，要做单右旋处理
		T->bf = lc->bf = EH;
		R_Rotate(T); break;
	case RH://新结点插入在T的左孩子的右子树上，要做双旋处理
		bstree rd = lc->rchild;
		switch (rd->bf)
		{
		case LH:T->bf = RH; lc->bf = EH; break;
		case EH:T->bf = lc->bf = EH; break;
		case RH:T->bf = EH; lc->bf = LH; break;
		}
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}
}
void rightbalance(bstree& T)//左平衡旋转处理
{
}
int insertAVL(bstree& T, elemtype e, bool& taller)
//若在平衡的二叉排序树T中不存在和e有相同关键字的结点，则插入数据元素为e的新结点，返回1，否则返回0；
//若因插入而使二叉排序树失去平衡，则作平衡旋转处理，布尔变量taller反映T长高与否
{
	if (!T)//空树插入新节点，树长高
	{
		T = new bstnode;
		T->date = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;taller = TRUE;
	}
	else
	{
		if (e.key == T->date.key)//存在与e有相同关键字的结点则不进行插入
		{
			taller = FALSE; return 0;
		}
		if (e.key < T->date.key)//在左子树中继续进行搜索
		{
			if (!insertAVL(T->lchild, e, taller))return 0;//未插入
			if (taller)
			{
				switch (T->bf)
				{
				case LH://原本左子树比右子树高，需要做左平衡处理
					leftbalance(T); taller = FALSE; break;
				case EH://原本左子树和右子树等高，现因左子树增高而使树增高
					T->bf = LH; taller = TRUE; break;
				case RH://原本右子树比左子树高，现在左右子树等高
					T->bf = EH; taller = FALSE; break;
				}
			}
		}
		else//在右子树中继续进行搜索
		{
			if (!insertAVL(T->rchild, e, taller))return 0;//未插入
			if (taller)
			{
				switch (T->bf)
				{
				case LH://原本左子树比右子树高，现在左右子树等高
					T->bf = EH; taller = FALSE; break;
				case EH://原本左子树和右子树等高，现因右子树增高而使树增高
					T->bf = RH; taller = TRUE; break;
				case RH://原本右子树比左子树高，需要做右平衡处理
					rightbalance(T); taller = FALSE; break;
				}
			}
		}
	}
}
int main()
{
	return 0;
}