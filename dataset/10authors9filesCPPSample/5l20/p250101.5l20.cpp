#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
double dis(double x,double y,double x1,double y1)
{
        return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int main()
{
        freopen("in.txt","r",stdin);
         freopen("out.txt","w",stdout);
        int t,i,j,p=0,n;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&n);
                double x,y,r,r1,ans;
                if(n==1)
                {
                    scanf("%lf%lf%lf",&x,&y,&r);
                    ans=r;
                }
                else if(n==2)
                {
                    double r1;
                    scanf("%lf%lf%lf",&x,&y,&r);
                    scanf("%lf%lf%lf",&x,&y,&r1);
                    ans=max(r1,r);
                }
                else
                {
                   double x1,x2,x3,y1,y2,y3,r1,r2,r3;
                   scanf("%lf%lf%lf",&x1,&y1,&r1);
                   scanf("%lf%lf%lf",&x2,&y2,&r2);
                   scanf("%lf%lf%lf",&x3,&y3,&r3);
                   ans=max((dis(x1,y1,x2,y2)+r1+r2)/2,r3);
                   ans=min(ans,max((dis(x2,y2,x3,y3)+r3+r2)/2,r1));
                   ans=min(ans,max((dis(x1,y1,x3,y3)+r3+r1)/2,r2));
                }
               printf("Case #%d: %.6lf\n",++p,ans);

        }
        return 0;
}
