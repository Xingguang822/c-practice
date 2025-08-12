#include<iostream>
using namespace std;
#define maxsize 20
typedef int keytype;
typedef struct
{
	int  a;
}infotype;
typedef struct
{
	keytype key;
	infotype otherinfo;
}redtype;
typedef struct
{
	redtype r[maxsize + 1];
	int length;
}sqlist;
void insertsort(sqlist& L)//ֱ�Ӳ�������
{
	int i, j;
	for (i = 2; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - 1].key)//��<���轫L.r[i]���������ӱ�
		{
			L.r[0] = L.r[i];
			for (j = i - 1; L.r[0].key < L.r[j].key; --j)
			{
				L.r[j + 1] = L.r[j];
			}
			L.r[j + 1] = L.r[0];//���뵽��ȷλ��
		}
	}
}
void binsertsort(sqlist& L)//�۰��������
{
	for (int i = 2; i <= L.length; --i)
	{
		L.r[0] = L.r[i];
		int low = 1, high = i - 1,mid;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (L.r[0].key < L.r[mid].key)high = mid - 1;
			else low = mid + 1;
		}//ѭ������high+1��Ϊ����λ��
		for (int j = i - 1; j >= high; --j)
		{
			L.r[j + 1] = L.r[j];
		}
		L.r[high + 1] = L.r[0];
	}
}
void shellinsert(sqlist& L, int dk)
{
	for (int i = dk + 1; i <= L.length; ++i)
	{
		if (L.r[i].key < L.r[i - dk].key)
		{
			L.r[0] = L.r[i];
			int j;
			for (j = i - dk; j > 0 && (L.r[0].key < L.r[j].key); j -= dk)
			{
				L.r[j + dk] = L.r[j];
			}
			L.r[j + dk] = L.r[0];
		}
	}
}
void shellsort(sqlist& L, int dlta[], int t)//ϣ�������������dlta[0..t-1]Ϊ��������
{
	for (int k = 0; k < t; ++k)shellinsert(L, dlta[k]);
}
int main()
{
	return 0;
}