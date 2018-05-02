#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, j, k, N;
	char ch;
	int n, m;
	int* Num;

	scanf("%d\n", &N);
	Num = (int*)malloc((N + 1) * sizeof(int));
	for (i = 1; i <= N; i++)
		Num[i] = -1;
	ch = getchar();
	while (ch != 'S') {
		if (ch == 'C') {
			scanf("%d %d\n", &n, &m);
			while (Num[n] > 0)
				n = Num[n];
			while (Num[m] > 0)
				m = Num[m];
			if (n == m)
				printf("yes\n");
			else
				printf("no\n");
		}
		else if (ch == 'I') {
			scanf("%d %d\n", &n, &m);
			while (Num[n] > 0)
				n = Num[n];
			while (Num[m] > 0)
				m = Num[m];
			if (n != m) {      //∞¥¥Û–°UNION//
				if (Num[n] < Num[m]) {
					Num[n] += Num[m];
					Num[m] = n;
				}
				else {
					Num[m] += Num[n];
					Num[n] = m;
				}
			}
		}
		else {
			printf("ERROR\n");
			break;
		}
		ch = getchar();
	}
	n = 0;
	for (i = 1; i <= N; i++)
		if (Num[i] < 0)
			n++;
	if (n != 1)
		printf("There are %d components.\n", n);
	else
		printf("The network is connected.\n");
	return 0;
}