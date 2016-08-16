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
    freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int ti=0; ti<t; ++ti) {
		int n,k;
		scanf("%d%d", &n, &k);
		printf("Case #%d: ", ti+1);
		if((k+1)%(1<<n) == 0) printf("ON\n"); else printf("OFF\n");
	}
    return (EXIT_SUCCESS);
}

