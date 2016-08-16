#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
using namespace std;

map <string,bool> MAP;

int l,d,n;
char word[20000];
char ext[20];
string tmp;
int num;
int len;

void dfs(int depth,int loc)
{
    int loc2;
    if (loc>=len) {
        ext[depth]=0;
        tmp=ext;
        if (MAP.count(tmp)) num++;
        return;
    }
    if (word[loc]=='(') {
        loc2=loc;
        while (word[loc2]!=')') loc2++;
        for (int i=loc+1;i<loc2;i++) {
            ext[depth]=word[i];
            ext[depth+1]=0;
            tmp=ext;
            if (MAP.count(tmp)) dfs(depth+1,loc2+1);
        }
    }
    else {
        ext[depth]=word[loc];
        ext[depth+1]=0;
        tmp=ext;
        if (MAP.count(tmp)) dfs(depth+1,loc+1);
    }
}

int main()
{
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    scanf("%d %d %d",&l,&d,&n);
    for (int i=0;i<d;i++) {
        scanf("%s",word);
        memset(ext,0,sizeof(ext));
        for (int j=0;j<l;j++) {
            ext[j]=word[j];
            tmp=ext;
            MAP[tmp]=true;
        }
        tmp=word;
        MAP[tmp]=true;
    }
    for (int i=0;i<n;i++) {
        num=0;
        scanf("%s",word);
        len=strlen(word);
        memset(ext,0,sizeof(ext));
        dfs(0,0);
        printf("Case #%d: %d\n",i+1,num);
    }
    return 0;
}
