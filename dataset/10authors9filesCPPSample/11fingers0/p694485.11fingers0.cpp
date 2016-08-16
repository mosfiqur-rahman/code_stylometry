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

template <class T> T sqr(T x) {
    return x*x;
}

int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

#define FOREACH(it, a) for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
#define ALL(x) (x).begin(), (x).end()

bool check(int k, int cnt[]) {
	int one = 1;
	if(k%2==0) one--;
    int two = 2 * k;
    if (k % 2 == 1) two-=2;
    int four = k * k - two - one;
    int res = 0;
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] / 4 > 0) {
            int tmp = (cnt[i] / 4 * 4);
            cnt[i] -= tmp;
            if (four) {
                int tot = min(four, tmp);
                four -= tot;
                tmp -= tot;
            }
            if (two) {
                int tot = min(two, tmp);
                two -= tot;
                tmp -= tot;
            }
            if (tmp) return 0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] == 3) {
            ++res;
            if (four) {
                four -= 4;
                cnt[i] -= 3;
            }
            else if (two) {
                two -= 2;
                cnt[i] -= 2;
            }
            if (cnt[i]==3) return 0;
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (cnt[i] == 1) {
			if (one) {
				one--;
				cnt[i]-=1;
			}
            if(!cnt[i]) continue;
			++res;		
            if (two) {
                two -= 2;
                cnt[i] -= 1;
            }
            if(!cnt[i]) continue;
			res+=2;
            if (four) {
                four -= 4;
                cnt[i] -= 1;
            }
            if (cnt[i]) return 0;
        } else if (cnt[i] == 2) {
            if (two) {
                two -= 2;
                cnt[i] -= 2;
            }
            if(!cnt[i]) continue;
			res+=2;
            if (four) {
                four -= 4;
                cnt[i] -= 2;
            }
            if (cnt[i]) return 0;
        }
    }
	return 1;
}

int main(int argc, char** argv) {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for (int ti = 0; ti < t; ++ti) {
        int n;
        scanf("%d", &n);
        int cnt[10] = {0};
        for (int i = 0; i < n * n; ++i) {
			int d;
			scanf("%d", &d);
            ++cnt[d];
        }
        int cur = n;
        for (; !check(cur, cnt); ++cur);
        printf("Case #%d: %d\n", ti+1, cur * cur - n * n);
    }
    return (EXIT_SUCCESS);
}

