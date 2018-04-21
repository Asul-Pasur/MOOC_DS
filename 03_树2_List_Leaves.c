#include<stdio.h>
#include<stdlib.h>

int found(int n, int* left, int* right,int N);

int main(void)
{
	int left[11], right[11];
	int i, j, k, N, M, flag, n;
	char l, r;

	scanf("%d\n", &N);
	for (i = 0; i < N; i++) {
		scanf("%c %c\n", &l, &r);
		if (l != '-')
			left[i] = l - '0';
		else
			left[i] = -1;
		if (r != '-')
			right[i] = r - '0';
		else
			right[i] = -1;
	}

	if (N == 0) {
		printf("\n");
		return 0;
	}

	n = 0;
	for (i = 0; i < N; i++) {
		n += i;
		if (left[i] != -1)
			n -= left[i];
		if (right[i] != -1)
			n -= right[i];
	}
	found(n, left, right, N);
	return 0;
}

int found(int n, int* left, int* right,int N) 
{
	int Q[11], i, j, flag = 1;
	i = 0;
	Q[0] = n;
	for (j = 1; i < j; i++) {
		if (left[Q[i]] != -1)
			Q[j++] = left[Q[i]];
		if (right[Q[i]] != -1)
			Q[j++] = right[Q[i]];
		if (left[Q[i]] == -1 && right[Q[i]] == -1) {
			if (flag == 1)
				printf("%d", Q[i]), flag = 0;
			else
				printf(" %d", Q[i]);
		}
	}
	printf("\n");
	return 0;
}