#include <iostream>
#include <string>

using namespace std;

int main()
{
	freopen("data.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, N, K;
	scanf("%d", &T);
	for(int i=1; i<=T; i++)
	{
		scanf("%d%d", &N, &K);
		printf("Case #%d: ", i);
		K+=1;
		if(K%(1<<N))
			printf("OFF\n");
		else 
			printf("ON\n");
	}
	return 0;
}