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
bstree searchBST(bstree T, keytype key)//�����������Ĳ����㷨,�����ҳɹ�����ָ�������Ԫ�ؽ���ָ�룬���򷵻ؿ�ָ��
{
	if (!T||key==T->date.key)return T;
	else if (key < T->date.key)return searchBST(T->lchild, key);
	else return searchBST(T->rchild, key);
}
int searchBST(bstree T, keytype key,bstree f,bstree &p)
//�ڸ�ָ��T��ָ�Ķ����������еݹ�Ĳ�����ؼ��ֵ���key������Ԫ�أ������ҳɹ�����ָ��pָ�������Ԫ�ؽ�㣬����TRUE��
//����pָ�����·���Ϸ��ʵ����һ���ڵ㲢����FALSE��fָ��T��˫�ף���ʼֵΪNULL
{
	if (!T) { p = f; return FALSE; }//���Ҳ��ɹ�
	else if (key == T->date.key) { p = T; return TRUE; }//���ҳɹ�
	else if (key < T->date.key) return searchBST(T->lchild, key, T, p);//���������м���Ѱ��
	else return searchBST(T->rchild, key, T, p);//���������м���Ѱ��
}
int insertBST(bstree& T, elemtype e)//�����������Ĳ���
{
	bstree p = new bstnode;
	if (!searchBST(T, e.key, NULL, p))
	{
		bstree s = new bstnode;
		s->date = e; s->lchild = s->rchild = NULL;
		if (!p)T = s;//���TΪ������sΪT�ĸ��ڵ�
		else if (e.key < p->date.key)p->lchild = s;
		else p->rchild = s;
		return TRUE;
	}
	else return FALSE;
}
int Delete(bstree& p)//ɾ����������
{
	if (!p->rchild)//������Ϊ����ֻ���ؽ�����������
		p = p->lchild;
	else if (!p->lchild)
		p = p->rchild;
	else//������������Ϊ��
	{
		bstree q = p, s = p->lchild;
		while (s->rchild) { q = s; s = s->rchild; }//ת��Ȼ�����ҵ���ͷ
		p->date = s->date;//sָ��ɾ�ڵ��ǰ��
		if (q != p)q->rchild = s->lchild;//�ؽ�q��������
		else q->lchild = s->lchild;//�ؽ�q��������
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
//void secondoptimal(bitree T, TElemtype R[], float sw[], int low, int high)//�������R[low...high]�����ۼ�Ȩֵ��sw�ݹ鹹����Ų�����T
//{
//	int i = low;
//	float min = abs(sw[high] - sw[low]),dw= sw[high] + sw[low-1];
//	for (int j = low + 1; j <= high; ++j)
//	{
//		i = j;
//		min = abs(dw - sw[j] - sw[i - 1]);//abs����������һ�������ľ���ֵ
//	}
//	T->date = R[i];
//	if (i == low)T->lchild = NULL;
//	else secondoptimal(T->lchild, R, sw, low, i - 1);
//	if (i == high)T->rchild = NULL;
//	else secondoptimal(T->rchild, R, sw, i + 1, high);
//}