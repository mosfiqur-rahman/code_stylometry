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
const int maxs = 10006;

long long dis[maxs];
long long sum[maxs];
long long a[maxs] ;
long long L,t,N,C;

void getAC1()
{
	long long res = -1;
	for (int i=1;i<=N;i++)
	{
			long long cost = 0;
			cost += sum[i-1] * 2;
			if (t<=2*sum[i])
			{
				if (t>=cost)
				{
					long long tmpleft = dis[i] - (t-cost)/2;
					cost = t + tmpleft;
				}
				else cost += dis[i];
			}
			else cost += 2*dis[i];
			cost += (sum[N] - sum[i])*2;
			if (res==-1 || cost<res)
				res = cost;
	}
	cout << res << endl;
}

void getAC2()
{
	long long res = -1;
	for (int i=1;i<=N;i++)
	{
		for (int j=i+1;j<=N;j++)
		{
			long long cost = 0;
			cost += sum[i-1] * 2;
			if (t<=2*sum[i])
			{
				if (t>=cost)
				{
					long long tmpleft = dis[i] - (t-cost)/2;
					cost += (t-cost) + tmpleft;
				}
				else cost += dis[i];
			}
			else cost += 2*dis[i];

			cost += (sum[j-1]-sum[i])*2;
			if (t<=cost)
			{
				cost += dis[j];
			}
			else
			{
				if (t <= cost+2*dis[j])
				{
					long long tmpleft = dis[j] - (t-cost)/2;
					cost += (t-cost) + tmpleft;
				}
				else
					cost += 2*dis[j];
			}
			cost += (sum[N]-sum[j])*2;
			if (res==-1 || cost<res)
				res = cost;
		}
	}
	cout << res << endl;
}

void getAC0()
{
	cout << 2*sum[N]  << endl;
}
void getAC()
{
	if (L == 2)
	{
		getAC2();
	}
	else if (L == 1)
	{
		getAC1();
	}
	else getAC0();
}
int main()
{
	freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	int testcases;
	cin >> testcases;
	for (int caseid=1;caseid<=testcases;caseid++)
	{	
		cin >> L >> t >> N >> C;
		for (int i=0;i<C;i++)
		{
			cin >> a[i];
		}
		int cnt = 0;
		dis[0] = 0;sum[0] = 0;
		for (int i=1;i<=N;i++)
		{
			dis[i] = a[cnt%C];
			sum[i] = dis[i];
			cnt ++;
		}
		for (int i=2;i<=N;i++)
		{
			sum[i] = sum[i-1] + dis[i];
		}
		printf("Case #%d: ",caseid);
		getAC();
	}
	return 0;
}