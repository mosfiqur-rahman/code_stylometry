#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char original[26];
bool seen[26];
int T;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d\n", &T);

	original['q'-'a']='z', seen['z'-'a']=true;
	original['e'-'a']='o', seen['e'-'a']=true;
	original['y'-'a']='a', seen['y'-'a']=true;

	for(int t=1; t<=T; t++)
	{
		string input, output;
		getline(cin, input);
		getline(cin, output);
		for(int i=0; i<input.length(); i++)
			if(isalpha(input[i]))
			{
				original[input[i]-'a']=output[i];
				seen[output[i]-'a']=true;
			}
	}

	char x, y;
	for(int i=0; i<26; i++)
	{
		if(!seen[i])
			y=i+'a';
		if(!isalpha(original[i]))
			x=i+'a';
	}
	original[x-'a']=y;

	scanf("%d\n", &T);
	for(int t=1; t<=T; t++)
	{
		string s;
		getline(cin, s);
		for(int i=0; i<s.length(); i++)
			if(isalpha(s[i]))
				s[i] = original[s[i]-'a'];
		printf("Case #%d: %s\n", t, s.c_str()); 
	}
	return 0;
}