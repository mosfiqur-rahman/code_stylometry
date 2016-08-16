#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int C;
	scanf("%d", &C);
	for(int i=1; i<=C; i++)
	{
		vector <int> t;
		int N;
		scanf("%d", &N);
		for(int j=0; j<N; j++)
		{
			int ti, k=0;
			scanf("%d", &ti);
			for(; k<t.size(); k++)
				if(t[k]==ti)
					break;
			if(k==t.size())
				t.push_back(ti);
		}
		sort(t.begin(), t.end());
		int dif=-1;
		for(int j=0; j<t.size(); j++)
			for(int k=j+1; k<t.size(); k++)
			{
				if(dif==-1)
					dif=t[k]-t[j];
				else
					dif=min(t[k]-t[j], dif);
			}
		printf("Case #%d: %d\n", i, (int)(dif*ceil(1.*t[0]/dif)-t[0]));
	}
	return 0;
}