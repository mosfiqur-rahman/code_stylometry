//#include <cstdlib>
//#include <cctype>
//#include <cstring>
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//#include <vector>
//#include <string>
//#include <iostream>
//#include <sstream>
//#include <map>
//#include <set>
//#include <queue>
//#include <stack>
//#include <fstream>
//#include <numeric>
//#include <iomanip>
//#include <bitset>
//#include <list>
//#include <stdexcept>
//#include <functional>
//#include <utility>
//#include <ctime>
//using namespace std;
//
//int T, CT=1, L, P, C;
//int main() {
//	//freopen("B-small-attempt0.in","r",stdin);
//    //freopen("B-small-attempt0.out","w",stdout);
//	//scanf("%d", &T);
//	cin>>T;
//	while(T--) {
//		scanf("%d %d %d", &L, &P, &C);
//
//		int ans = 0;
//		int TT = C;
//		while(L * C < P) {
//			L *= TT;
//			TT *= C;
//			++ans;
//		}
//		printf("Case #%d: %d\n", CT++, ans);
//
//	}
//	return 0;
//}


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

struct node
{
	char ch;
	int pos;
};
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
	int t;
	scanf("%d",&t);
	for(int cases=1;cases<=t;cases++)
	{
		int n;
		scanf("%d",&n);
		queue<node> q;
		queue<int> ro,rb;
		for(int i=0;i<n;i++)
		{
			node tmp;
			//scanf("%c %d",&tmp.ch,&tmp.pos);
			cin >> tmp.ch >> tmp.pos;
			q.push(tmp);
			if(tmp.ch=='O')
				ro.push(tmp.pos);
			else rb.push(tmp.pos);
		}
		int po=1,pb=1;
		int res = 0;
		while(!q.empty())
		{
			if(q.front().ch=='O')
			{
				if(rb.empty()==false)
				{
					if(pb<rb.front())
						pb++;
					else if(pb>rb.front())
						pb--;
				}
				if(po==q.front().pos)
				{
					q.pop();
					ro.pop();
				}
				else if(po < q.front().pos)
					po++;
				else po--;
				res ++;
			}
			else
			{
				if(ro.empty()==false)
				{
					if(po<ro.front())
						po++;
					else if(po>ro.front())
						po--;
				}
				if(pb==q.front().pos)
				{
					q.pop();
					rb.pop();
				}
				else if(pb < q.front().pos)
					pb++;
				else pb--;
				res ++;
			}
		}
		printf("Case #%d: %d\n",cases,res);
	}
	return 0;
}
