#include <iostream>
#include <algorithm>
using namespace std;
int a[10],b[10],c[10],n;
bool ok()
{
        for(int i=0;i<n;++i)
        {

                if(a[c[i]]&b[i])return false;
        }
        return true;
}
int re()
{
        int ans=0;
        for(int i=0;i<n;++i)
        {
                for(int j=i+1;j<n;++j)
                {
                        if(c[i]>c[j])++ans;
                }
        }
        return ans;
}
int main()
{
        freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);
        int t,i,j,p=0;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                int tmp;
                for(i=0;i<n;++i)
                {
                    for(a[i]=j=0;j<n;++j)
                    {
                            scanf("%1d",&tmp);
                            a[i]<<=1;
                            a[i]+=tmp;
                    }

                    b[i]=(1<<(n-i-1))-1;
                    c[i]=i;
                   // printf("%d %d\n",a[i],b[i]);
               }
               int ans=1000000;
               do
               {
                    if(ok())
                    {
                            tmp=re();
                            if(tmp<ans)ans=tmp;
                    }
               }while(next_permutation(c,c+n));
               printf("Case #%d: %d\n",++p,ans);

        }
        return 0;
}
