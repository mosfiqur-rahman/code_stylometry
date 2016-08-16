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
    freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int ti=1; ti<=T; ++ti) {
		int n;
		scanf("%d", &n);
		char color[105][5] = {0};
		int arr[105] = {0};
		for(int i=0; i<n; ++i) {
			scanf("%s%d", color[i], &arr[i]);
		}
		int ai = 1, bi=1, act=0, bct=0;
		int ans=0;
		for(int i=0; i<n; ++i) {
			if(!strcmp(color[i],"O")) {
				int dist = abs(arr[i] - ai);
				int tmp = min(dist, act);
				ans += dist - tmp + 1;
				bct += dist - tmp + 1;
				act = 0;
				ai = arr[i];
			}
			else if(!strcmp(color[i], "B")) {
				int dist = abs(arr[i] - bi);
				int tmp = min(dist, bct);
				ans += dist - tmp + 1;
				bct = 0;
				act += dist - tmp + 1;
				bi = arr[i];
			}
		}
		printf("Case #%d: %d\n", ti, ans);
	}

    return (EXIT_SUCCESS);
}

