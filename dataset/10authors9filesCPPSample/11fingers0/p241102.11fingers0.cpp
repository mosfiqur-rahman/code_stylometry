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
#define mset(x,a) memset(x,(a),sizeof(x))
typedef long long LL;
#define twoL(X) (((LL)(1))<<(X))
const double PI = acos(-1.0);
const double eps = 1e-8;

template <class T> T sqr(T x)
{
    return x*x;
}

template <class T> T gcd(T a, T b)
{
    if(a < 0) return (gcd(-a, b));
    if(b < 0) return (gcd(a, -b));
    return (b == 0) ? a : gcd(b, a % b);
}

#define FOREACH(it, a) for(typeof((a).begin()) it = (a).begin(); it!=(a).end(); ++it)
#define ALL(x) (x).begin(), (x).end()
int n;

int Val(const string &str)
{
    for(int i = str.size() - 1; i >= 0; i--)
    {
        if(str[i] == '1') return i;
    }
    return -1;
}

int ct(string str[], int p)
{
    int ret = 0;
    for(int i = p; i < n; i++)
    {
        if(Val(str[i]) <= p)
        {
            while(i > p)
            {
                swap(str[i], str[i - 1]);
                i--;
                ret++;
            }
			return ret;
        }
    }
}

int main(int argc, char** argv)
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    int t;
    cin >> t;
    for(int ti = 0; ti < t; ti++)
    {

        cin >> n;
        string str[45];
        vector < string > tmp;
        for(int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        int res = 0;
        for(int i = 0; i < n; i++)
        {
            res += ct(str, i);
        }
        cout << "Case #" << ti + 1 << ": " << res << endl;
    }
    return (EXIT_SUCCESS);
}

