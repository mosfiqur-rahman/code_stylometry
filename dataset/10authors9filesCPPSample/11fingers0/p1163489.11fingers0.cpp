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

struct seg
{
	int s, v;
	bool operator<(const seg & next) const {
		return v < next.v;
	}
};

int main(int argc, char** argv)
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

    int T;
	scanf("%d", &T);
	for(int ti = 1; ti<=T; ++ti) {
		int X, S, R,  N;
		double t;
		scanf("%d%d%d%lf%d", &X, &S, &R, &t, &N);
		vector <seg> vs;
		seg cur;
		int len = X;
		for(int ni=0; ni<N; ++ni) {
			int a,b;
			scanf("%d%d", &a, &b);
			cur.s = b-a;
			scanf("%d", &cur.v);
			cur.v += S;
			vs.PB(cur);
			len -= cur.s;
		}
		cur.s = len;
		cur.v = S;
		vs.PB(cur);
		sort(ALL(vs));
		double ans = 0;
		for(int i=0; i<vs.size(); ++i) {
			cur = vs[i];
			double time = min(1.0 * t, 1.0 * cur.s / (cur.v + R - S));
			ans += time;
			t -= time;
			if(!t) {
				ans += 1.0 * (cur.s - (cur.v + R - S) * time) / cur.v;
			}
		}
		printf("Case #%d: %.9lf\n", ti, ans);
	}
    return (EXIT_SUCCESS);
}

