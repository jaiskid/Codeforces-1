/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define iin(x)        scanf("%d",&x)
#define din(x)        scanf("%lf",&x)
#define lin(x)        scanf("%lld",&x)
#define clin(x)       scanf("%I64d",&x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define fast          ios::sync_with_stdio(0)
#define read          freopen("input.txt","r",stdin)
#define write         freopen("output.txt","w",stdout)
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"yes":"no")
/* macro definitions */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definitions */

LL MOD_EXPO(LL b, LL p, LL m)
{
    if(p==0) return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++) ans*=N;
    return ans;
}
int SET(int N, int pos)
{
    return (N | (1<<pos));
}
int RESET(int N, int pos)
{
    return (N & !(1<<pos));
}
bool CHECK(int N, int pos)
{
    return (N & (1<<pos));
}
/* necessary functions */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction arrays */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e3;
const long long int mod=1e9+7;
/* global declarations */

string str[mx+5];
int visited[mx+5][mx+5];
int dp[mx+5][mx+5];
int n,m;
bool cycle;

char next_char(char ch)
{
    if(ch=='D') return 'I';
    if(ch=='I') return 'M';
    if(ch=='M') return 'A';
    if(ch=='A') return 'D';
    return '#';
}

void dfs(int x, int y)
{
    int i,nx,ny,cnt;

    if(visited[x][y]==1) cycle=true;
    if(cycle) return;

    visited[x][y]=1;

    for(i=0; i<4; i++)
    {
        nx=x+dx4[i];
        ny=y+dy4[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && str[nx][ny]==next_char(str[x][y]) && visited[nx][ny]<2)
        {
            dfs(nx,ny);
        }
    }
    visited[x][y]=2;
    return;
}

int calc(int x, int y)
{
    int i,nx,ny;

    int &ret=dp[x][y];
    if(ret!=-1) return ret;

    ret=0;

    for(i=0; i<4; i++)
    {
        nx=x+dx4[i];
        ny=y+dy4[i];
        if(nx>=0 && ny>=0 && nx<n && ny<m && str[nx][ny]==next_char(str[x][y]))
        {
            ret=max(ret,calc(nx,ny));
        }
    }
    ret+=(str[x][y]=='A');
    return ret;
}

int main()
{
    int i,j,ans,k;
    fast;
    while(cin>>n>>m)
    {
        setzero(visited);
        setneg(dp);
        for(i=0; i<n; i++) cin>>str[i];
        cycle=false;
        ans=0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                if(!visited[i][j] && str[i][j]=='D')
                {
                    dfs(i,j);
                }
            }
        }
        ans=0;
        for(i=0; i<n && !cycle; i++)
        {
            for(j=0; j<m && !cycle; j++)
            {
                if(str[i][j]=='D')
                {
                    ans=max(ans,calc(i,j));
                }
            }
        }
        if(cycle) pr1("Poor Inna!");
        else if(!ans) pr1("Poor Dima!");
        else pr1(ans);
    }
    return 0;
}
