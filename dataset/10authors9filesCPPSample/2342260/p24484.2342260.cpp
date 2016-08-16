#include <fstream>
#include <algorithm>
using namespace std;


ifstream fin("ain.txt");
ofstream fou("aou.txt");


int main()
{
	int CaseNum;
	fin >> CaseNum;


	int n;
	int a[2000],b[2000];
	int ans;

	for (int i=1; i<=CaseNum; i++){
		fin >> n;
		for ( int k=1; k<=n; k++){
			fin >> a[k];
		}
		for ( int k=1; k<=n; k++){
			fin >> b[k];
		}


		for (int k=1; k<=n-1; k++)
		for (int j=k+1; j<=n; j++){
			if (a[k]>a[j]) swap( a[k] , a[j] );
		}

		for (int k=1; k<=n-1; k++)
		for (int j=k+1; j<=n; j++){
			if (b[k]<b[j]) swap( b[k] , b[j] );
		}

		ans = 0;
		for (int k=1; k<=n; k++){
			ans += a[k]*b[k];
		}

		fou << "Case #"<<i<<": "<<ans<<endl;

	}

	return 0;
}
