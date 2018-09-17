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
const long long int mx=200;
const long long int mod=1e9+7;
/* global declarations */

int n,k;
int twos[mx+5];
int fives[mx+5];
int dp[mx+5][mx+5][5200+5];

void factor(int i, LL x)
{
    twos[i]=0;
    fives[i]=0;
    while(x%2==0)
    {
        twos[i]++;
        x=x/2ll;
    }
    while(x%5==0)
    {
        fives[i]++;
        x=x/5ll;
    }
    return;
}

int recur(int i, int taken, int two, int five)
{
    if(taken>=k)
    {
        //pr4(i,taken,two,five);
        dp[i][taken][five] = two;
        return dp[i][taken][five];
    }
    if(i>n) return -100000;

    int &ret=dp[i][taken][five];
    if(ret!=-1) return ret;

    int l=0;
    int r=0;
    ret=0;
    l=recur(i+1, taken, two, five);
    r=recur(i+1, taken+1, two+twos[i], five+fives[i]) + twos[i];
    ret=max(ret,max(l,r));
    //pr3(i,l,r);
    return ret;
}

int main()
{
    int i,j,l,ans;
    LL x;
    while(cin>>n>>k)
    {
        for(i=1; i<=n; i++)
        {
            lin(x);
            factor(i,x);
        }
        setneg(dp);
        recur(1,0,0,0);
        ans=0;
        for(i=1; i<=n+1; i++)
        {
            for(l=0; l<=k; l++)
            {
                for(j=0; j<=5200; j++)
                {
                    ans=max(ans, min(dp[i][l][j], j));
                    if(j<=5) pr3(i, dp[i][l][j], j);
                }
            }
        }
        pr1(ans);
    }
    return 0;
}
