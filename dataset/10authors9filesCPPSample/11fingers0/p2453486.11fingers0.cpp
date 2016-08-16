#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <bitset>

using namespace std;

#define dbg(x) cerr<<#x<<" : "<<x<<endl;
#define inf (1<<30)
#define PB push_back
#define MP make_pair
#define mset(x, a) memset(x, (a), sizeof(x))
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;
const double PI = acos(-1.0);
const double eps = 1e-8;
#define INPUT_FILE "in.txt"
#define OUTPUT_FILE "out.txt"

bool is_end = false;
char board[5][5];

bool check_is_full()
{
    for(int i = 0; i < 4; ++i)
        for(int j = 0; j < 4; ++j)
            if (board[i][j] == '.') return false;
    return true;
}

bool check_single(char &winner, char ch)
{
    if(ch == '.') return false;
    if(ch == 'T') return true;
    if(winner == 0)
    {
        winner = ch;
        return true;
    }
    else return winner == ch;
}

int check_win(char a, char b, char c, char d)
{
    char winner = 0;
    if (!check_single(winner, a)) return 0;
    if (!check_single(winner, b)) return 0;
    if (!check_single(winner, c)) return 0;
    if (!check_single(winner, d)) return 0;

    return winner;
}

void proc(int cs)
{
    for(int i = 0; i < 4; ++i) 
    {
        gets(board[i]);
        if(!board[i][0]) --i;
    }

    int ret = 0;
    for(int i = 0; i < 4; ++i)
    {
        ret |= check_win(board[i][0], board[i][1], board[i][2], board[i][3]);
        ret |= check_win(board[0][i], board[1][i], board[2][i], board[3][i]);
    }
    ret |= check_win(board[1][1], board[2][2], board[3][3], board[0][0]);
    ret |= check_win(board[0][3], board[1][2], board[2][1], board[3][0]);

    printf("Case #%d: ", cs);
    if (ret == 0)
    {
        if(check_is_full()) puts("Draw");
        else puts("Game has not completed");
    }
    else printf("%c won\n", ret);
}

int main(int argc, char *argv[])
{
    int n;
    freopen(INPUT_FILE, "r", stdin);
    freopen(OUTPUT_FILE, "w", stdout);

    scanf("%d", &n);
    for (int cs = 1; cs <= n; ++cs)
        proc(cs);
   	
	return 0;
}
