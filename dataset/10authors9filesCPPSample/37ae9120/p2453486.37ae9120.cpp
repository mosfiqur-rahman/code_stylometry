
#include <cstdio>

char mp[10][10];

bool win(char c)
{
    for(int i=0;i<4;++i){
        // test row
        bool ok=true;
        for(int j=0;j<4;++j){
            if( mp[i][j]==c || mp[i][j]=='T') continue;
            ok = false;
        }
        if(ok)return true;

        ok = true;
        // test col
        for(int j=0;j<4;++j){
            if( mp[j][i]==c || mp[j][i]=='T') continue;
            ok = false;
        }
        if(ok) return true;
    }


    //diag
    bool ok=true;
    for(int i=0;i<4;++i){
       if(mp[i][3-i]==c || mp[i][3-i]=='T')continue;
       ok=false;
    }
    if(ok) return true;
    ok = true;
    for(int i=0;i<4;++i){
       if(mp[i][i]==c || mp[i][i]=='T')continue;
       ok=false;
    }

    return ok;
}

bool draw()
{
    for(int i=0;i<4;++i)
    for(int j=0;j<4;++j)
        if(mp[i][j]=='.') return false;

    return true;
}


int main()
{
    int t,cs=0;
    scanf("%d",&t);
    
    while( getchar() != '\n');


    while(cs++<t){
        for(int i=0;i<4;++i) gets(mp[i]); 
        gets(mp[4]);

        printf("Case #%d: ",cs);
        if( win('X') ) puts("X won");
        else if( win('O') ) puts("O won");
        else if( draw() ) puts("Draw");
        else
            puts("Game has not completed");
    }


    return 0;
}
