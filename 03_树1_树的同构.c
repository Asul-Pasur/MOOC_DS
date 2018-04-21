#include<stdio.h>
#include<stdlib.h>

int Is(char* ch1, char* ch2, int* left1, int* left2, int* right1, int* right2, int n1, int n2);

int main(void)
{
	char ch1[11], ch2[11];
	int left1[11], right1[11], left2[11], right2[11];
	int i, j, k, N, M, flag, n1, n2;
	char l, r;

	scanf("%d\n", &N);
	for (i = 0; i < N; i++) {
		scanf("%c %c %c\n", &ch1[i], &l, &r);
		if (l != '-')
			left1[i] = l - '0';
		else
			left1[i] = -1;
		if (r != '-')
			right1[i] = r - '0';
		else
			right1[i] = -1;
	}
	scanf("%d\n", &M);
	for (i = 0; i < M; i++) {
		scanf("%c %c %c\n", &ch2[i], &l, &r);
		if (l != '-')
			left2[i] = l - '0';
		else
			left2[i] = -1;
		if (r != '-')
			right2[i] = r - '0';
		else
			right2[i] = -1;
	}

	if (N != M) {
		printf("No\n");
		return 0;
	}
	if (N == 0) {
		printf("Yes\n");
		return 0;
	}

	n1 = 0;
	for (i = 0; i < N; i++) {
		n1 += i;
		if (left1[i] != -1)
			n1 -= left1[i];
		if (right1[i] != -1)
			n1 -= right1[i];
	}
	n2 = 0;
	for (i = 0; i < N; i++) {
		n2 += i;
		if (left2[i] != -1)
			n2 -= left2[i];
		if (right2[i] != -1)
			n2 -= right2[i];
	}

	flag = Is(ch1, ch2, left1, left2, right1, right2, n1, n2);
	if (flag == 0)
		printf("No\n");
	else
		printf("Yes\n");
	return 0;
}

int Is(char* ch1, char* ch2, int* left1, int* left2, int* right1, int* right2, int n1, int n2)
{
	int a, b;
	if (n1 == -1 && n2 == -1)
		return 1;
	else if ((n1 == -1 && n2 != -1) || (n1 != -1 && n2 == -1))
		return 0;
	if (ch1[n1] != ch2[n2])
		return 0;
	a = Is(ch1, ch2, left1, left2, right1, right2, left1[n1], left2[n2])*Is(ch1, ch2, left1, left2, right1, right2, right1[n1], right2[n2]);
	b = Is(ch1, ch2, left1, left2, right1, right2, left1[n1], right2[n2])*Is(ch1, ch2, left1, left2, right1, right2, right1[n1], left2[n2]);
	return a || b;
}