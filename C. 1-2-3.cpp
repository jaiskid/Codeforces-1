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
const long long int mx=15;
const long long int mod=1e9+7;
/* global declarations */

LL cycle;
LL path_length;
LL A[mx+5][mx+5];
LL B[mx+5][mx+5];
LL pointa[mx*mx+5];
LL pointb[mx*mx+5];
LL visited[mx+5][mx+5];

void find_cycle(LL a, LL b, LL pnta, LL pntb)
{
    if(visited[a][b])
    {
        cycle=visited[a][b];
        return;
    }

    path_length++;
    visited[a][b]=path_length;
    pointa[path_length]=pnta;
    pointb[path_length]=pntb;
    if(a==1)
    {
        if(b==2) pointb[path_length]++;
        if(b==3) pointa[path_length]++;
    }
    if(a==2)
    {
        if(b==3) pointb[path_length]++;
        if(b==1) pointa[path_length]++;
    }
    if(a==3)
    {
        if(b==1) pointb[path_length]++;
        if(b==2) pointa[path_length]++;
    }
    //pr4(a,b,pointa[path_length], pointb[path_length]);
    find_cycle(A[a][b], B[a][b], pointa[path_length], pointb[path_length]);
    return;
}

int main()
{
    LL k,a,b,i,j,ansa,ansb,cyclea,cycleb,cycle_length;
    cin>>k>>a>>b;
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++) cin>>A[i][j];
    }
    for(i=1; i<=3; i++)
    {
        for(j=1; j<=3; j++) cin>>B[i][j];
    }
    find_cycle(a,b,0,0);

    if(k<=path_length)
    {
        ansa=pointa[k];
        ansb=pointb[k];
    }
    else
    {
        ansa=pointa[cycle-1];
        ansb=pointb[cycle-1];
        cyclea=pointa[path_length]-pointa[cycle-1];
        cycleb=pointb[path_length]-pointb[cycle-1];

        k-=cycle-1;
        cycle_length=path_length-cycle+1;

        ansa+=(k/cycle_length)*cyclea;
        ansb+=(k/cycle_length)*cycleb;
        k=k%cycle_length;

        if(k) ansa+=pointa[k+cycle-1]-pointa[cycle-1];
        if(k) ansb+=pointb[k+cycle-1]-pointb[cycle-1];
    }
    pr2(ansa,ansb);
    return 0;
}
