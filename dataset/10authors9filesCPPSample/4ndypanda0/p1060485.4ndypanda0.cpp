#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int T, R, C;
char grid[51][51];

bool valid(int ci, int cj)
{
	if(ci+1>=R || cj+1>=C)
		return false;
	if(grid[ci+1][cj]=='#' && grid[ci+1][cj+1]=='#' && grid[ci][cj+1]=='#')
		return true;
	return false;
}

bool solve()
{
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(grid[i][j]=='#')
				if(valid(i, j))
				{
					grid[i][j]='/';
					grid[i+1][j]='\\';
					grid[i+1][j+1]='/';
					grid[i][j+1]='\\';
				}
				else return false;
	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	cin >> T;
	for(int t=1; t<=T; t++)
	{
		cin >> R >> C;
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				cin >> grid[i][j];
		printf("Case #%d:\n", t);
		if(solve())
			for(int i=0; i<R; i++)
			{
				for(int j=0; j<C; j++)
					cout << grid[i][j];
				cout << endl;
			}
		else
			printf("Impossible\n");
	}
	return 0;
}