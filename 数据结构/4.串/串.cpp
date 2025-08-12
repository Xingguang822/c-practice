#include<iostream>
using namespace std;
#define MAXLEN 255
#define CHUNKSIZE 80
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef struct 
{
	char ch[MAXLEN + 1];
	int length;
}sstring;
typedef struct chunk
{
	char ch[CHUNKSIZE];
	chunk* next;
}chunk;
typedef struct 
{
	chunk* head, * tail;
	int curlen;
}lstring;
/*
stelen(string a);���ַ����ĳ���
strcpy(string a,string b);���ַ���b���Ƶ��ַ���a��
strcat(string a,string b);���ַ���b���ӵ��ַ���a��
strcmp(string a,string b);�Ƚ����ַ����Ƿ���ȣ�>,����1��=������0��<������-1
strlwr(string a);���ַ���a�Ĵ�д��ĸת��ΪСд��ĸ
strupr(string a);���ַ���a��Сд��ĸת��Ϊ��д��ĸ
strncpy(string a,string b,int length);���ַ���b��ǰlength���ַ����Ƶ��ַ���a��
strncmp(string a,string b,int length);�Ƚ����ַ�����ǰlength���ַ��Ƿ���ȣ�>,����1��=������0��<������-1
*/
int index_BF(sstring S, sstring T, int pos)//�����ִ�T������S�е�pos���ַ�֮���λ�ã�ʱ�临�Ӷ�O��n*m��
{
	int i = pos, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++, j++;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length)return i - T.length;
	else return 0;
}
void get_next(sstring T, int next[])
{
	int i = 1,j=0;
	next[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			next[++i] = ++j;
		}
		else
		{
			j = next[j];
		}
	}
}
int index_KMP(sstring S, sstring T, int pos)//�����ִ�T������S�е�pos���ַ�֮���λ�ã�ʱ�临�Ӷ�O��n+m��
{
	int next[MAXLEN + 1];
	get_next(T, next);
	int i = pos, j = 1;
	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++, j++;
		}
		else
			j = next[j];
	}
	if (j >= T.length)return i - T.length;
	else return 0;
}
void get_nextval(sstring T, int nextval[])
{
	int i = 1,j=0;
	nextval[1] = 0;
	while (i < T.length)
	{
		if (j == 0 || T.ch[i] == T.ch[j])
		{
			++i, ++j;
			if (T.ch[i] != T.ch[j])nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}
int index_KMPpromax(sstring S, sstring T, int pos)//�����ִ�T������S�е�pos���ַ�֮���λ�ã�ʱ�临�Ӷ�O��n+m��
{
	int nextval[MAXLEN + 1];
	get_nextval(T, nextval);
	int i = pos, j = 1;
	while (i < S.length && j < T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++, j++;
		}
		else
			j = nextval[j];
	}
	if (j >= T.length)return i - T.length;
	else return 0;
}
int main()
{
	return 0;
}