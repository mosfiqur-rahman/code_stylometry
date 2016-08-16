#include <iostream>
#include <queue>
using namespace std;
queue<int>a,b;
queue<int> q;
int pa,pb,nexta,nextb;
char ch;
int main()
{
	int i,j,k,co=1,t,n,p,d;
	freopen("A-small-attempt0.in","r",stdin);
	freopen("outa.text","w",stdout);
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d",&n);
		getchar();
		pa=pb=1;
		while (!a.empty())
			a.pop();
		while (!b.empty())
			b.pop();
		while (!q.empty())
			q.pop();
		for (i=0;i<n;i++)
		{
			scanf("%c",&ch);
			scanf("%d",&p);
			getchar();
			if (ch=='O')
			{
				a.push(p);
				q.push(0);
			}
			else
			{
				b.push(p);
				q.push(1);
			}
		}
		d=0;
		nexta=nextb=-1;
		if (!a.empty())
			nexta=a.front();
		if (!b.empty())
			nextb=b.front();
		while(!q.empty())
		{
			d++;
			if (q.front()==0)
			{
				if (nextb!=-1)
				{
					if (pb!=nextb)
						pb+=(pb<nextb?1:-1);
				}
				if (nexta!=pa)
					pa+=(pa<nexta?1:-1);
				else
				{
					a.pop();
					if (!a.empty())
						nexta=a.front();
					else
						nexta=-1;
					q.pop();
				}
			}
			else
			{
				if (nexta!=-1)
				{
					if (pa!=nexta)
						pa+=(pa<nexta?1:-1);
				}
				if (nextb!=pb)
					pb+=(pb<nextb?1:-1);
				else
				{
					b.pop();
					if (!b.empty())
						nextb=b.front();
					else
						nextb=-1;
					q.pop();
				}
			}
		}
		printf("Case #%d: %d\n",co++,d);
	}
	return 0;
}