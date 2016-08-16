#include <cstdlib>  
#include <cctype>  
#include <cstring>  
#include <cstdio>  
#include <cmath>  
#include <algorithm>  
#include <vector>  
#include <string>  
#include <iostream>  
#include <sstream>  
#include <map>  
#include <set>  
#include <queue>  
#include <stack>  
#include <fstream>  
#include <numeric>  
#include <iomanip>  
#include <bitset>  
#include <list>  
#include <stdexcept>  
#include <functional>  
#include <utility>  
#include <ctime>  
using namespace std;  

#define PB push_back  
#define MP make_pair  

#define REP(i,n) for(i=0;i<(n);++i)  
#define FOR(i,l,h) for(i=(l);i<=(h);++i)  
#define FORD(i,h,l) for(i=(h);i>=(l);--i)  
#define CLOCK cout << "Clock " << (double)clock()/CLOCKS_PER_SEC << endl
const int maxs = 100003;
struct node
{
	long long dis,len;
	long long maxdis;
	long long maxlen;
}vines[maxs];
long long n,love;

int main()
{
	freopen("A-small-attempt0.in","r",stdin);freopen("A-small-attempt0.out","w",stdout);
	//freopen("B-large.in","r",stdin);freopen("B-large.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		scanf("%lld",&n);
		for (int i=0;i<n;i++) {scanf("%lld %lld",&vines[i].dis,&vines[i].len);vines[i].maxdis=0LL;vines[i].maxlen=0LL;}
		scanf("%lld",&love);
		bool flag = false;
		vines[0].maxdis = 2*vines[0].dis;
		vines[0].maxlen = vines[0].dis;
		for (int i=0;!flag && i<n;i++)
		{
			if (vines[i].maxdis >= love) {flag = true;break;}
			for (int j=i+1;j<n;j++)
			{
				if(vines[j].dis-vines[i].dis <= vines[i].maxlen)
				{
					long long tmp = std::min(vines[j].dis-vines[i].dis,vines[j].len);
					vines[j].maxlen = std::max(tmp,vines[j].maxlen);
					if (vines[j].dis+vines[j].maxlen >= love)
					{
						flag = true;break;
					}
					vines[j].maxdis = vines[j].dis + vines[j].maxlen;
				}
				else break;
			}
		}
		printf("Case #%d: ",cases);
		if (!flag) cout << "NO"<<endl;
		else cout << "YES" << endl;
	}
	return 0;
}