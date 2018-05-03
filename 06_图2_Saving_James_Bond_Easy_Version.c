#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct Cro {
	int x;
	int y;
	int visited;
};

typedef struct Cro* CPos;
int main(void)
{
	int i, j, k, N, D, front, rear, X, Y;
	CPos C, Stack;
	struct Cro Now;
	double dis;

	scanf("%d%d", &N, &D);
	C = (CPos)malloc(N * sizeof(struct Cro));
	Stack = (CPos)malloc((N + 1) * sizeof(struct Cro));
	for (i = 0; i < N; i++) {
		scanf("%d%d", &X, &Y);
		C[i].x = X;
		C[i].y = Y;
		C[i].visited = 0;
	}
	front = 0;
	rear = 0;
	if ((15 >= 50 - D) || (-15 <= D - 50) || (15 >= 50 - D) || (-15 <= D - 50)) {
		printf("Yes\n");
		return 0;
	}
	for (i = 0; i < N; i++) {
		if (C[i].visited == 1)
			continue;
		dis = C[i].x *C[i].x + C[i].y *C[i].y;
		if (dis <= (D+15)*(D+15))
			C[i].visited = 1, Stack[rear++] = C[i];
	}
	while (front != rear) {
		Now = Stack[--rear];
		if ((Now.x >= 50 - D) || (Now.x <= D - 50) || (Now.y >= 50 - D) || (Now.y <= D - 50)) {
			printf("Yes\n");
			return 0;
		}
		for (i = 0; i < N; i++) {
			if (C[i].visited == 1)
				continue;
			dis = (C[i].x - Now.x)*(C[i].x - Now.x) + (C[i].y - Now.y)*(C[i].y - Now.y);
			if (dis <= D*D)
				C[i].visited = 1, Stack[rear++] = C[i];
		}
	}
	printf("No\n");
	return 0;
}