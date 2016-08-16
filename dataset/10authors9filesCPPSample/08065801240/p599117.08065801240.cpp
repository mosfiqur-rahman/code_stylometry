#include <iostream>
using namespace std;
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,i,j,k,s,count=1;
	int a[1005],b[1005];
	scanf("%d",&t);
	while (t--)
	{
		s=0;
		scanf("%d",&n);
		for (i=1;i<=n;i++)
			scanf("%d%d",&a[i],&b[i]);
		for (i=1;i<=n-1;i++)
			for (j=i+1;j<=n;j++)
				if ((a[i]-a[j])*(b[i]-b[j])<0)
					s++;
		printf("Case #%d: %d\n",count++,s);
	}
	return 0;
}