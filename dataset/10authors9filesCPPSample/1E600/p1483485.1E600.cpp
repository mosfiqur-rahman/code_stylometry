#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main(void)
{
#if 1
	//Conversion
	char str[100*5];
	int conv_table[26]={
		24,7,4,18,14,2,21,23,3,20,8,6,11,1,10,17,25,19,13,22,9,15,5,12,0,16,
	};
	int N;
	int n;
	scanf("%d\n",&N);
	for (n=1;n<=N;n++){
		memset(str,0,sizeof(str));
		scanf("%[a-z ]\n",str);
		int i=0;
		while (str[i]!='\0'){
			if (str[i]!=' '){
				str[i]='a'+conv_table[str[i]-'a'];
			}
			i++;
		}
		printf("Case #%d: %s\n",n,str);
	}
	return 0;
#else
	//Generate conversion table
	const char *A="zyqeeejpmysljylckdkxveddknmcrejsicpdrysirbcpcypcrtcsradkhwyfrepkymveddknkmkrkcddekrkdeoyakwaejtysrreujdrlkgcjv";
	const char *B="qazooourlanguageisimpossibletounderstandtherearetwentysixfactorialpossibilitiessoitisokayifyouwanttojustgiveup";
	const char *p1=A,*p2=B;
	int table[26],Af[26],Bf[26];
	int i;
	for (i=0;i<26;i++){
		table[i]=-1;Af[i]=Bf[i]=0;
	}
	while (*p1!='\0'){
		int i1,i2;
		i1=(*p1)-'a';
		i2=(*p2)-'a';
		assert(table[i1]==-1 || table[i1]==i2);
		table[i1]=i2;
		Af[i1]=1;
		Bf[i2]=1;
		p1++;p2++;
	}
	int cnt=0;
	for (i=0;i<26;i++){
		if (table[i]==-1){
			assert(0);
		}
		else{
			fprintf(stderr,"%c -> %c\n",(char)'a'+i,(char)'a'+table[i]);
			cnt++;
		}
	}
	for (i=0;i<26;i++){
		printf("%d,",table[i]);
	}
	printf("\n");
#endif
}
