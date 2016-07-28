/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)
#define mp(a,b)       make_pair(a,b)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

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
/* defining macros */

using namespace std;

template <class T> inline T bigmod(T b, T p, T m)
{
    T ret;
    if(p==0) return 1;
    if(p&1)
    {
        ret=(bigmod(b,p/2,m)%m);
        return ((b%m)*ret*ret)%m;
    }
    else
    {
        ret=(bigmod(b,p/2,m)%m);
        return (ret*ret)%m;
    }
}
/* template functions */

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
/* type definition */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int tc=1;
const double eps=1e-9;
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declaration */

vll edges[mx+5],revedges[mx+5];
LL n,m,comp[mx+5],compid,cnt[mx+5],costs[mx+5],comp_min_cnt[mx+5];
stack<LL>sortedlist;
bool visited[mx+5];

void dfs1(LL node)
{
    LL i,a;

    visited[node]=1;
    for(i=0;i<edges[node].size();i++)
    {
        a=edges[node][i];
        if(!visited[a]) dfs1(a);
    }

    sortedlist.push(node);
    return;
}

LL dfs2(LL node, LL x)
{
    LL i,a,b;

    visited[node]=0;
    comp[node]=x;
    b=costs[node];
    for(i=0;i<revedges[node].size();i++)
    {
        a=revedges[node][i];
        if(visited[a]) b=min(b,dfs2(a,x));
    }
    return b;
}

void SCC(void)
{
    LL i,a,b,ans1,ans2;
    for(i=1;i<=n;i++)
    {
        if(!visited[i]) dfs1(i);
    }
    compid=0;
    while(!sortedlist.empty())
    {
        a=sortedlist.top();
        sortedlist.pop();
        if(visited[a])
        {
            compid++;
            cnt[compid]=dfs2(a,compid);
        }
    }
    for(i=1;i<=n;i++)
    {
        a=comp[i];
        b=cnt[a];
        if(b==costs[i]) comp_min_cnt[a]++;
    }
    ans1=0;
    ans2=1;
    for(i=1;i<=compid;i++)
    {
        ans1+=cnt[i];
        ans2=(ans2*comp_min_cnt[i])%mod;
    }
    printf("%lld %lld\n",ans1,ans2);
    return;
}

int main()
{
    LL i,a,b;
    scanf("%lld",&n);
    for(i=1;i<=n;i++) scanf("%lld",&costs[i]);
    scanf("%lld",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%lld %lld",&a,&b);
        edges[a].pb(b);
        revedges[b].pb(a);
    }
    SCC();
    return 0;
}
