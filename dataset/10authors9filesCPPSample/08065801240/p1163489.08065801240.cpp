#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
	double v,s;
};
vector <node> q;
bool cmp(node a,node b)
{
	return a.v<b.v;
}
int main()
{
	node a;
	freopen("A-small-attempt1.in","r",stdin);
	freopen("outa.txt","w",stdout);
	int i,j,k,n,tt,co=1;
	double x,y,v,s,l,v1,v2,end,ans,t;
	scanf("%d",&tt);
	while (tt--)
	{
		scanf("%lf%lf%lf%lf%d",&l,&v1,&v2,&t,&n);
	//	cout<<t<<endl;
		q.clear();
		end=0;
		for (i=0;i<n;i++)
		{
			scanf("%lf%lf%lf",&x,&y,&v);
			if (x>end)
			{
				a.v=0;
				a.s=x-end;
				q.push_back(a);
			}
			a.s=y-x;
			a.v=v;
			q.push_back(a);
			end=y;
		}
		if (end<l)
		{
			a.s=l-end;
			a.v=0;
			q.push_back(a);
		}
		sort(q.begin(),q.end(),cmp);
		n=q.size();
		ans=0;
	//	for (i=0;i<n;i++)
	//		cout<<q[i].s<<' '<<q[i].v<<endl;
		i=0;
	//	cout<<t<<endl;
		while (t>0)
		{
	//		cout<<ans<<endl;
			if (i==n)
				break;
			if (q[i].s/(v2+q[i].v)<=t)
			{
				ans+=q[i].s/(v2+q[i].v);
				t-=q[i].s/(v2+q[i].v);
				i++;
			}
			else
			{
				ans+=t;
				q[i].s-=(v2+q[i].v)*t;
				ans+=q[i].s/(v1+q[i].v);
				t=0;
				i++;
			}
		}
		while (i<n)
		{
			ans+=q[i].s/(v1+q[i].v);
			i++;
		}
		printf("Case #%d: %.6lf\n",co++,ans);
	}
	return 0;
}