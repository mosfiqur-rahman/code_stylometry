#include <iostream>
using namespace std;
int  a[4][4],b[4][4];
int main()
{
	int  Cases;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&Cases);
	for (int i = 1; i<= Cases; ++i)
	{
		printf("Case #%d: ", i);
		int  ind_a, ind_b;
		scanf("%d",&ind_a);
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				scanf("%d",&a[j][k]);
		scanf("%d",&ind_b);
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				scanf("%d",&b[j][k]);
		int ans=0, tmp = 0;
		for(int j=0;j<4;++j)
			for(int k=0;k<4;++k)
				if(a[ind_a-1][j]==b[ind_b-1][k]) {
					tmp = a[ind_a-1][j];
					++ans;
				}
		if(ans==1) printf("%d\n",tmp);
		else if(ans==0) printf("Volunteer cheated!\n");
		else printf("Bad magician!\n");
	}
	return 0;
}