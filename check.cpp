#include<bits/stdc++.h>
using namespace std;
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%ld",&x)
#define scf(x) scanf("%f",&x)
#define scd(x) scanf("%lf",&x)
#define nnn cout<<endl
#define clr clear()
#define srt sort
#define pb push_back
#define ps push
#define sz size()
#define frnt front
#define beg begin()
#define end end()
#define sqr(x) (x)*(x)
#define gc getchar()
#define FOR(i, b, e) for(int i = b; i <= e; i++)
typedef long long ll;
char hor[6][62]= {"*****..***..*...*.*****...*...*.*****.*****.***...*****.*...*",
                  "*.....*...*.*...*.*.......*...*.*...*...*...*..*..*...*..*.*.",
                  "*****.*****.*...*.***.....*****.*****...*...*...*.*...*...*..",
                  "....*.*...*..*.*..*.......*...*.*.*.....*...*..*..*...*...*..",
                  "*****.*...*...*...*****...*...*.*..**.*****.***...*****...*.."
                 };
char ver[62][6]=
{
    "*****",
    "*....",
    "*****",
    "....*",
    "*****",
    ".....",
    ".***.",
    "*...*",
    "*****",
    "*...*",
    "*...*",
    ".....",
    "*...*",
    "*...*",
    "*...*",
    ".*.*.",
    "..*..",
    ".....",
    "*****",
    "*....",
    "***..",
    "*....",
    "*****",
    ".....",
    ".....",
    ".....",
    "*...*",
    "*...*",
    "*****",
    "*...*",
    "*...*",
    ".....",
    "*****",
    "*...*",
    "*****",
    "*.*..",
    "*..**",
    ".....",
    "*****",
    "..*..",
    "..*..",
    "..*..",
    "*****",
    ".....",
    "***..",
    "*..*.",
    "*...*",
    "*..*.",
    "***..",
    ".....",
    "*****",
    "*...*",
    "*...*",
    "*...*",
    "*****",
    ".....",
    "*...*",
    ".*.*.",
    "..*..",
    "..*..",
    "..*.."
};
int main()
{
    int n;
    while(true)
    {
        scanf("%d",&n);
        if(n==0)break;
        if(n>0)
        {
            FOR(i,0,4)
            {
                string str;
                FOR(j,0,60)
                    FOR(l,0,n-1)
                        str+=hor[i][j];
                FOR(l,0,n-1)
                    printf("%s\n",str.c_str());
            }
            printf("\n\n");
        }
        else
        {
            n=abs(n );
            FOR(i,0,60)
            {
                string str;
                FOR(j,0,4)
                    FOR(l,0,n-1)
                        str+=ver[i][j];
                FOR(l,0,n-1)
                    printf("%s\n",str.c_str());
            }
            printf("\n\n");
        }
    }
    return 0;
}
