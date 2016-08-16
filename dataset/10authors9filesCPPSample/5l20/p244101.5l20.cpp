#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAXN=18;
int g[18][MAXN];
int a[18][25],n,k,col;
int check(int i,int j)
{
           for(int kk=0;kk<k-1;++kk)
           {
                if(a[i][kk]<=a[j][kk]&&a[i][kk+1]>=a[j][kk+1])return 1;
                if(a[j][kk]<=a[i][kk]&&a[j][kk+1]>=a[i][kk+1])return 1;
           }
           return 0;
}
void clique(int n, int* u, int mat[][MAXN], int size, int& max, int& bb, int* res, int* rr, int* c) {
	int i, j, vn, v[MAXN];
	if (n) {
		if (size + c[u[0]] <= max) return;
		for (i = 0; i < n + size - max && i < n; ++ i) {
			for (j = i + 1, vn = 0; j < n; ++ j)
				if (mat[u[i]][u[j]])
					v[vn ++] = u[j];
			rr[size] = u[i];
			clique(vn, v, mat, size + 1, max, bb, res, rr, c);
			if (bb) return;
		}
	} else if (size > max) {
		max = size;
		for (i = 0; i < size; ++ i)
			res[i] = rr[i];
		bb = 1;
	}
}

int maxclique(int n, int mat[][MAXN], int *ret) {
	int max = 0, bb, c[MAXN], i, j;
	int vn, v[MAXN], rr[MAXN];
	for (c[i = n - 1] = 0; i >= 0; -- i) {
		for (vn = 0, j = i + 1; j < n; ++ j)
			if (mat[i][j])
				v[vn ++] = j;
		bb = 0;
		rr[0] = i;
		clique(vn, v, mat, 1, max, bb, ret, rr, c);
		c[i] = max;
	}
	return max;
}
int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int t,i,j,p=0;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d%d",&n,&k);
                memset(g,0,sizeof(g));
                for(i=0;i<n;++i)
                    for(j=0;j<k;++j)
                        scanf("%d",&a[i][j]);
                for(i=0;i<n;++i)
                    for(j=i+1;j<n;++j)
                             g[i][j]=g[j][i]=check(i,j);
               // for(i=0;i<n;++i,printf("\n"))
                //    for(j=0;j<n;++j) printf("%d ",g[i][j]);
                int ret[MAXN];
                int ans=maxclique(n,g,ret);
                printf("Case #%d: %d\n",++p,ans);

        }
        return 0;
}
