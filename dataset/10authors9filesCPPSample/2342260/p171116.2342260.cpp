#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

ifstream fin("p2in.txt");
ofstream fou("p2out.txt");

struct Node
{
    double w;
    string name;
    Node* left;
    Node* right;
};


string item[100000];
int tot;
int idx;

int A;
int tf;
string fea[101];

void inputtree( Node* &t )
{
	double d;
    string name;

    if (idx>=tot) return;
    d = atof(item[idx].c_str() );
    name = item[idx+1];

    if (name[0]>='a' && name[0]<='z'){
        idx++;
    	t = new Node;
        t->w = d;
        t->name = name;
        t->left = 0;
        idx++;
        inputtree(t->left );
        t->right = 0;
        inputtree(t->right );
    }else{
    	t = new Node;
        t->w = d;
        t->name = "#";
        t->left = 0;
        t->right = 0;
        idx++;
    }
}


void readdata()
{
	tot=0;
	while (1){
        tot++;
        fin >> item[tot];
        bool findout= false;
        for (int i=0; i<item[tot].length() ; i++)
        	if (item[tot][i]=='.') {
                findout = true;
                break;
            }
        if ( !findout && (item[tot][0]>='0' && item[tot][0]<='9')  ){
             A = atoi(item[tot].c_str());
             item[tot]="#";
             break;
        }
    }

}


bool havef( string tmp )
{
    for (int i=1; i<=tf; i++)
    	if (tmp==fea[i]) return true;
    return false;
}


void work( Node* t , double& ans )
{
	ans = (t->w)*ans;
    if (t->name == "#") return;
    if (havef( t->name )){
    	work( t->left , ans );
    }else{
        work( t->right , ans );
    }
}

int main()
{

	int T;
    fin >> T;

    for (int i=1; i<=T; i++){
        int L;
        fin >>L;
        readdata();
        Node* t = 0;
        idx=1;
        inputtree( t );

        fou << "Case #" << i << ":" << endl;
        for (int k=1; k<=A; k++){
            string tmp;
            fin >> tmp >> tf;
            for (int j=1; j<=tf; j++){
				fin >> fea[j];
            }

            double ans=1;
            work( t , ans );
            fou << setiosflags(ios::fixed) << setprecision(7) << ans << endl;
        }
    }







	return 0;
}
