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
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

LL arr[mx+5];
LL sum[mx+5];
LL tree[4*mx+5];

void build(LL node, LL b, LL e)
{
    if(b==e)
    {
        tree[node]=sum[b];
        return;
    }

    LL l=2*node;
    LL r=2*node+1;
    LL mid=(b+e)/2;
    build(l,b,mid);
    build(r,mid+1,e);
    tree[node]=max(tree[l],tree[r]);
    return;
}

LL query(LL node, LL b, LL e, LL x, LL y)
{
    if(b>y || e<x)
    {
        return LONG_MIN;
    }
    if(b>=x && e<=y)
    {
        return tree[node];
    }
    LL l=2*node;
    LL r=2*node+1;
    LL mid=(b+e)/2;
    return max(query(l,b,mid,x,y),query(r,mid+1,e,x,y));
}

int main()
{
    LL i,n,d,ans,extra,can_add,max_val;
    bool flag;
    while(cin>>n>>d)
    {
        ans=0;
        sum[0]=0;
        flag=true;
        for(i=1; i<=n; i++)
        {
            lin(arr[i]);
            sum[i]=sum[i-1]+arr[i];
            if(sum[i]>d) flag=false;
        }
        build(1,1,n);
        extra=0;
        if(flag)
        {
            for(i=1; i<=n; i++)
            {
                if(arr[i]==0)
                {
                    if(sum[i]+extra<0)
                    {
                        max_val=query(1,1,n,i,n);
                        can_add=d-max_val-extra;
                        if(sum[i]+extra+can_add<0)
                        {
                            flag=false;
                            break;
                        }
                        else
                        {
                            ans++;
                            extra+=can_add;
                        }
                    }
                }
            }
        }
        if(!flag) ans=-1;
        pr1(ans);
    }
    return 0;
}
