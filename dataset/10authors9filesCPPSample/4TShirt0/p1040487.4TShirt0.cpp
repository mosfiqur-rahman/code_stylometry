#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int t;
	cin >> t;
	for (int cases=1;cases<=t;cases++)
	{
		int n,pd,pg;
		cin >> n >> pd >>pg;
		int d=-1,wd=0;
		int g=-1,wg=0;
		bool find = false;
		bool flag = false;
		for (int i=1;i<=n;i++)
		{
			int j;
			flag = false;
			bool tmpflag = false;
			for (j=0;j<=i;j++)
			{
				if (j*100/i==pd && j*100%i==0)
				{
					tmpflag = true;
					break;
				}
			}
			if (tmpflag==false)
			{
				continue;
			}
			d = i;wd=j;
			for (int k=1;k<=9900;k++)
			{
				if ((d*k*pg)%(100) == 0 && (d*k*pg)/(100)>=wd)
				{
					if (((d*k*pg)/(100))-wd <= (k-1)*d)
					{
						//cout << wd <<" "<< d<<endl;
						//cout << (d*k*pg)/(100)<<" " << k*d << endl;
						flag = true;break;
					}
				}
			}
			if (flag == true)
			{
				break;
			}
		}
		//cout << "Case #1: Possible"
		if (flag)
		{
			printf("Case #%d: Possible\n",cases);
		}
		else printf("Case #%d: Broken\n",cases);
	}
	return 0;
}