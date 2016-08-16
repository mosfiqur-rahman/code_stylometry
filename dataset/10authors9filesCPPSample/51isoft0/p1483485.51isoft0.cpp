#include <stdio.h>
#include <string.h>

char ori[]="ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
char out[]="our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";
char cor[300];
char tmp[2000];
int kk;


int main() {
    freopen("A-small-attempt1.in","r",stdin);
    freopen("A-small-attempt1.out","w",stdout);
    for (int i=0;i<strlen(ori);i++) cor[ori[i]]=out[i];
    cor['z']='q';
    cor['q']='z';
    int kase;
    scanf("%d",&kase);
    gets(tmp);
    while (kase--) {
        gets(tmp);
        printf("Case #%d: ",++kk);
        for(int i=0;i<strlen(tmp);i++) printf("%c",cor[tmp[i]]);
        printf("\n");
    }
    return 0;
}
