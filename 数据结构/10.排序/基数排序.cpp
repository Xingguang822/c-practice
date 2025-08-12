#include<iostream>
#include<iterator>
using namespace std;
#define max_num_of_key 8//关键字项数的最大值
#define radix 10//关键字基数，十进制整数的基数
#define maxspace 10000
typedef int keytype;
typedef int arrtype[radix];//指针数组类型
typedef struct
{
	int  a;
}infotype;
typedef struct
{
	keytype keys[max_num_of_key];//关键字
	infotype otheritems;//其他数据项
	int next;
}slcell;//静态链表的结点类型
typedef struct
{
	slcell r[maxspace];//静态链表的可利用空间，r[0]为头指针
	int keynum;//记录的当前关键字个数
	int recnum;//静态链表当前的长度
}sllist;//静态链表类型
void distribute(slcell r[], int i, arrtype& f, arrtype& e)
//静态链表L的r域有序，按第i个关键字key[i]建立radix个子表，使同一子表中记录的keys[i]相同，f和e分别指向各子表中第一个和最后一个记录
{
	int j,p;
	for (j = 0; j < radix; ++j)f[j] = 0;//各子表初始化为空表
	for (p = r[0].next; p; p = r[p].next)
	{
		j = r[p].keys[i];
		if (!f[j])f[j] = p;
		else r[e[j]].next = p;
		e[j] = p;//将p所指结点插入到第j个子表
	}
}
void collect(slcell r[], int i, arrtype f, arrtype e)//按keys[i]将f所指各子表依次链接成一个链表
{
	int j,t;
	for (j = 0; !f[j]; j=succ(j));//找第一个非空子表，succ为求后继函数
	r[0].next = f[j]; t = e[j];//r[0].next指向第一个非空子表中的第一个结点
	while (j < radix)
	{
		for (succ(j); j < radix - 1 && !f[j]; succ(j));//找下一个非空子表
		if (f[j]) { r[t].next = f[j]; t = e[j]; }//链接两个非空子表
	}
}
void radixsort(sllist& L)//L是采用静态链表表示的顺序表，对做基数排序，使L按关键字从小到大的有序静态链表，L.r[0]为头节点
{
	for (int i = 0; i < L.recnum; ++i)L.r[i].next = i + 1;
	L.r[L.recnum].next = 0;//将L改造为静态链表
	arrtype f, e;
	for (int i = 0; i < L.keynum; ++i)//按最低位优先依次对各关键字进行分配和收集
	{
		distribute(L.r, i, f, e);//第i趟分配
		collect(L.r, i, f, e);//第i趟收集
	}
}
int main()
{
	return 0;
}