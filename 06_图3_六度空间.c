#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct Nodes* NP;

struct Nodes {
	int num; \\记录这是第几轮广度优先便利的结果\\
	int node; \\邻接链表中记录下一个点的位置\\
	NP Next;
};

int main(void)
{
	int i, j, k, N, M, a, b, sum;
	int* visited;
	int* Queue, front, rear;\\用队列进行广度优先便利\\
	NP P, Q;
	double percent;
	
	scanf("%d%d", &N, &M);
	NP Node = (NP)malloc((N + 1) * sizeof(struct Nodes));
	visited = (int*)malloc((N + 1) * sizeof(int));
	Queue = (int*)malloc(N * sizeof(int));
	for (i = 0; i <= N; i++)
		Node[i].Next = NULL;
	for (i = 0; i < M; i++) {
		scanf("%d%d", &a, &b);
		P = (NP)malloc(sizeof(struct Nodes));
		P->node = a;
		P->Next = NULL;
		Q = &(Node[b]);
		while (Q->Next != NULL)
			Q = Q->Next;
		Q->Next = P;
		P = (NP)malloc(sizeof(struct Nodes));
		P->node = b;
		P->Next = NULL;
		Q = &Node[a];
		while (Q->Next != NULL)
			Q = Q->Next;
		Q->Next = P;
	}
	for (i = 1; i <= N; i++) {
		for (j = 0; j <= N; j++)
			visited[j] = 0;
		front = 0; 
		rear = 1;
		Queue[0] = i;
		visited[i] = 1;
		sum = 0;
		Node[i].num = 0;
		while (front != rear ) {
			k = Queue[front++];
			if (Node[k].num > 6)
				break;
			sum++;
			P = Node[k].Next;
			while (P != NULL) {
				if (visited[P->node] == 0)
					Queue[rear++] = P->node, visited[P->node] = 1, Node[P->node].num = Node[k].num + 1;
				P = P->Next;
			}
		}
		percent = 100*(double)sum / N;
		printf("%d: %.2lf%%\n", i, percent);
	}
	return 0;
}