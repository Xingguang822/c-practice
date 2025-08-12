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
stelen(string a);求字符串的长度
strcpy(string a,string b);将字符串b复制到字符串a中
strcat(string a,string b);将字符串b连接到字符串a后
strcmp(string a,string b);比较两字符串是否相等；>,返回1；=，返回0；<，返回-1
strlwr(string a);将字符串a的大写字母转变为小写字母
strupr(string a);将字符串a的小写字母转变为大写字母
strncpy(string a,string b,int length);将字符串b的前length个字符复制到字符串a中
strncmp(string a,string b,int length);比较两字符串的前length个字符是否相等；>,返回1；=，返回0；<，返回-1
*/
int index_BF(sstring S, sstring T, int pos)//返回字串T在主串S中第pos个字符之后的位置，时间复杂度O（n*m）
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
int index_KMP(sstring S, sstring T, int pos)//返回字串T在主串S中第pos个字符之后的位置，时间复杂度O（n+m）
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
int index_KMPpromax(sstring S, sstring T, int pos)//返回字串T在主串S中第pos个字符之后的位置，时间复杂度O（n+m）
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