#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[1010][1010];
int kase,k,res;
bool able;

bool pd(int a,int b,int c,int d) {
    int x=2*c-a;
    int y=2*d-b;
    if (x<0||y<0||num[x][y]==-1) return true;
    if (num[x][y]==num[a][b]) return true;
    return false;
}

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&kase);
    for (int i=1;i<=kase;i++) {
        scanf("%d",&k);
        memset(num,-1,sizeof(num));
        for (int j=0;j<k;j++) {
            for (int l=k-j-1;l<=k-j-1+2*j;l+=2) scanf("%d",&num[j][l]);
        }
        for (int j=k;j<2*k-1;j++) {
            for (int l=j+1-k;l<j-k+1+2*(2*k-j-1);l+=2) scanf("%d",&num[j][l]);
        }
        res=200;
        for (int j=0;j<2*k-1;j++)
        {
            for (int l=0;l<2*k-1;l++) {
                int tmp=abs(j-k+1)+abs(l-k+1)+k;
                if (tmp>=res) continue;
                able=true;
                for (int a=0;a<k;a++) {
                    if (!able) break;
                    for (int b=k-a-1;b<=k-a-1+2*a;b+=2) {
                        if (!pd(a,b,j,l)) {
                            able=false;
                            break;
                        }
                    }
                }
                for (int a=k;a<2*k-1;a++) {
                    if (!able) break;
                    for (int b=a+1-k;b<a-k+1+2*(2*k-a-1);b+=2) {
                        if (!pd(a,b,j,l)) {
                            able=false;
                            break;
                        }
                    }
                }
                if (able) res=tmp;
            }
        }
        printf("Case #%d: %d\n",i,res*res-k*k);
    }
    return 0;
}
