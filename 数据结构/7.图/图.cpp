#include<iostream>
using namespace std;
#define OK 1
//邻接矩阵表示法
#define maxint 32767//表示极大值
#define mvnum 100//最大顶点数
typedef char vertextype;//顶点的数据类型
typedef int arctype;//边的权值
typedef struct
{
	vertextype vexs[mvnum];//顶点表
	arctype arcs[mvnum][mvnum];//邻接矩阵
	int vexnum, arcnum;//顶点和边的个数
}amgraph;
int locatevex(amgraph G, int n)
{
	for (int m = 0; m < G.vexnum; ++m)
	{
		if (G.vexs[m] == n)
			return m;
	}
	return -1;
}
int createudn(amgraph& G)//构造无向网,用邻接矩阵法建立
{
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vexs[i];
	}
	for (int i = 0; i <G.arcnum; ++i)
	{
		for (int j = 0; j <G.arcnum; ++j)
		{
			G.arcs[i][j] = maxint;
		}
	}
	int v1, v2, w, i, j;
	for (int k = 0; k < G.arcnum; ++k)
	{
		v1, v2, w;
		cin >> v1 >> v2 >> w;
		i = locatevex(G, v1);
		j = locatevex(G, v2);
		G.arcs[i][j] = G.arcs[j][i] = w;
	}
	return OK;
}
//邻接表表示法
typedef int otherinfo;
typedef struct arcnode//弧节点
{
	int adjvex;
	arcnode* nextarc;
	otherinfo info;
}arcnode;
typedef struct vnode//头节点
{
	vertextype date;
	arcnode* firstarc;
}vnode,adjlist[mvnum];
typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;
}algraph;
int locatevex(algraph G, int n)
{
	for (int m = 0; m < G.vexnum; ++m)
	{
		if (G.vertices[m].date == n)
			return m;
	}
	return -1;
}
int createudg(algraph& G)//构造无向网，用邻接表法建立
{
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; ++i)
	{
		cin >> G.vertices[i].date;
		G.vertices[i].firstarc = NULL;
	}
	int v1, v2,i,j;
	for (int k = 0; k < G.arcnum; ++k)
	{
		cin >> v1 >> v2;
		i = locatevex(G, v1);
		j = locatevex(G, v2);
		arcnode* p1 = new arcnode;
		p1->adjvex = j;
		p1->nextarc = G.vertices[i].firstarc;//头插法，将p1放在G的弧节点的第一个
		G.vertices[i].firstarc = p1;
		arcnode* p2 = new arcnode;
		p2->adjvex = i;
		p2->nextarc = G.vertices[j].firstarc;
		G.vertices[j].firstarc = p2;
	}
	return OK;
}
//十字链表表示法
typedef int infotype;
typedef struct arcbox
{
	int tailvex, headvex;
	arcbox* hlink, * tlink;
	infotype info;
}arcbox;
typedef struct vexnode
{
	vertextype date;
	arcbox* firstin, * firstout;
}vexnode;
typedef struct
{
	vexnode xlist[mvnum];
	int vexnum, arcnum;
}olgraph;
//邻接多重表表示法
typedef enum{unvisited,visited} visitif;
typedef struct ebox
{
	visitif mark;
	int ivex, jvex;
	ebox* ilink, * jlink;
	infotype info;
}ebox;
typedef struct vexbox
{
	vertextype date;
	ebox* firstedge;
}verbox;
typedef struct
{
	vexbox adjmulist[mvnum];
	int vexnum, arcnum;
}amlgraph;
int main()
{
	system("pause");
	return 0;
}