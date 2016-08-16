#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T, N;
int button[101];
char color[101];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf(" %c %d", &color[i], &button[i]);
		int time=0, timeO=0, timeB=0, posO=1, posB=1;
		for(int i=0; i<N; i++)
			if(color[i]=='O')
			{
				time+=max(0, abs(button[i]-posO)-(time-timeO))+1;
				timeO=time;
				posO=button[i];
			}
			else
			{
				time+=max(0, abs(button[i]-posB)-(time-timeB))+1;
				timeB=time;
				posB=button[i];
			}
		printf("Case #%d: %d\n", t, time);
	}
	return 0;
}