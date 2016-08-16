#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

map <string,int> feat;

struct Node {
    int num;
    int l,r;
    double val;
};

Node node[100000];
bool has[500];
char tmp;
string str;
char tp[200];

int kase,k,num,tot;
int l,a,n,len,curr,line;
double res;

void init(int loc)
{
    node[loc].l=node[loc].r=-1;node[loc].num=-1;
    //memset(node[loc].con,0,sizeof(node[loc].con));
    //while (line<l) {
        do {
            scanf("%c",&tmp);
            if (tmp=='\n') line++;
        } while(line<l&&(tmp=='\n'||tmp==' '));
        if (tmp=='(') {
            scanf("%lf",&node[loc].val);
            scanf("%s",tp);
            if (tp[0]==')') return;
            str=tp;
            feat[str]=++tot;
            node[loc].num=tot;
            node[loc].l=++num;
            node[loc].r=++num;
            init(node[loc].l);
            init(node[loc].r);
            do {
                scanf("%c",&tmp);
                if (tmp=='\n') line++;
            } while(line<l&&(tmp=='\n'||tmp==' '));
            return;
        }
    //}
}

void calc(int loc)
{
    res*=node[loc].val;
    if (node[loc].l==-1) return;
    if (has[node[loc].num]) calc(node[loc].l);
    else calc(node[loc].r);
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    scanf("%d",&kase);
    while (kase--) {
        num=0;
        tot=0;
        scanf("%d\n",&l);
        /*for (int i=0;i<l;i++) {
            gets(l);
            while ()
        }*/
        line=0;
        init(0);
        printf("Case #%d:\n",++k);
        scanf("%d",&a);
        for (int i=0;i<a;i++) {
            scanf("%s%d",tp,&n);
            memset(has,false,sizeof(has));
            for (int j=0;j<n;j++) {
                scanf("%s",tp);
                str=tp;
                has[feat[str]]=true;
            }
            res=1.0;
            calc(0);
            printf("%.7f\n",res);
        }
    }
    return 0;
}
