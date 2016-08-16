#include <cstdlib>
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
#include <list>
#include <bitset>
#include <utility>

using namespace std;

#define dbg(x) cerr<<#x<<" : "<<x<<endl
#define inf (1<<30)
#define PB push_back
#define MP make_pair
#define mset(x,a) memset(x,(a),sizeof(x))
typedef long long LL;
#define twoL(X) (((LL)(1))<<(X))
const double PI = acos(-1.0);
const double eps = 1e-8;

template <class T> T sqr(T x)
{
    return x*x;
}

int gcd(int a, int b)
{
    return (b == 0) ? a : gcd(b, a % b);
}

#define FOREACH(it, a) for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
#define ALL(x) (x).begin(), (x).end()

int main(int argc, char** argv)
{
	freopen("A-small-attempt4.in", "r", stdin);
	freopen("A-small-attempt4.out", "w", stdout);
    int t;
	scanf("%d", &t);
	for(int ti=1; ti<=t; ++ti) {
		LL n, pd, pg;
		cin>>n>>pd>>pg;
		bool fd = 0;

		if(n<=100 && pd != 0) {
			for(int i=1; i<=n; ++i) {
				for(int j=i; j<=n; ++j) {
					if(i * 100 % j == 0 && i * 100 / j == pd) {
						fd=1;
						goto end;
					}
				}
			}
		}

end:	printf("Case #%d: ", ti);
		if(pd==100 && pg == 100 || pg != 100 && (pd == 0 || (n >= 100 || fd) && pg > 0)) puts("Possible");
		else puts("Broken");
	}
    return (EXIT_SUCCESS);
}

