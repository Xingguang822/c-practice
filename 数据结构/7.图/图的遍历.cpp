#include<iostream>
using namespace std;
//邻接矩阵表示法
#define true 1
#define OK 1
#define ERROR 1
#define MAXQSIZE 100
#define maxint 32767//表示极大值
#define mvnum 100//最大顶点数
typedef char vertextype;//顶点的数据类型
typedef int arctype;//边的权值
//typedef struct
//{
//	vertextype vexs[mvnum];//顶点表
//	arctype arcs[mvnum][mvnum];//邻接矩阵
//	int vexnum, arcnum;//顶点和边的个数
//}amgraph;
//int* visited = new int(mvnum);
//static void DFS(amgraph G, int v)//邻接矩阵法表示图并深度优先遍历图G，时间复杂度O（n）
//{
//	cout << v; visited[v] = TRUE;
//	for (int w = 0; w < G.vexnum; ++w)
//	{
//		if (G.arcs[v][w]!=0 && !visited[w])
//		{
//			DFS(G, w);
//		}
//	}
//}
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
}vnode, adjlist[mvnum];
typedef struct
{
	adjlist vertices;
	int vexnum, arcnum;
}algraph;
int* visited = new int(mvnum);
typedef struct sqqueue
{
	int* base;
	int front;
	int rear;
};
int initqueue(sqqueue& Q)//初始化顺序队
{
	Q.base = new int[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queueempty(sqqueue Q)//顺序队是否为空
{
	if (Q.front==Q.rear)return ERROR;
	return OK;
}
int enqueue(sqqueue& Q, int x)//入顺序队
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, int& x)//出顺序队
{
	if (Q.front == Q.rear)return ERROR;
	x = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return OK;
}
int firstadjver(algraph G, int u)
{
	for (int i = 0; i < G.vexnum; ++i)
	{
		if (G.vertices[i].date== u)return i;
	}
	return ERROR;
}
int nextadjvex(algraph G, int u, int w)
{

}
void BFS(algraph G, int v)//广度优先遍历，O(n+e)
{
	cout << v; visited[v] = true;
	sqqueue Q;
	initqueue(Q);
	enqueue(Q, v);
	int u;
	while (!queueempty(Q))
	{
		dequeue(Q, u);
		for (int w = firstadjver(G, u); w > 0; w = nextadjvex(G, u, w))
		{
			cout << w; visited[w] = true; enqueue(Q, w);
		}
	}
}
int main()
{
	system("pause");
	return 0;
}