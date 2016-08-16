#include <fstream>
using namespace std;

ifstream fin("p1in.txt");
ofstream fou("p1out.txt");


int N;
char a[50][50];
int d[50];
bool vis[50];


void swap( int& a , int& b )
{
    int c = a; a= b ; b=c;
}


long work()
{
	//d[0]=50;
    memset( d , 0 , sizeof(d) );
    d[0]=50;
	for (int i=1; i<=N; i++){
        for (int k=N; k>=1; k--)
        	if (a[i][k]=='1') {
                d[i]=k;
                break;
            }
    }

    bool tem;
    bool fini = false;
    long ans=0;
    while(!fini){
        tem = false;
        fini = true;
    	for (int i=1; i<=N && !tem ; i++){
        	if (d[i]>i){
                fini = false;
                for (int k=i+1; k<=N; k++){
                    if (d[k]<=i){
                        for (int j=k; j>=i+1; j--){
                        	swap( d[j] , d[j-1] );
                        	ans++;
                        }
                        tem = true;
                    	break;
                    }
                }
            }
        }
    }

    return ans;

}



int main()
{
	int T;
	fin >> T;
    for (int i=1; i<=T; i++){
        fin >> N;
        for (int k=1; k<=N; k++)
        for (int j=1; j<=N; j++) fin >> a[k][j];

        fou << "Case #" << i << ": " << work() << endl;

    }


    return 0;
}

