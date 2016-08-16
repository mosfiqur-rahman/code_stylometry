#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("ain.txt");
ofstream fou("aou.txt");


const int maxn = 1000005;

int P, K , L;
int a[maxn];


void readdata()
{
	fin >>	P >> K >> L;
	memset( a , 0 , sizeof(a));
	for ( int i=1; i<=L; i++){
		fin >> a[i];
	}


	for (int i=1; i<=L-1; i++)
	for (int k=i+1; k<=L; k++){
		if (a[i]<a[k]){
			swap( a[i] , a[k] );
		}
	}


}



unsigned long long work()
{
	i=1;
	unsigned long long ans=0;

	for (int p=1; p<=P; k++){
		for(int k=1; k<=K; k++){
			ans += a[k+((p-1)*K)]*p;
		}
	}

	return ans;
}




int main()
{
	int CaseNum;
	fin >> CaseNum;

	unsigned long long ans;

	for (int T=1; T<=CaseNum; T++){
		readdata();
		ans = work();
		fou << "Case #" << T << ": " << ans << endl;
	}



	return 0;
}
