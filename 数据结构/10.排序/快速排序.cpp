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
void bubble_sort(sqlist& L)//ð������
{
	//��һ��д��
	for (int i= 0; (mi< L.length-1); ++i)
	{
		for (int j = 1; j < L.length - i-1; ++j)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				swap(L.r[j].key, L.r[j+1].key);
			}
		}
	}
	//�ڶ���д��
	bool swaped;
	for (int i = 0; i < L.length - 1; ++i)
	{
		swaped = false;
		for (int j = 0; j < L.length - 1 - i; ++j)
		{
			if (L.r[j].key > L.r[j + 1].key)
			{
				swap(L.r[j].key, L.r[j + 1].key);
				swaped = true;
			}
		}
		if (!swaped)break;
	}
	//������д��
	bool swapped = true;
	int last_unsorted_index = L.length - 1;
	int swapped_index = -1;
	while (swapped)
	{
		swapped = false;
		for (int i = 0; i < last_unsorted_index; i++) {
			if (L.r[i].key > L.r[i + 1].key)
			{
				swap(L.r[j].key, L.r[j + 1].key);
				swapped = true;
				swapped_index = i;
			}
		}
		last_unsorted_index = swapped_index;
	}
}
int partition(sqlist& L, int low, int high)//��������
{
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while (low < high)
	{
		while (low < high && L.r[high].key >= pivotkey)--high;
		L.r[low] = L.r[high];
		while (low < high && L.r[low].key >= pivotkey)++low;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}
void qsort(sqlist& L, int low, int high)
{
	if (low < high)
	{
		int pivotloc = partition(L, low, high);//��L.r[low..high]һ��Ϊ����pivotlocΪ����Ԫ���ź����λ��
		qsort(L, low, pivotloc - 1);//�Ե��ӱ�ݹ�����
		qsort(L, pivotloc + 1, high);//�Ը��ӱ�ݹ�����
	}
}
int main()
{
	return 0;
}