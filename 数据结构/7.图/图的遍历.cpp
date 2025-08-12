#include<iostream>
using namespace std;
//�ڽӾ����ʾ��
#define true 1
#define OK 1
#define ERROR 1
#define MAXQSIZE 100
#define maxint 32767//��ʾ����ֵ
#define mvnum 100//��󶥵���
typedef char vertextype;//�������������
typedef int arctype;//�ߵ�Ȩֵ
//typedef struct
//{
//	vertextype vexs[mvnum];//�����
//	arctype arcs[mvnum][mvnum];//�ڽӾ���
//	int vexnum, arcnum;//����ͱߵĸ���
//}amgraph;
//int* visited = new int(mvnum);
//static void DFS(amgraph G, int v)//�ڽӾ��󷨱�ʾͼ��������ȱ���ͼG��ʱ�临�Ӷ�O��n��
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
//�ڽӱ��ʾ��
typedef int otherinfo;
typedef struct arcnode//���ڵ�
{
	int adjvex;
	arcnode* nextarc;
	otherinfo info;
}arcnode;
typedef struct vnode//ͷ�ڵ�
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
int initqueue(sqqueue& Q)//��ʼ��˳���
{
	Q.base = new int[MAXQSIZE];
	if (!Q.base)exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}
int queueempty(sqqueue Q)//˳����Ƿ�Ϊ��
{
	if (Q.front==Q.rear)return ERROR;
	return OK;
}
int enqueue(sqqueue& Q, int x)//��˳���
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)return ERROR;
	Q.base[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return OK;
}
int dequeue(sqqueue& Q, int& x)//��˳���
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
void BFS(algraph G, int v)//������ȱ�����O(n+e)
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