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
const int maxs = 104;

double wp[maxs];
double owp[maxs];
double oowp[maxs];
double tmpwp[maxs][maxs];
int n;
char ch[maxs][maxs];


void calwp()
{
	for (int i=0;i<n;i++)
	{
		int win = 0,lose=0;
		for (int j=0;j<n;j++)
		{
			if (ch[i][j]=='1') win ++;
			else if (ch[i][j]=='0')
			{
				lose ++;
			}
		}
		wp[i] = (win*1.0)/((win+lose)*1.0);
		for (int j=0;j<n;j++)
		{
			if (ch[i][j] == '.')
			{
				tmpwp[i][j] = wp[i];
			}
			else if (ch[i][j] == '1')
			{
				tmpwp[i][j] = ((win-1)*1.0)/((win-1+lose)*1.0);
			}
			else if (ch[i][j] == '0')
			{
				tmpwp[i][j] = (win*1.0)/((win+lose-1)*1.0);
			}
		}
	}
}
void calowp()
{
	for (int i=0;i<n;i++)
	{
		int ans= 0;
		double sum = 0.0;
		for (int j=0;j<n;j++)
		{
			if (ch[i][j] != '.')
			{
				ans ++ ;
				sum += tmpwp[j][i];
			}
		}
		owp[i] = sum/(ans*1.0);
	}
}
void caloowp()
{
	for (int i=0;i<n;i++)
	{
		int cnt = 0;
		double sum = 0.0;
		for (int j=0;j<n;j++)
		{
			if (ch[i][j] != '.')
			{
				cnt ++ ;
				sum += owp[j];
			}
		}
		oowp[i] = sum/(cnt*1.0);
	}
}
int main()
{
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int testcases;
	cin >> testcases;
	for (int caseid=1;caseid<=testcases;caseid++)
	{	
		cin >> n ;
		for (int i=0;i<n;i++)
		{
			cin >> ch[i];
		}
		calwp();
		calowp();
		caloowp();
		cout << "Case #"<<caseid<<":"<<endl;
		for (int i=0;i<n;i++)
		{
			double rpi = 0.25*wp[i] + 0.50*owp[i] + 0.25*oowp[i];
			//cout <<  << rpi << endl;
			printf("%.10lf\n",rpi);
		}
	}
	return 0;
}