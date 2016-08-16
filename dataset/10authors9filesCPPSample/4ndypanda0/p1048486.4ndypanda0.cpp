#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int T, N;
int schedule[101][101];
double WP[101], OWP[101], OOWP[101];

void calculate_WP()
{
	for(int i=0; i<N; i++)
	{
		int won=0, total=0;
		for(int j=0; j<N; j++)
			total+=schedule[i][j]!=-1, won+=schedule[i][j]==1;
		WP[i]=1.*won/total;
	}
}

void calculate_OWP()
{
	for(int i=0; i<N; i++)
	{
		int total=0;
		double total_percent=0;
		for(int j=0; j<N; j++)
			if(schedule[i][j]!=-1)
			{
				total++;
				int opp_total=0, opp_win=0;
				for(int k=0; k<N; k++)
					if(k!=i && schedule[j][k]!=-1)
						opp_total++, opp_win+=schedule[j][k]==1;
				total_percent+=1.*opp_win/opp_total;
			}
		OWP[i] = total_percent/total;
	}
}

void calculate_OOWP()
{
	for(int i=0; i<N; i++)
	{
		int total=0;
		double total_OWP=0;
		for(int j=0; j<N; j++)
			if(schedule[i][j]!=-1)
				total++, total_OWP+=OWP[j];
		OOWP[i] = total_OWP/total;
	}
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> N;
		for(int i=0; i<N; i++)
		{
			string s;
			cin >> s;
			for(int j=0; j<s.length(); j++)
				if(s[j]=='.')
					schedule[i][j]=-1;
				else
					schedule[i][j]=s[j]-'0';
		}
		calculate_WP();
		calculate_OWP();
		calculate_OOWP();
		printf("Case #%d:\n", t);
		for(int i=0; i<N; i++)
			cout << 0.25*WP[i]+0.5*OWP[i]+0.25*OOWP[i] << endl;
	}
	return 0;
}