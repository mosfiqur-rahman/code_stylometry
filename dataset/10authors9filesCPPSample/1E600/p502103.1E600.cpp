#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int i,t;
	int ret;
	int T,N,K;
	scanf("%d\n",&T);
	for (i=0;i<T;i++){
		scanf("%d %d\n",&N,&K);
		t=(1<<N)-1;
		if ((t & K) == t)
			printf("Case #%d: ON\n",i+1);
		else
			printf("Case #%d: OFF\n",i+1);
	}
	return 0;
}
