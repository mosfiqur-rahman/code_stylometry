#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("din.txt");
ofstream fou("dou.txt");

int W , H , R;
int tot;
int c[14][2];
int res[1000000];
const int mod = 10007;


int d[102][102];

void readdata()
{
	 fin >> H >> W >> R;

	 c[0][0]=1; c[0][1]=1;
	 tot=0;
	 int x , y;
	 for (int i=1; i<=R; i++){
		fin >> x >> y;
		if ((x+y)%3==2 && (2*y>=x+1) && (2*x>=y+1) ){
			tot++;
			c[tot][0]=x; c[tot][1]=y;
		}
	 }
	 c[tot+1][0]=H; c[tot+1][1]=W;
	 tot++;

	 for (int i=0; i<=tot-1; i++)
	 for (int k=i+1; k<=tot; k++){
		 if (c[i][0]+c[i][1] > c[k][0]+c[k][1]){
			swap( c[i][0] , c[k][0] );
			swap( c[i][1] , c[k][1] );
		 }
	 }

}


int path( int x1 , int y1 , int  x2 ,  int y2 )
{
	if ( x1>=x2 || y1 >= y2 ){
		return 0;
	}

	memset( d , 0 , sizeof(d));
	d[1][1]=1;

	for (int x=2; x<= x2-x1+1; x++)
	for (int y=2; y<= y2-y1+1; y++){
		if (x-2>0 && y-1>0){
			d[x][y]=(d[x][y] + d[x-2][y-1]) % mod;
		}
		if (x-1>0 && y-2>0){
			d[x][y]=(d[x][y] + d[x-1][y-2]) % mod;
		}
	}

	return d[x2-x1+1][y2-y1+1];

}



int work()
{
	if ( (c[tot][0]+c[tot][1]) % 3 !=2 ){
		return 0;
	}

	int up = 1;
	for (int i=1; i<=tot-1; i++){
		up = up*2;
	}

	int v[14];
	int ok[14];
	int tmp;
	int k;
	for (int h=1; h<=up; h++){
		memset( v , 0 , sizeof(v));
		tmp=h; k=0;
		while (tmp!=0){
			k++;
			v[k]=tmp%2;
			tmp=tmp/2;
		}

		k=0;
		ok[0]=0;
		for (int i=1; i<=tot-1; i++){
			if (v[i]==1){
				k++;
				ok[k]=i;
			}
		}
		k++;
		ok[k]=tot;

		tmp=path( c[ok[0]][0] , c[ok[0]][1] , c[ok[1]][0] , c[ok[1]][1] );
		for (int i=2; i<=k; i++){
			tmp = (tmp * path(c[ok[i-1]][0] , c[ok[i-1]][1] , c[ok[i]][0] , c[ok[i]][1] ) ) % mod;
		}

		res[h]=tmp;
		if (k%2) res[h]=-res[h];
	}


	tmp = path( 1 , 1 , H , W );
	for (int i=1; i<=up; i++){
		tmp = (tmp+res[i])%mod);
	}

	return tmp%mod;

}

 int main()
 {
	int CaseNum;
	fin >> CaseNum;

	int ans;
	for (int T=1; T<=CaseNum; T++){
		readdata();
		ans = work();
		fou << "Case #" << T << ": " << ans << endl;
	}
	return 0;
 }
