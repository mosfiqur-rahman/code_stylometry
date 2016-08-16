#include <iostream>
#include <fstream>
#include <string>
using namespace std;



ifstream fin("p1in.txt");
ofstream fou("p1out.txt");

                            
int L , D , N;
string dict[5001];


int work( string s)
{
    int len = s.length();

    bool word[15][26];
    memset( word , 0 , sizeof(word));

    int ipp = 0;   // the pointer to the current pattern     0 - L-1
    int ips = 0;   // the pointer to the current string  s   0 - len
    while(ipp<L){
    	if (s[ips]=='('){
            ips++;
            while (s[ips]!=')'){
        		word[ipp][s[ips]-'a']=true;
                ips++;
            }
            ips++;
        }
        else{
            word[ipp][s[ips]-'a']=true;
            ips++;
        }
        ipp++;
    }

    int ans = 0;

    //calculate answer
    for (int i=1; i<=D; i++){
        bool match = true;
    	for (int k=0; k<L; k++){
            if (!word[k][dict[i][k]-'a']) {
                match = false;
                break;
            }
        }
        if (match){
            ans ++;
        }
    }

    return ans;
}



int main()
{
	fin >> L >> D >> N;
    for (int i=1; i<=D; i++){
        string s;
    	fin >> s;
        dict[i]=s;
    }

    for (int i=1; i<=N; i++){
    	fou << "Case #" << i << ": ";
    	string s;
        fin >> s;
        fou << work( s ) << endl;
    }

    system("pause");
    return 0;
}
