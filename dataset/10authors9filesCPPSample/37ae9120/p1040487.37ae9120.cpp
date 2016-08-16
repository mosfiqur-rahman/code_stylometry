

#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;






int main()
{
    int cs=0,T;
    scanf("%d",&T);
    while(cs++<T){
        printf("Case #%d: ",cs);
        
        int N,pd,pg;
        scanf("%d%d%d",&N,&pd,&pg);
        
        if(pd==100 && pg==100){puts("Possible");continue;}
        if(pd>0 && pg==0){puts("Broken");continue;}
        
        int b=100;
        if(pd%2==0){ b/=2; }
        if(pd%4==0){b/=2;}
        if(pd%5==0)b/=5;
        if(pd%25==0)b/=5;
        
        if(N>=b){
            
            if(pg==100)puts("Broken");
            else puts("Possible");
        }
        else{
            puts("Broken");    
        }
        
    }
    
    return 0;    
}
