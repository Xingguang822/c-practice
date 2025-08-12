#include<iostream>
using namespace std;
typedef int keytype;
typedef struct
{
	keytype key;
	int a;
}elemtype;
typedef struct
{
	elemtype* R;
	int length;
}sstable;//˳���
int search_seq(sstable ST, keytype key)//˳�����,�ñ�����������
{
	int i;
	ST.R[0].key = key;
	for (i = ST.length; ST.R[i].key != key; --i);
	return i;
}
int search_bin(sstable ST, keytype key)//�۰���ң��ñ�Ϊ�����
{
	int low = 1, high = ST.length,mid;
	while (low<=high)
	{
		mid = (high + low) / 2;
		if (ST.R[mid].key > key)
		{
			high = mid - 1;
		}
		if (ST.R[mid].key == key)
		{
			return mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return 0;
}
int main()
{
	return 0;
}