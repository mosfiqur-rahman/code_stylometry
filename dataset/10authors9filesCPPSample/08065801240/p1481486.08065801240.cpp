#include <iostream>
#include <string.h>
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
int n;
int l[10005],d[10005];
int dis[10005];
int D;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,t;
	int ok,co=1;
	scanf("%d",&t);
	while (t--)
	{
		ok=0;
		scanf("%d",&n);
		for (i=0;i<n;i++)
		{
			scanf("%d%d",&d[i],&l[i]);
		}
		scanf("%d",&D);
		memset(dis,0,sizeof(dis));
		dis[0]=d[0];
		for (i=0;i<n;i++)
		{
			for (j=i+1;j<n;j++)
			{
				if (dis[i]+d[i]>=d[j])
				{
					if (l[j]<d[j]-d[i])
						dis[j]=max(dis[j],l[j]);
					else
						dis[j]=max(dis[j],d[j]-d[i]);
				}
			}
		}
		for (i=0;i<n;i++)
			if (d[i]+dis[i]>=D)
				ok=1;
		if (ok==1)
			printf("Case #%d: YES\n",co++);
		else
			printf("Case #%d: NO\n",co++);
	}
	return 0;
}
