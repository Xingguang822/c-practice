#include<iostream>
using namespace std;
typedef char** huffmancode;
typedef struct
{
	int weight;
	int parent, lch, rch;
}htnode,*huffmantree;
void select(huffmantree HT, int n, int s1, int s2)
{
	int min = HT[1].weight,s1=s2=1;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].weight < min)
		{
			min = HT[i].weight;
			s2 = i;
		}
	}
	int nextmin = HT[1].weight;
	for (int i = 1; i <= n; i++)
	{
		if (HT[i].weight < nextmin&&nextmin>=min)
		{
			nextmin = HT[i].weight;
			s1 = i;
		}
	}
}
void createhuffmantree(huffmantree HT, int n)//构造哈夫曼树
{
	if (n <= 1)return ;
	int m = 2 * n - 1;
	HT = new htnode[m+1];
	for (int i = 1; i <= m; i++)
	{
		HT[i].parent = 0; HT[i].lch = 0; HT[i].rch = 0;
	}
	for(int i=1;i<=n;++i)cin>>HT[i].weight;
	for (int i = n + 1; i <= m; i++)
	{
		int s1=0, s2=0;
		select(HT, i - 1, s1, s2);
		HT[s1].parent = i;
		HT[s2].parent = i;
		HT[i].lch = s1;
		HT[i].rch = s2;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}
void creathuffmancode(huffmantree HT, huffmancode& HC, int n)//从叶子到根逆向求每个字符的哈夫曼编码，存储在编码表HC中
{
	HC = new char* [n + 1];
	char* cd = new char[n];
	cd[n - 1] = '\0';
	for (int i = 1; i <= n; ++i)
	{
		int start = n - 1, c = i, f = HT[i].parent;
		while (f != 0)
		{
			--start;
			if (HT[f].lch == c)cd[start] = '0';
			else cd[start] = '1';
			c = f; f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}
	delete cd;
}
int main()
{

	system("pause");
	return 0;
}