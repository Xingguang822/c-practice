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
void selectsort(sqlist& L)//简单选择排序
{
	int i,j,k,temp;
	for (i = 1; i < L.length; ++i)
	{
		k = i;
		for (j = i + 1; j <= L.length; j++)
		{
			if (L.r[j].key < L.r[k].key)k = j;
		}
		if (k != i)
		{
			temp = L.r[i].key;
			L.r[i].key = L.r[k].key;
			L.r[i].key = temp;
		}
	}
}
void heapadjust(sqlist& H, int s, int m)//已知H.r[s].key之外均满足堆的定义，调整H.r[s]的关键字，使H.r[s..m]成为一个大顶堆
{
	redtype rc = H.r[s];
	for (int j = 2 * s; j <= m; j *= 2)
	{
		if (j < m && (H.r[j].key < H.r[j + 1].key))++j;
		if (!(rc.key < H.r[j].key))break;
		H.r[s] = H.r[j]; s = j;
	}
	H.r[s] = rc;
}
void heapsort(sqlist& H)//堆排序
{
	for (int i = H.length / 2; i > 0; --i)//大顶堆的建立
	{
		heapadjust(H, i, H.length);
	}
	for (int i = H.length; i > 1; --i)
	{
		redtype temp = H.r[1];
		H.r[1] = H.r[i];
		H.r[i] = temp;
		heapadjust(H, 1, i - 1);//重新调整为大顶堆
	}
}
int main()
{
	return 0;
}