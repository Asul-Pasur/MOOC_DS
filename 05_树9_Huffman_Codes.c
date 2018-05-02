#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include<string.h>

struct HCode {
	char c;
	int f;
	char HC[64];
};
typedef struct HCode* HP;

int HSum(int* num, int n);
int IsHC(HP Code, int n);


int main(void)
{
	int i, j, k, N, M, Sum, sum;
	HP Code ;
	char ch;
	int* num;

	scanf("%d\n", &N);
	Code = (HP)malloc(N * sizeof(struct HCode));
	num = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) {
		Code[i].c = getchar();
		while (Code[i].c == ' ')
			Code[i].c = getchar();
		scanf("%d", &Code[i].f);
		num[i] = Code[i].f;
	}
	Sum = HSum(num, N);
	scanf("%d\n", &M);
	for (j = 0; j < M; j++) {
		sum = 0;
		for (k = 0; k < N; k++) {
			ch = getchar();
			while ((ch == ' ') || (ch == '\n'))
				ch = getchar();
			for (i = 0; i < N; i++)
				if (Code[i].c == ch)
					break;
			if (i == N) {
				printf("ERROR\n");
				break;
			}
			scanf("%s", Code[i].HC);
			sum += strlen(Code[i].HC)*Code[i].f;
		}
		if (sum != Sum) 
			printf("No\n");
		else {
			if (IsHC(Code, N))
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}

int cmp(const void *a, const void *b)

{
	return *(int *)a - *(int *)b;
}

int HSum(int* num,int n) {
	int Sum, i;
	Sum = 0;
	for (i = 0; i < n-1; i++) {
		qsort(&(num[i]), n - i, sizeof(int), cmp);
		num[i + 1] += num[i];
		Sum += num[i + 1];
	}
	return Sum;
}

int IsHC(HP Code, int n)
{
	int i, j, alen, blen;
	char ch;
	for (i = 0; i < n; i++) {
		alen = strlen(Code[i].HC);
		for (j = i + 1; j < n; j++) {
			blen = strlen(Code[j].HC);
			if (alen < blen) {
				ch = (Code[j].HC)[alen];
				(Code[j].HC)[alen] = '\0';
				if (strcmp(Code[i].HC, Code[j].HC) == 0)
					return 0;
				else
					(Code[j].HC)[alen] = ch;
			}
			else {
				ch = (Code[i].HC)[blen];
				(Code[i].HC)[blen] = '\0';
				if (strcmp(Code[i].HC, Code[j].HC) == 0)
					return 0;
				else
					(Code[i].HC)[blen] = ch;
			}
		}
	}
	return 1;
}