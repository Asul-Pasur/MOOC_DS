#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	char st[10];
	int N, i, j, k, n, flag;
	int num[31], time[31];
	
	scanf("%d\n", &N);
	flag = 0;
	k = 0;
	for (i = 0; i < 2 * N; i++) {
		scanf("%s", st);
		if (st[1] == 'u') {
			scanf("%d", &num[k]);
			time[k] = 1;
			k++;
		}
		else
		{
			while (k > 0 && time[k - 1] == 2) {
				if (flag)
					printf(" ");
				flag = 1;
				printf("%d", num[k - 1]);
				k--;
			}
			if (k > 0)
				time[k - 1] = 2;
		}
	}
	while(k){
		if (flag)
			printf(" ");
		flag = 1;
			printf("%d", num[--k]);
	}
	printf("\n");
	return 0;
}