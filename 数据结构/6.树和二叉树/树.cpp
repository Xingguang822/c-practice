#include<iostream>
using namespace std;
#define MAXTSIZE 100
typedef struct 
{
	int a;
}TElemtype;
typedef struct pnode//˫�ױ�ʾ��
{
	TElemtype date;
	int parent;//˫��λ����
}pnode;//�ڵ�ṹ
typedef struct
{
	pnode node[MAXTSIZE];
	int r, n;//����λ�úͽ����
}ptree;//���ṹ

typedef struct ctnode//���ӱ�ʾ��
{
	int child;
	ctnode* next;
}ctnode,*childptr;//���ӽڵ�
typedef struct 
{
	TElemtype date;
	childptr firstchild;//��������ͷָ��
}ctbox;//˫�׽��
typedef struct
{
	ctbox nodes[MAXTSIZE];
	int r, n;//����λ�úͽ����
}ctree;//���ṹ

typedef struct csnode//�����ֵܱ�ʾ��
{
	TElemtype date;
	csnode* firstchild, * nextsibling;
}csnode,*cstree;
int main()
{
	system("pause");
	return 0;
}