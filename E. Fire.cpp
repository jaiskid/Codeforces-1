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
const long long int mx=2000;
const long long int mn=100;
const long long int mod=1e9+7;
/* global declarations */

struct item
{
    int index,save,burn,price;
};

bool operator<(item A, item B)
{
    if(A.burn < B.burn) return true;
    if(A.burn == B.burn) return A.price > B.price;
    return false;
}

int n;
vi indexes;
item items[mn+5];
int dp[mn+5][mx+5];

int save_items(int i, int total)
{
    if(i>n) return 0;
    int &ret=dp[i][total];
    if(ret) return ret;

    int l,r;
    l=r=0;
    if(total+items[i].save<items[i].burn) l = save_items(i+1,total+items[i].save)+items[i].price;
    r = save_items(i+1,total);

    ret=max(l,r);
    return ret;
}

void print_path(int i, int k, int ans)
{
    if(i>n or ans<=0) return;
    int s=items[i].save;
    int p=items[i].price;

    if(dp[i+1][s+k]==ans-p)
    {
        indexes.push_back(i);
        print_path(i+1,s+k,ans-p);
    }
    else
    {
        print_path(i+1,k,ans);
    }
    return;
}

int main()
{
    int i,k,ans;
    cin>>n;
    for(i=1; i<=n; i++)
    {
        iin(items[i].save);
        iin(items[i].burn);
        iin(items[i].price);
        items[i].index = i;
    }
    setzero(dp);
    sort(items+1, items+n+1);

    ans=save_items(1,0);
    print_path(1,0,ans);

    pr1(ans);
    pr1(indexes.size());
    for(i=0; i<indexes.size(); i++) printf("%d ",items[indexes[i]].index);
    nl;
    return 0;
}
