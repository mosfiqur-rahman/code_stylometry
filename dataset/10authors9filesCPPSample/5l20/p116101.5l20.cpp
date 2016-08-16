#include<iostream>
using namespace std;
struct node
{
        int c[26];
        int flag;
}a[75002];
int root=0,tot=0;
int l,d,n;
char tmp[300];
int deal()
{
        int q[6000],r1=0,r2=0,ans=0;
        int ch[26],num=0,len=strlen(tmp),j=0;
        //printf("%s",tmp);
        if(tmp[j]=='(')
        {
                num=0;
                while(tmp[++j]!=')')
                {
                        ch[num++]=tmp[j]-'a';
                }
                ++j;
        }
        else num=1,ch[0]=tmp[j++]-'a';
       // for(int i=0;i<num;++i) printf("%d ",ch[i]);
       // printf("\n");
        int lv=0;
        while(r1<=r2)
        {
                int t=q[r1++];
               // printf("%d:\n",t);
                if(a[t].flag==l)
                {
                        ++ans;
                        continue;
                }
                if(a[t].flag!=lv)
                {
                    if(tmp[j]=='(')
                    {
                        num=0;
                        while(tmp[++j]!=')') ch[num++]=tmp[j]-'a';
                        ++j;
                    }
                     else num=1,ch[0]=tmp[j++]-'a';
                     ++lv;
                }
                for(int i=0;i<num;++i)
                {
                      //  printf("(%c->%d)",'a'+ch[i],a[t].c[ch[i]]);
                        if(a[t].c[ch[i]]!=0)q[++r2]= a[t].c[ch[i]];
                }
               // printf("\n");
        }
        return ans;

}
int main()
{

        freopen("in.txt","r",stdin);
        freopen("smallout.txt","w",stdout);
        scanf("%d%d%d",&l,&d,&n);
        for(int i=0;i<d;++i)
        {
                scanf("%s",tmp);
                root=0;
                for(int j=0;j<l;++j)
                {
                    if(a[root].c[tmp[j]-'a']==0) a[root].c[tmp[j]-'a']=++tot;
                    a[root].flag=j;
                    root=a[root].c[tmp[j]-'a'];

                }
                a[root].flag=l;
        }
        /*for(int i=0;i<=tot;++i)
        {
             printf("%d(",i);
             for(int j=0;j<26;++j)
             {
                    if(a[i].c[j]!=0) printf("%c->%d,",j+'a',a[i].c[j]);
             }
           //  printf("  flag: %d\n",a[i].flag);
        }*/
        for(int i=1;i<=n;++i)
        {
                scanf("%s",tmp);
                printf("Case #%d: %d\n",i,deal());
        }
        return 0;
}
