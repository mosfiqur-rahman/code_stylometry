#include <iostream>
using namespace std;
int gcd (int x,int y)
{
	if (y==0)
		return x;
	return gcd(y,x%y);
}
int main()
{
	int i,j,k,t,p1,p2;
	__int64 n,m;
	int co=1;	freopen("A-small-attempt0.in","r",stdin);
	freopen("outa.txt","w",stdout);
	scanf("%d",&t);

	while (t--)
	{
		scanf("%I64d%d%d",&n,&p1,&p2);
		if (p2==0)
		{
			if (p1==0)
				printf("Case #%d: Possible\n",co++);
			else
				printf("Case #%d: Broken\n",co++);
			continue;
		}
		if (p2==100)
		{
			if (p1==100)
				printf("Case #%d: Possible\n",co++);
			else
				printf("Case #%d: Broken\n",co++);
			continue;
		}
		m=__int64(100/gcd(100,p1));
		if (m<=n)
		{
			printf("Case #%d: Possible\n",co++);

		}
					else
				printf("Case #%d: Broken\n",co++);
	}
	return 0;
}