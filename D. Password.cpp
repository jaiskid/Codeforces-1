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
const long long int mx=1e6;
/* global declarations */

LL hash;
LL base=29;
LL mod=1e9+7;
LL power[mx+5];
LL pre_hash[mx+5];

vi sizes;
string str;
LL n;

bool OK(int len)
{
    int i,j;
    LL x,y;
    hash=0;
    for(i=n-2,j=len-1; j>=0 && i>=1; j--,i--)
    {
        x=str[i];
        hash=(hash+(x*power[j])%mod)%mod;
    }
    if(pre_hash[len-1]==hash) return true;
    while(i>=1)
    {
        x=str[i];
        y=str[i+len];
        hash=((hash-(y*power[len-1])%mod)+mod)%mod;
        hash=(hash*base+x)%mod;
        i--;
        if(pre_hash[len-1]==hash) return true;
    }
    return false;
}

int main()
{
    int i,j,len,low,high,mid,ans;
    LL x;
    string out;
    cin>>str;
    power[0]=1;
    n=str.size();
    for(i=1; i<=n; i++)
    {
        power[i]=(power[i-1]*base)%mod;
    }
    hash=0;
    for(i=0; i<n; i++)
    {
        x=str[i];
        hash=(hash+x*power[i])%mod;
        pre_hash[i]=hash;
    }
    hash=0;
    for(i=n-1,j=0; i>=0; i--,j++)
    {
        x=str[i];
        hash=(x+hash*base)%mod;
        if(pre_hash[j]==hash) sizes.pb(n-i);
    }
    low=0;
    high=sizes.size()-1;
    ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(OK(sizes[mid]))
        {
            ans=sizes[mid];
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(ans==-1)
    {
        pr1("Just a legend");
    }
    else
    {
        for(i=0; i<ans; i++) out+=str[i];
        pr1(out);
    }
    return 0;
}
