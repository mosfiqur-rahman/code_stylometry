#include <iostream>
using namespace std;
int main()
{
	int t,n,k,count=1;
		freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	cin>>t;
	while (t--)
	{
		cin>>n>>k;
		if (k%(1<<n)==(1<<n)-1)
			cout<<"Case #"<<count++<<": ON"<<endl;
		else
			cout<<"Case #"<<count++<<": OFF"<<endl;
	}
	return 0;
}