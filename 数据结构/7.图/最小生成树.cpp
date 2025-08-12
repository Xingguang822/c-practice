#include<iostream>
#include<stdlib.h>
using namespace std;
//�ڽӾ����ʾ��
#define maxint 32767//��ʾ����ֵ
#define mvnum 100//��󶥵���
typedef char vertextype;//�������������
typedef int arctype;//�ߵ�Ȩֵ
typedef struct
{
	vertextype vexs[mvnum];//�����
	arctype arcs[mvnum][mvnum];//�ڽӾ���
	int vexnum, arcnum;//����ͱߵĸ���
}amgraph;
struct cnode
{
	vertextype adjvex;
	int lowcost;
}closedge[mvnum];
int locatevex(amgraph G, int n)
{
	for (int m = 0; m < G.vexnum; ++m)
	{
		if (G.vexs[m] == n)
			return m;
	}
	return -1;
}
int minimun(cnode* cc)
{
	cnode aa;
	aa.lowcost = cc[0].lowcost;
	for (int i = 1; i < mvnum; ++i)
	{
		if (aa.lowcost > cc[i].lowcost&&cc[i].lowcost!=0)
			aa.lowcost = cc[i].lowcost;
	}
	return aa.lowcost;
}
void minispantree_PRIM(amgraph G, vertextype u)//����ķ�㷨
{
	int k = locatevex(G, u);
	for (int n = 1; n < G.vexnum; ++n)
	{
		if (n != k)closedge[n] = { u,G.arcs[k][n] };
	}
	closedge[k].lowcost = 0;
	for (int i = 0; i < G.vexnum; ++i)
	{
		k = minimun(closedge);
		printf("%c", closedge[k].adjvex, G.vexs[k]);
		closedge[k].lowcost = 0;
		for (int j = 0; j < G.vexnum; ++j)
		{
			if (G.arcs[k][j] < closedge[j].lowcost)
			{
				closedge[j] = { G.vexs[k],G.arcs[k][j] };
			}
		}
	}
}
int main()
{
	system("pause");
	return 0;
}