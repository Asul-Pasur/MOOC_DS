#include <stdio.h>
#include <stdlib.h>

int Insert(int* MinHeap, int n, int num);
int PrintMin(int* Minheap, int n);

int main(void)
{
	int i, j, k, N, M, num;
	int* MinHeap;

	scanf("%d %d", &N, &M);
	MinHeap = (int *)malloc((N + 1) * sizeof(int));
	for (i = 1; i <= N; i++) {
		scanf("%d", &num);
		Insert(MinHeap, i, num);
	}
	for (i = 0; i < M; i++) {
		scanf("%d", &num);
		PrintMin(MinHeap, num);
	}
	return 0;
}

int Insert(int* MinHeap, int n, int num)
{
	int i;
	while (n != 1 && MinHeap[n / 2] > num) {
		MinHeap[n] = MinHeap[n / 2];
		n = n / 2;
	}
	MinHeap[n] = num;
	return 0;
}

int PrintMin(int* MinHeap, int n)
{
	int flag = 0;

	while (n) {
		if (flag)
			printf(" %d", MinHeap[n]);
		else
			flag = 1, printf("%d", MinHeap[n]);
		n = n / 2;
	}
	printf("\n");
	return 0;
}