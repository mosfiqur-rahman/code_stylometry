#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


ifstream fin("ain.txt");
ofstream fou("aou.txt");

int CaseNum;
int S,Q;

string wn[120];
int q[1200];
const int maxn=1000000;


void readdata()
{
	string str;

	fscanf( fin , "%d" , &S);
	for (int i=1; i<=S; i++){
		getline( fin, wn[i]);
	}
	fscanf( fin , "%d" , &N);
	for (int i=1; i<=Q; i++){
		getline( fin, str );
		for (int k=1; k<=S; k++){
			if (str == wn[k]){
				q[i]=k;
				break;
			}
		}
	}

}


int work()
{
	int f[120][1200];
	memset(f,0,sizeof(f));

	f[1][q[1]]=maxn;

	int tmp;

	for (int i=2; i<=Q; i++){
		for (int k=1; k<=S; k++){
			tmp=maxn;
			if (q[i]!=k){
				tmp=f[i-1][k];
			}
			for (int h=1; h<=S; h++){
				if (h==k) continue;
				if (f[i-1][h]+1 < f[i][k]){
					tmp = f[i-1][h]+1;
				}
			}
			f[i][k]=tmp;
		}
	}


	tmp=maxn;
	for (int k=1; k<=S; k++){
		if (f[Q][k]<tmp) tmp=f[Q][k];
	}

	return tmp;
}



int main()
{
	fscanf( fin , "%d" , &CaseNum);

	int ans;
	for (int i=1; i<=CaseNum; i++){
		readdata();
		ans=work();
		fou << "Case #" << i << ": " << ans << endl;
	}

	fin.close();
	fou.close();

	return 0;
}
