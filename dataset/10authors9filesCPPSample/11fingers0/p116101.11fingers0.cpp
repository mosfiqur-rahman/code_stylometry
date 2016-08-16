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

int Match(string cur, string dic, int p1, int p2)
{
	if(p2==dic.size()) return 1;
    if(cur[p1] != '(')
    {
        if(dic[p2] == cur[p1]) return Match(cur, dic, p1 + 1, p2 + 1);
        else return 0;
    }
    else
    {
        bool isFind = 0;
        while(cur[++p1] != ')')
        {
            if(cur[p1] == dic[p2]) isFind = 1;
        }
        if(isFind) return Match(cur, dic, p1 + 1, p2 + 1);
        else return 0;
    }
}

int main(int argc, char** argv)
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small.out","w",stdout);
    int l, d, n;
    scanf("%d%d%d", &l, &d, &n);
    vector < string > dic(d);
    for(int i = 0; i < d; i++)
    {
        cin >> dic[i];
    }

    for(int i = 0; i < n; i++)
    {
	    int res = 0;
        string cur;
        cin >> cur;
        for(int j = 0; j < d; j++)
        {
            res += Match(cur, dic[j], 0, 0);
        }
		cout<<"Case #"<<i+1<<": "<<res<<endl;
    }
    return (EXIT_SUCCESS);
}

