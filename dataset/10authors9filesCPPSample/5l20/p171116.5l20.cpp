#include<iostream>
#include <algorithm>
using namespace std;
struct node
{
        double p;
        char tmp[15];
        int c[101];
}a[101];
int s[101],top;
double ans;
int nnum;
char str[6][20];
bool check(int j)
{
       for(int i=0;i<nnum;++i)
       {
          if(strcmp(str[i],a[j].tmp)==0)return true;
        }
        return false;
}
double findp(int root)
{
    int i;
  //  printf("->%d(%lf/%s/%d)",root,a[root].p,a[root].tmp,check(root));
    if(a[root].c[0]==0)return a[root].p;
    if(check(root)) return a[root].p*findp(a[root].c[1]);
    else return a[root].p*findp(a[root].c[2]);
}
int main()
{
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
        int t,root=0,i,p=0,n,len,j,num=0;
        a[0].p=1;
        scanf("%d",&t);
        char tmp[40];
        while(t--)
        {
                scanf("%d",&n);
                gets(tmp);
                num=top=0;s[top]=0;

                for(i=1;i<=n;++i)
                {
                   gets(tmp);
               //    printf("%s\n",tmp);
                   len=strlen(tmp);
                   int tt=0;
                   for(j=0;j<len;++j)
                   {
                       if(tmp[j]=='(')
                       {
                             ++a[s[top]].c[0];
                             a[s[top]].c[a[s[top]].c[0]]=++num;
                             s[++top]=num;
                             a[num].c[0]=0;
                       }
                       else if(tmp[j]>='0'&&tmp[j]<='9')
                       {
                            sscanf(tmp+j,"%lf",&a[num].p);
                            while(tmp[j]>='0'&&tmp[j]<='9'||tmp[j]=='.')++j;
                            --j;
                       }
                       else if(tmp[j]<='z'&&tmp[j]>='a')
                       {
                            a[num].tmp[tt++]=tmp[j];
                       }
                       else if(tmp[j]==')') --top;
                   }
                   a[num].tmp[tt]=0;
                }

                printf("Case #%d:\n",++p);
                scanf("%d",&n);
                for(i=0;i<n;++i)
                {
                        scanf("%s",tmp);
                        scanf("%d",&nnum);
                        for(j=0;j<nnum;++j)scanf("%s",str[j]);
                        printf("%.7lf\n",findp(1));
                }


        }
        return 0;
}
