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
const int maxs = 1000006;

int r,c;
char ch[55][55];

void getAC()
{
	for (int i=0;i<r;i++)
	{
		for (int j=0;j<c;j++)
		{
			if (ch[i][j]=='#' && (j<c-1 && ch[i][j+1]=='#') && (i<r-1 && ch[i+1][j]=='#') && (ch[i+1][j+1]=='#'))
			{
				ch[i][j] = '/';
				ch[i+1][j+1]='/';
				ch[i+1][j] ='\\'; 
				ch[i][j+1] = '\\';
			}
		}
	}
	bool flag = true;
	for (int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			if (ch[i][j] == '#')
			{
				flag = false ;break;
			}
		}
	}
	if (!flag)
	{
		cout << "Impossible" << endl;
	}
	else 
	{
		for (int i=0;i<r;i++)
		{
			for (int j=0;j<c;j++)
			{
				cout << ch[i][j];
			}
			cout << endl;
		}
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
		cin >> r >> c;
		for (int i=0;i<r;i++)
		{
			cin >> ch[i];
		}
		cout << "Case #"<<caseid<<":\n" ;
		getAC();
	}
	return 0;
}