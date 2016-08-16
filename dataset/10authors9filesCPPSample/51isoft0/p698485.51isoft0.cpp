#include <stdio.h>
#include <string.h>

int m[2000];
int tree[2000];
int kase;
int p,tmp,res;

int main()
{
    freopen("B-small3.in","r",stdin);
    freopen("B-small.out","w",stdout);
    scanf("%d",&kase);
    for(int i=1;i<=kase;i++) {
        scanf("%d",&p);
        for (int j=0;j<(1<<p);j++) scanf("%d",&m[j]);
        for (int j=0;j<p;j++) {
            for (int k=0;k< 1<<(p-j-1);k++ ) scanf("%d",&tmp);
        }
        memset(tree,0,sizeof(tree));
        res=0;
        for (int j=0;j<(1<<p);j++) {
            //printf("%d: ",j);
            tmp=1;
            for (int k=0;k<p-m[j];k++) {
                //printf("%d ",tmp);
                if (!tree[tmp]) tree[tmp]=1,res++;
                if (((1<<(p-k-1))&j)==0) tmp=tmp*2;
                else tmp=tmp*2+1;
            }
            //printf("\n");
        }
        printf("Case #%d: %d\n",i,res);
    }
    return 0;
}
