#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k, N, M, a, b, D, Max, MaxN, Maxi;
	int** G;
	int **Path;


	scanf("%d%d", &N, &M);
	if (N == 1) {
		printf("1\n");
		return 0;
	}
	G = (int**)malloc((N + 1) * sizeof(int*));
	Path = (int**)malloc((N + 1) * sizeof(int*));
	for (i = 0; i <= N; i++) {
		Path[i] = (int*)malloc((N + 1) * sizeof(int));
		G[i] = (int*)malloc((N + 1) * sizeof(int));
		for (j = 0; j <= N; j++) {
			if (i != j)
				G[i][j] = 100001;
			else
				G[i][j] = 0;
			Path[i][j] = -1;
		}
	}
	for (i = 0; i < M; i++) {
		scanf("%d%d%d", &a, &b, &D);
		G[a][b] = D;
		G[b][a] = D;
	}
	for (k = 1; k < N + 1; k++)
		for (i = 1; i < N + 1; i++)
			for (j = 1; j < N + 1; j++)
				if (G[i][k] + G[k][j] < G[i][j]) {
					G[i][j] = G[i][k] + G[k][j];
					Path[i][j] = k;
				}
	Max = 100001;
	Maxi = 0;
	for (i = 1; i < N + 1; i++) {
		MaxN = G[i][1];
		for (j = 2; j < N + 1; j++)
			if (G[i][j] > MaxN)
				MaxN = G[i][j];
		if (MaxN < Max)
			Max = MaxN, Maxi = i;
	}
	if (Max == 100001)
		printf("0\n");
	else
		printf("%d %d\n", Maxi, Max);
	return 0;
}