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
void merge(redtype SR[], redtype TR[], int i, int m, int n)//¶þÂ·¹é²¢ÅÅÐò
{
	int j, k;
	for ( j = m + 1, k = i; i <= m && j <= n; ++k)
	{
		if (SR[i].key < SR[j].key)TR[k] = SR[i++];
		else TR[k] = SR[j++];
	}
	if (i <= m)TR[k++] = SR[i++];
	if (j <= n)TR[k++] = SR[i++];
}
void mergesort(redtype SR[], redtype TR1[], int s, int t)
{
	if (s == t)TR1[s] = SR[s];
	else
	{
		redtype* TR2=new redtype;
		int m = (s + t) / 2;
		mergesort(SR, TR2, s, m);
		mergesort(SR, TR2, m + 1, t);
		merge(TR1, TR2, s, m, t);
	}
}
int main()
{
	return 0;
}