#include<iostream>
using namespace std;
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct
{
	int a;
}Elemtype;
typedef struct LNode
{
	Elemtype date;
	struct LNode* next;
}lnode,*linklist;
int initlist(linklist& L)//����һ���ձ�
{
	L = new lnode;
	L->next = NULL;
	return OK;
}
int destroylist(linklist& L)//��������
{
	lnode* p;
	while (L != NULL)
	{
		p = L;
		L = L->next;
		delete p;
	}
	return OK;
}
int listempty(linklist L)//�ж������Ƿ�Ϊ��
{
	if (L->next)
	{
		return 0;
	}
	else return 1;
}
int clearlist(linklist& L)//������L����Ϊ�ձ����ͷ�ԭ����Ľ��ռ�
{
	LNode* p, * q;
	p = L->next;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
	L->next = NULL;
	return OK;
}
int getlength(linklist L)//�õ�����ı�
{
	LNode* p;
	p = L->next;
	int i = 0;
	while (p)
	{
		p = p->next;
		i++;
	}
	return i;
}
int getelem(linklist L, int i, Elemtype& e)//��ȡ���Ա���ĳ������Ԫ�ص����ݣ�����e����
{
	linklist p = L->next;
	int j = 1;
	while (p && j < i)p = p->next; j++;
	if (!p || j > i)return FALSE;
	e = p->date;
	return OK;
}
int operator!=(Elemtype a, Elemtype b)
{
	if (a != b)
		return 1;
	else return 0;
}
int locateelem(linklist L,Elemtype e)//����L��ֵΪe������Ԫ�ص����O(1)
{
	linklist p = L->next;
	int j = 1;
	while (p&&(p->date!=e))
		p = p->next;++j;
	if(p) return j;
	else  return 0;
}
lnode* locateElem(linklist L, Elemtype e)//��������Ԫ���е���e�����ݵĵ�ַ
{
	linklist p = L->next;
	while (p && p->date != e)p = p->next;
	return p;
}
int listinsert(linklist& L, int i, Elemtype e)//�ڵ�i���ڵ�ǰ�����µĽڵ�O(n)
{
	int j = 0;
	linklist p = L;
	while (p && j < i - 1)p = p->next; ++j;
	if (!p || j > i - 1)return ERROR;
	lnode* s = new lnode; s->date = e;
	s->next = p->next;
	p -> next = s;
	return OK;
}
int deletelist(linklist& L, int i, Elemtype& e)//ɾ����i���ڵ�O(n)
{
	int j = 0;
	linklist p = L;
	while ((p->next )&& j < i - 1)p = p->next; ++j;
	if (!(p->next) || j > i - 1)return ERROR;
	linklist q = p->next;
	p->next = q->next;
	e = q->date;
	delete q;
	return OK;
}
int operator<=(Elemtype a, Elemtype b)
{
	if (a <= b)
		return 1;
	else return 0;
}
void mergelist(linklist& La, linklist& Lb, linklist& Lc)//�鲢Lb��Laʹ������LcҲ��ֵ�ǵݼ�����
{
	linklist pa = La->next, pb = Lb->next,pc;
	Lc=pc= La;
	while (pa && pb)
	{
		if (pa->date <= pb->date)
		{
			pc->next = pa;
			pc = pa;
			pa = pa->next;
		}
		else
		{
			pc->next = pb;
			pc = pb;
			pb = pb->next;
		}
	}
	pc->next = pa ? pa : pb;
	delete pb;
}
linklist connect(linklist La, linklist Lb)//ѭ������Ľ���
{
	La->next = Lb->next->next;
	delete Lb->next;
	Lb->next = La->next;
	return Lb;
}
void createlist(linklist L, int n)//��λ������n��Ԫ�ص�ֵ������������
{
	L = new lnode; L->next = NULL;
	linklist r = L;
	for (int i = 0; i < n; i++)
	{
		int j; cin >> j;
		linklist p = new lnode{ (i,NULL) };
		r->next = p;
		r = p;
	}
}
typedef struct DulNode
{
	Elemtype date;
	DulNode* prior, * next;
}dulnode,*dulinklist;
dulnode* getelem(dulinklist L, int i)//��ȡ���Ա���ĳ������Ԫ�ص�����
{
	dulinklist p = L->next;
	int j = 1;
	while (p && j < i)p = p->next; j++;
	return p;
}
int insertdulist(dulinklist& L, int i, Elemtype e)//�ڴ�ͷ����˫������L�е�I��λ��ǰ����e
{
	dulinklist p;
	if (!(p = getelem(L, i)))return ERROR;
	dulinklist s = new dulnode;
	s->date = e;
	s->next = p;s->prior = p->prior;
	p->prior->next = s; p->prior = s;
	return OK;
}
int deletedulist(dulinklist& L, int i, Elemtype e)//�ڴ�ͷ����˫������L��ɾ����i��Ԫ�ز���e����
{
	dulinklist p;
	if (!(p = getelem(L, i)))return ERROR;
	e = p->date;
	p->next->prior = p->prior;
	p->prior->next = p->next;
	delete p;
	return OK;
}
int main()
{
	return 0;
}