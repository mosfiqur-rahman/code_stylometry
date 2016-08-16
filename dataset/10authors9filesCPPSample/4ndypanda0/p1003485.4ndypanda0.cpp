#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int T, L, N, C;
long long t;
vector <int> dist, distance_left;

int dfs(int pos=0, int last_time=0, int boosters=0)
{
	if(pos==N)
		return 0;
	if(boosters==L)
		return distance_left[pos]*2;
	int min_time = distance_left[pos]*2;
	int dist_required = max(0LL,(t-last_time)/2);
	if(last_time+dist[pos]*2 >= t) //There is room left to use a booster in current position.
		min_time = dist[pos]-dist_required+dist_required*2+dfs(pos+1, dist[pos]-dist_required, boosters+1);
	min_time = min(min_time, dist[pos]*2+dfs(pos+1, last_time+dist[pos]*2, boosters)); //Do not use a booster this position.
	return min_time;
}

int min_time()
{
	distance_left.clear();
	distance_left = vector <int>(N);
	for(int i=N-1; i>=0; i--)
		distance_left[i]=dist[i] + (i<N-1 ? distance_left[i+1] : 0);
	return dfs();
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int test=1; test<=T; test++)
	{
		cin >> L >> t >> N >> C;
		dist.clear();
		for(int i=0; i<C; i++)
		{
			int a;
			cin >> a;
			dist.push_back(a);
		}	
		int cur=0;
		while(dist.size()<N)
		{
			dist.push_back(dist[cur]);
			cur = (cur+1)%C;
		}
		printf("Case #%d: %d\n", test, min_time());
	}
	return 0;
}