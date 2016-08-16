#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, Pd, Pg;
	long long N;
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N >> Pd >> Pg;
		bool possible = true;
		if(Pg == 100 && Pd != 100 || Pg == 0 && Pd!= 0)
			possible = false;
		if(Pd!=0)
		{
			int cnt2=0, cnt5=0;
			while(!(Pd%2))
				cnt2++, Pd/=2;
			while(!(Pd%5))
				cnt5++, Pd/=5;
			if((long long)pow(2.,max(0, 2-cnt2))*pow(5., max(0, 2-cnt5))>N)
				possible = false;
		}
		printf("Case #%d: %s\n", t, possible ? "Possible" : "Broken");
	}
	return 0;
}