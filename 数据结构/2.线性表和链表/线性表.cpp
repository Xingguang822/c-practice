#include<iostream>
#include<stdlib.h>
using namespace std;
#define INIT_LIST_SIZE 100
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct
{
	int a;
	float b;
}Elemtype;
typedef struct
{
	Elemtype* elem;
	int length;
	int listsize;
}sqlist;
int initlist(sqlist& L)//����һ���յ����Ա�L
{
	L.elem=(Elemtype*)malloc(INIT_LIST_SIZE * sizeof(Elemtype));
	if (!L.elem)exit(OVERFLOW);
	L.length = 0;
	L.listsize = INIT_LIST_SIZE;
	return	OK;
}
void destroylist(sqlist& L)//�������Ա�L
{
	if (L.elem)
		delete L.elem;
}
void clearlist(sqlist& L)//������Ա�
{
	L.length = 0;
}
int listempty(sqlist L)//�ж����Ա��Ƿ�Ϊ��
{
	if (L.elem)
		return OK;
	else return FALSE;
}
int listlength(sqlist L)//����Ԫ�ظ���
{
	return(L.length);
}
int getelem(sqlist L, int i, Elemtype& e)//��e����L�е�i��Ԫ�ص�ֵ
{
	if (i<1 || i>L.length) return FALSE;
	e = L.elem[i - 1]; return OK;
}
int listinsert(sqlist& L, int i, Elemtype e)//��L�е�i��λ�ò���e
{
	if (i<1 || i>L.length)return FALSE;
	if (L.length >= L.listsize)
	{
		Elemtype* newbase = (Elemtype*)realloc(L.elem, (L.listsize + INIT_LIST_SIZE) * sizeof(Elemtype));
		if (!newbase)exit(OVERFLOW);
		L.elem = newbase;
		L.listsize+ = INIT_LIST_SIZE;
	}
	for (int j = L.length - 1; j >= i - 1; j--)
	{
		L.elem[j + 1] = L.elem[j];
	}
	L.elem[i - 1] = e;
	L.length++;
	return TRUE;
}
int listdelete(sqlist& L, int i, Elemtype e)//ɾ����i��Ԫ�ز���e������ֵ
{
	if (i<1 || i>L.length)return FALSE;
	e = L.elem[i - 1];
	for (int j = i - 1; j < L.length - 1; j++)
	{
		L.elem[j] = L.elem[j + 1];
	}
	L.length--;
	return OK;
}
bool operator==(Elemtype a, Elemtype b)
{
	if (a == b)return TRUE;
	return FALSE;
}
int locateelem(sqlist L, Elemtype e)//�ҵ���һ������e��Ԫ�ص�λ��
{
	for (int i = 0; i < L.length; i++)
	{
		if (L.elem[i] == e)
			return i + 1;
	}
	return FALSE;
}
void unionlist(sqlist& La, sqlist Lb)//����Lb������La�е�Ԫ�ز��뵽La��
{
	La.length = listlength(La), Lb.length = listlength(Lb);
	for (int i = 1; i <= Lb.length; i++)
	{
		Elemtype e;
		getelem(Lb, i, e);
		if (!locateelem(La, e))listinsert(La, ++La.length, e);
	}
}
bool operator<=(Elemtype a, Elemtype b)
{
	if (a <= b)return TRUE;
	return FALSE;
}
void mergelist(sqlist La, sqlist Lb, sqlist& Lc)//�鲢La��Lb�õ��µ����Ա�Lc����ֵ�ǵݼ�����
{
	Elemtype* pa = La.elem, * pb = Lb.elem;
	Lc.listsize = Lc.length = La.length + Lb.length;
	Lc.elem = new Elemtype[Lc.length];
	Elemtype* pc = Lc.elem;
	Elemtype* pa_last, * pb_last;
	pa_last = La.elem + La.length - 1;
	pb_last = Lb.elem + Lb.length - 1;
	while (pa <= pa_last && pb <= pb_last)
	{
		if (*pa <= *pb)*(pc++) = *(pa++);
		else *(pc++) = *(pb++);
	}
	while (pa <= pa_last)*(pc++) = *(pa++);
	while (pb <= pb_last)*(pc++) = *(pb++);
}
int main()
{
	return 0;
}