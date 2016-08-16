#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int kase;
int n;
int a[110],b[110],c[110];
int na,nb;
int pa,pb,tt,ta,tb,tot,kk;
char tp[20];

int sgn(int a) { return a>0?1:-1; }

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        na=nb=0;
        pa=pb=1;
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%s%d",tp,&tt);
            if (tp[0]=='O') a[na++]=tt,c[i]=0;
            else b[nb++]=tt,c[i]=1;
        }
        ta=tb=tot=0;
        for (int i=0;i<n;i++) {
            if (c[i]==0) {
                tot+=abs(pa-a[ta])+1;
                if (abs(pa-a[ta])+1>=abs(pb-b[tb])) pb=b[tb];
                else pb-=sgn(pb-b[tb])*(abs(pa-a[ta])+1);
                pa=a[ta];
                ta++;
            }
            else {
                tot+=abs(pb-b[tb])+1;
                if (abs(pb-b[tb])+1>=abs(pa-a[ta])) pa=a[ta];
                else pa-=sgn(pa-a[ta])*(abs(pb-b[tb])+1);
                pb=b[tb];
                tb++;
            }
        }
        printf("Case #%d: %d\n",++kk,tot);
    }
    return 0;
}
