#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(void)
{
	int tc,T;
	scanf("%d\n",&T);
	for (tc=1;tc<=T;tc++){
		int N,M;
		scanf("%d %d\n",&N,&M);
		int i,j;
		int O[M],E[M],P[M];
		for (i=0;i<M;i++){
			scanf("%d %d %d\n",&O[i],&E[i],&P[i]);
		}
		int orgcost=0,mincost=0;
		for (i=0;i<M;i++){
			int k;
			k=E[i]-O[i];
			orgcost+=(k*(2*N+1-k)/2)*P[i];
		}
		int cards[N+1];
		for (i=0;i<=N;i++){
			cards[i]=0;
		}
		for (i=0;i<M;i++){
			for (j=O[i]+1;j<=E[i];j++){
				cards[j]+=P[i];
			}
		}
		while (1){
			int mincards=0;
			for (i=0;i<=N;i++){
				if (mincards==0 || (cards[i]>0 && cards[i]<mincards)){
					mincards=cards[i];
				}
			}
			if (mincards==0)break;
			//fprintf(stderr,"mincards=%d\n",mincards);
			for (i=0;i<=N;i++){
				//fprintf(stderr,"%d : %d\n",i,cards[i]);
			}
			int dist=0;
			for (i=0;i<=N;i++){
				if (cards[i]<mincards){
					if (dist>0){
						//fprintf(stderr,"score add:%d\n",mincards*(dist*(2*N+1-dist)/2));
					}
					mincost+=mincards*(dist*(2*N+1-dist)/2);
					dist=0;
				}
				else dist++;
			}
			if (dist>0){
				//fprintf(stderr,"score add:%d\n",mincards*(dist*(2*N+1-dist)/2));
				mincost+=mincards*(dist*(2*N+1-dist)/2);
			}
			for (i=0;i<=N;i++){
				if (cards[i]>0)
					cards[i]-=mincards;
			}
		}
		printf("Case #%d: %d\n",tc,orgcost-mincost);
	}
	return 0;
}
