#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int K, thissum, maxsum, n;
	int i, j;

	scanf("%d\n", &K);
	maxsum = 0;
	thissum = 0;
	for (i = 0; i < K; i++){
		scanf("%d", &n);
		if (thissum + n >= 0)
			thissum = thissum + n;
		else
			thissum = 0;
		if (thissum >= maxsum)
			maxsum = thissum;
	}
	printf("%d\n", maxsum);
	return 0;
}