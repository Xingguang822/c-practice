#include<iostream>
#include<iterator>
using namespace std;
#define max_num_of_key 8//�ؼ������������ֵ
#define radix 10//�ؼ��ֻ�����ʮ���������Ļ���
#define maxspace 10000
typedef int keytype;
typedef int arrtype[radix];//ָ����������
typedef struct
{
	int  a;
}infotype;
typedef struct
{
	keytype keys[max_num_of_key];//�ؼ���
	infotype otheritems;//����������
	int next;
}slcell;//��̬����Ľ������
typedef struct
{
	slcell r[maxspace];//��̬����Ŀ����ÿռ䣬r[0]Ϊͷָ��
	int keynum;//��¼�ĵ�ǰ�ؼ��ָ���
	int recnum;//��̬����ǰ�ĳ���
}sllist;//��̬��������
void distribute(slcell r[], int i, arrtype& f, arrtype& e)
//��̬����L��r�����򣬰���i���ؼ���key[i]����radix���ӱ�ʹͬһ�ӱ��м�¼��keys[i]��ͬ��f��e�ֱ�ָ����ӱ��е�һ�������һ����¼
{
	int j,p;
	for (j = 0; j < radix; ++j)f[j] = 0;//���ӱ��ʼ��Ϊ�ձ�
	for (p = r[0].next; p; p = r[p].next)
	{
		j = r[p].keys[i];
		if (!f[j])f[j] = p;
		else r[e[j]].next = p;
		e[j] = p;//��p��ָ�����뵽��j���ӱ�
	}
}
void collect(slcell r[], int i, arrtype f, arrtype e)//��keys[i]��f��ָ���ӱ��������ӳ�һ������
{
	int j,t;
	for (j = 0; !f[j]; j=succ(j));//�ҵ�һ���ǿ��ӱ�succΪ���̺���
	r[0].next = f[j]; t = e[j];//r[0].nextָ���һ���ǿ��ӱ��еĵ�һ�����
	while (j < radix)
	{
		for (succ(j); j < radix - 1 && !f[j]; succ(j));//����һ���ǿ��ӱ�
		if (f[j]) { r[t].next = f[j]; t = e[j]; }//���������ǿ��ӱ�
	}
}
void radixsort(sllist& L)//L�ǲ��þ�̬�����ʾ��˳���������������ʹL���ؼ��ִ�С���������̬����L.r[0]Ϊͷ�ڵ�
{
	for (int i = 0; i < L.recnum; ++i)L.r[i].next = i + 1;
	L.r[L.recnum].next = 0;//��L����Ϊ��̬����
	arrtype f, e;
	for (int i = 0; i < L.keynum; ++i)//�����λ�������ζԸ��ؼ��ֽ��з�����ռ�
	{
		distribute(L.r, i, f, e);//��i�˷���
		collect(L.r, i, f, e);//��i���ռ�
	}
}
int main()
{
	return 0;
}