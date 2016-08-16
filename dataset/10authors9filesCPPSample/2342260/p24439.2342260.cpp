#include <fstream>
using namespace std;

ifstream fin("ain.txt");
ofstream fou("aou.txt");



const int maxn=10000000;

int M , V;
int w[10005][2];

int f[10005][2];




void readdata()
{
	fin >> M >> V;


	for (int i=1; i<=(M-1)/2; i++){
		fin >> w[i][0] >> w[i][1];
	}

	for (int i=(M+1)/2; i<=M; i++){
		fin >> w[i][0];
		f[i][w[i][0]]=0;
		f[i][(w[i][0]+1)%2]=maxn;
	}

}


void dp( int x )
{
	if ( x >= (M+1)/2 ){
		return;
	}

	dp( x*2 );
	dp( x*2+1);

	f[x][0]=maxn;
	f[x][1]=maxn;


	int and[2], or[2];

	and[0]=maxn; and[1]=maxn;
	or[0]=maxn; or[1]=maxn;

	for (int i=0; i<=1; i++)
	for (int k=0; k<=1; k++){
		if ( f[x*2][i]+f[x*2+1][k] < and[i && k] ){
			and[i && k]=f[x*2][i]+f[x*2+1][k];
		}
		if ( f[x*2][i]+f[x*2+1][k] < or[i || k] ){
			or[i || k]=f[x*2][i]+f[x*2+1][k];
		}
	}


	if (w[x][0]==1){
		f[x][0]=and[0];
		if (w[x][1]==1 && f[x][0]> or[0]+1) f[x][0]=or[0]+1;

		f[x][1]=and[1];
		if (w[x][1]==1 && f[x][1]> or[1]+1) f[x][1]=or[1]+1;
	}
	else{
		f[x][0]=or[0];
		if (w[x][1]==1 && f[x][0]> and[0]+1) f[x][0]=and[0]+1;

		f[x][1]=or[1];
		if (w[x][1]==1 && f[x][1]> and[1]+1) f[x][1]=and[1]+1;

	}


}







int main()
{

	int CaseNum;
	fin >> CaseNum;

	for (int T=1; T<=CaseNum; T++){
		readdata();
		dp(1);




		fou << "Case #" <<T<<": ";


		for (int i=1; i<=M; i++){
			fou << "No " << i << " " << f[i][0] <<' '<< f[i][1] << endl;
		}


		if (f[1][V]>=maxn){
			fou <<"IMPOSSIBLE"<< endl;
		}
		else{
			fou <<f[1][V] << endl;
		}
	}

	return 0;
}
