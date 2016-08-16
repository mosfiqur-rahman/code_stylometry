#include <stdio.h>
#include <string.h>

bool a[120][120];
bool b[120][120];
int kase,n,a1,b1,c,d,mx,my,kk,res;
bool has;

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        ++kk;
        scanf("%d",&n);mx=my=0;
        memset(a,false,sizeof(false));
        while (n--) {
            scanf("%d%d%d%d",&a1,&b1,&c,&d);
            for (int i=b1;i<=d;i++)
                for (int j=a1;j<=c;j++) a[i][j]=true;
            if (d>mx) mx=d;
            if (c>my) my=c;
        }
        res=0;
        do {
            has=false;
            ++res;
            /*for (int i=1;i<=mx;i++) {
                for (int j=1;j<=my;j++) {
                    if (a[i][j]) printf("1");
                    else printf("0");
                }
                printf("\n");
            }
            printf("\n");*/
            for (int i=1;i<=mx;i++) {
                for (int j=1;j<=my;j++) {
                    b[i][j]=false;
                    if (a[i][j]&&(a[i-1][j]||a[i][j-1])) b[i][j]=true;
                    if (a[i-1][j]&&a[i][j-1]) b[i][j]=true;
                    if (b[i][j]) has=true;
                }
            }
            memcpy(a,b,sizeof(b));
        }while(has);
        printf("Case #%d: %d\n",kk,res);
    }
    return 0;
}
