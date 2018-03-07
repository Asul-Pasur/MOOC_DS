#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int K, thissum, maxsum, n, maxf, maxl, thisf, thisl, f, l;
	int i, j, flag;

	scanf("%d\n", &K);
	maxsum = 0;
	thissum = 0;
	maxf = 0;
	maxl = 0;
	thisf = 0;
	thisl = 0;
	flag = 1;
	for (i = 0; i < K; i++){
		scanf("%d", &n);
		if (i == 0)
			f = n;
		if (i + 1 == K)
			l = n;
		if (thissum + n >= 0) {
			thissum = thissum + n;
			if (thisf == 0)
				thisf = n;
			thisl = n;
			flag = 0;
		}
		else {
			thissum = 0;
			thisf = 0;
			thisl = 0;
		}
		if (thissum > maxsum) {
			maxsum = thissum;
			maxl = thisl;
			maxf = thisf;
		}
	}
	if (flag)
		maxf = f, maxl = l;
	else if (maxsum == 0)
		maxf = 0, maxl = 0;
	printf("%d %d %d\n", maxsum, maxf, maxl);
	return 0;
}