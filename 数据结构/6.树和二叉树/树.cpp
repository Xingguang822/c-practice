#include<iostream>
using namespace std;
#define MAXTSIZE 100
typedef struct 
{
	int a;
}TElemtype;
typedef struct pnode//双亲表示法
{
	TElemtype date;
	int parent;//双亲位置域
}pnode;//节点结构
typedef struct
{
	pnode node[MAXTSIZE];
	int r, n;//根的位置和结点数
}ptree;//树结构

typedef struct ctnode//孩子表示法
{
	int child;
	ctnode* next;
}ctnode,*childptr;//孩子节点
typedef struct 
{
	TElemtype date;
	childptr firstchild;//孩子链表头指针
}ctbox;//双亲结点
typedef struct
{
	ctbox nodes[MAXTSIZE];
	int r, n;//根的位置和结点数
}ctree;//树结构

typedef struct csnode//孩子兄弟表示法
{
	TElemtype date;
	csnode* firstchild, * nextsibling;
}csnode,*cstree;
int main()
{
	system("pause");
	return 0;
}