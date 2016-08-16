#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

int main(void)
{
	int t,T;
	scanf("%d\n",&T);
	for (t=1;t<=T;t++){
		int N,X;
		scanf("%d %d\n",&N,&X);
		int n;
		int S[N];
		int flag[N];
		int ans=N;
		for (n=0;n<N;n++){
			scanf("%d ",&S[n]);
			flag[n]=0;
		}
		std::sort(S,S+n);
		for (n=0;n<N;n++){
			if (flag[n])continue;
			flag[n]=1;
			int nn;
			for (nn=N-1;nn>=n+1;nn--){
				if (flag[nn])continue;
				if (S[n]+S[nn]<=X){
					//fprintf(stderr,"%d %d\n",S[n],S[nn]);
					flag[nn]=1;
					ans--;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
