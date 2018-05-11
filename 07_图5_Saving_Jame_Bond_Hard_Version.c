#include<stdio.h>
#include<stdlib.h>

struct CroP {
	int x;
	int y;
};
typedef struct CroP* CP;

int Print(int* path, int n, CP C, int i);

int main(void)
{
	int i, j, k, N, D, X, Y, Min, Mini, Now, flag = 0, d;
	CP C;
	int* Vis, *Path;
	int*Q, *Dis, front, rear;

	scanf("%d%d", &N, &D);
	C = (CP)malloc(N * sizeof(struct CroP));
	Vis = (int*)malloc(N * sizeof(int));
	Path = (int*)malloc(N * sizeof(int));
	Q = (int*)malloc((N + 1) * sizeof(int));
	Dis = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		scanf("%d%d", &X, &Y);
		C[i].x = X;
		C[i].y = Y;
		Vis[i] = 0;
		Path[i] = -1;
		Dis[i] = (C[i].x * C[i].x) + (C[i].y*C[i].y);
	}
	if (D >= 50 - 7.5) {
		printf("1\n");
		return 0;
	}
	front = 0;
	rear = 0;
	while (1) {
		for (i = 0; i < N; i++)
			if (Vis[i] == 0) {
				Min = Dis[i];
				Mini = i;
				break;
			}
		if (i == N)
			break;
		for (; i < N; i++)
			if (Dis[i] < Min&&Vis[i] == 0)
				Min = Dis[i], Mini = i;
		if (Min <= ((double)D + 7.5)*((double)D + 7.5))
			Q[rear++] = Mini, Vis[Mini] = 1;
		else
			break;
	}
	if (front == rear) {
		printf("0\n");
		return 0;
	}
	while (front != rear) {
		Now = Q[front++];
		if (front == N+1)
			front = 0;
		if (C[Now].x >= 50 - D || C[Now].x <= D - 50 || C[Now].y >= 50 - D || C[Now].y <= D - 50) {
			flag = Print(Path, Now, C, 1);
			break;
		}
		for (i = 0; i < N; i++) {
			d = (C[Now].x - C[i].x)*(C[Now].x - C[i].x) + (C[Now].y - C[i].y)*(C[Now].y - C[i].y);
			if (Vis[i] == 0 && d <= D*D) {
				Q[rear++] = i;
				Vis[i] = 1;
				Path[i] = Now;
				if (rear == N + 1)
					rear = 0;
			}
		}
	}
	if (flag == 0) 
		printf("0\n");
	return 0;
}

int Print(int* path, int n,CP C,int i)
{

	if (n == -1) {
		printf("%d\n", i);
		return 1;
	}
	Print(path, path[n], C, i + 1);
	printf("%d %d\n", C[n].x, C[n].y);
	return 1;
}