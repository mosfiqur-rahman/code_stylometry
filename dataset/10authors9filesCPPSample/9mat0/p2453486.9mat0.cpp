#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <utility>
#include <vector>
#include <iterator>
#include <map>
#include <set>
#include <algorithm>
#include <list>

#define FOR(i,n) for(int i = 0, n_ = (n); i<n_; i++)
#define ITER(it, lst) for(typeof((lst).begin()) it = (lst).begin(); it != (lst).end(); ++it)
#define N 4

using namespace std;

int result(const vector<string> &board){
  int x, o, t;
  FOR(i, N){
    x = o = t = 0;
    FOR(j, N)
      if(board[i][j] == 'T') t++;
      else if(board[i][j] == 'X') x++;
      else if(board[i][j] == 'O') o++;
    if(x + t == N) return 1;
    if(o + t == N) return 2;

    x = o = t = 0;
    FOR(j, N)
      if(board[j][i] == 'T') t++;
      else if(board[j][i] == 'X') x++;
      else if(board[j][i] == 'O') o++;
    if(x + t == N) return 1;
    if(o + t == N) return 2;  
  }

  x = o = t = 0;
  FOR(i, N) 
    if(board[i][i] == 'T') t++;
    else if(board[i][i] == 'X') x++;
    else if(board[i][i] == 'O') o++;
  if(x + t == N) return 1;
  if(o + t == N) return 2;  

  x = o = t = 0;
  FOR(i, N) 
    if(board[i][N-i-1] == 'T') t++;
    else if(board[i][N-i-1] == 'X') x++;
    else if(board[i][N-i-1] == 'O') o++;
  if(x + t == N) return 1;
  if(o + t == N) return 2;

  FOR(i,N) FOR(j,N) if(board[i][j] == '.') return 0;
  return 3;
}

int main(){
  int T;
  string line;
  getline(cin, line);
  
  istringstream iss(line);
  iss >> T;

  vector<string> board(4, "....");

  FOR(t, T){
    int count = 0;
    while(count < N*N){
      getline(cin, line);
      FOR(i, line.length())
	if(line[i] == 'X' || line[i] == 'O' || line[i] == '.' || line[i] == 'T'){
	  board[count/N][count%N] = line[i];
	  count++;
	}
    }

    int res = result(board);
    switch(res) {
    case 0: cout<<"Case #"<<t+1<<": Game has not completed"<<endl; break;
    case 1: cout<<"Case #"<<t+1<<": X won"<<endl; break;
    case 2: cout<<"Case #"<<t+1<<": O won"<<endl; break;
    case 3: cout<<"Case #"<<t+1<<": Draw"<<endl; break;
    }
  }

  return 0;
}
