#include <stdio.h>
#include <string.h>

int kk;
int kase;
char rel[120][120];
double a[120],b[120],c[120];
int w[120],l[120],p[120];
int n;

int main() {
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        scanf("%d",&n);
        for (int i=0;i<n;i++) {
            scanf("%s",rel[i]);
            w[i]=l[i]=p[i]=0;
            for (int j=0;j<n;j++) {
                if (rel[i][j]!='.') p[i]++;
                if (rel[i][j]=='1') w[i]++;
                if (rel[i][j]=='0') l[i]++;
            }
            a[i]=1.0*w[i]/p[i];
            //printf("%.7f\n",a[i]);
        }
        for (int i=0;i<n;i++) {
            b[i]=0;
            int m=0;
            for (int j=0;j<n;j++) {
                if (j==i) continue;
                if (rel[j][i]=='.') continue;
                m++;
                if (rel[j][i]=='1') b[i]+=1.0*(w[j]-1)/(p[j]-1);
                if (rel[j][i]=='0') b[i]+=1.0*w[j]/(p[j]-1);
            }
            b[i]/=m;
            //printf("%.7f\n",b[i]);
        }
        printf("Case #%d:\n",++kk);
        for (int i=0;i<n;i++) {
            int m=0;
            c[i]=0;
            for (int j=0;j<n;j++) {
                if (rel[i][j]=='.') continue;
                m++;
                c[i]+=b[j];
            }
            c[i]/=m;
            printf("%.11f\n",0.25*a[i]+0.5*b[i]+0.25*c[i]);
        }
    }
    return 0;
}
