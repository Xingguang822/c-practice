#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define LH 1 //���
#define EH 0 //�ȸ�
#define RH -1 //�Ҹ�
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
void R_Rotate(bstree& p)//LL�ͣ�����������
{
	bstree lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
}
void L_Rotate(bstree& p)//RR�ͣ�����������
{
	bstree rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}
void leftbalance(bstree& T)//��ƽ����ת����
{
	bstree lc = T->lchild;
	switch (lc->bf)
	{
	case LH://�½�������T�����ӵ��������ϣ�Ҫ������������
		T->bf = lc->bf = EH;
		R_Rotate(T); break;
	case RH://�½�������T�����ӵ��������ϣ�Ҫ��˫������
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
void rightbalance(bstree& T)//��ƽ����ת����
{
}
int insertAVL(bstree& T, elemtype e, bool& taller)
//����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ�㣬���������Ԫ��Ϊe���½�㣬����1�����򷵻�0��
//��������ʹ����������ʧȥƽ�⣬����ƽ����ת������������taller��ӳT�������
{
	if (!T)//���������½ڵ㣬������
	{
		T = new bstnode;
		T->date = e;
		T->lchild = T->rchild = NULL;
		T->bf = EH;taller = TRUE;
	}
	else
	{
		if (e.key == T->date.key)//������e����ͬ�ؼ��ֵĽ���򲻽��в���
		{
			taller = FALSE; return 0;
		}
		if (e.key < T->date.key)//���������м�����������
		{
			if (!insertAVL(T->lchild, e, taller))return 0;//δ����
			if (taller)
			{
				switch (T->bf)
				{
				case LH://ԭ�����������������ߣ���Ҫ����ƽ�⴦��
					leftbalance(T); taller = FALSE; break;
				case EH://ԭ�����������������ȸߣ��������������߶�ʹ������
					T->bf = LH; taller = TRUE; break;
				case RH://ԭ�����������������ߣ��������������ȸ�
					T->bf = EH; taller = FALSE; break;
				}
			}
		}
		else//���������м�����������
		{
			if (!insertAVL(T->rchild, e, taller))return 0;//δ����
			if (taller)
			{
				switch (T->bf)
				{
				case LH://ԭ�����������������ߣ��������������ȸ�
					T->bf = EH; taller = FALSE; break;
				case EH://ԭ�����������������ȸߣ��������������߶�ʹ������
					T->bf = RH; taller = TRUE; break;
				case RH://ԭ�����������������ߣ���Ҫ����ƽ�⴦��
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