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
const long long int mx=5000;
const long long int mod=1e9+7;
/* global declarations */

vi edges[mx+5],cost[mx+5];
int n,m,t,a;
vi out;
int dist[mx+5][mx+5],par[mx+5][mx+5];

class node
{
public:
    int u,v,w;
    node(LL a, LL b, LL c)
    {
        u=a;
        v=b;
        w=c;
    }
    node()
    {

    }
};

bool operator<(node A, node B)
{
    return B.w<A.w;
}

void Dijkstra(void)
{
    node top;
    int x,i,a,k,b,j;
    for(i=0; i<=mx; i++)
    {
        for(j=0; j<=mx; j++) dist[i][j]=2e9;
    }

    priority_queue<node>Q;
    Q.push(node(1,1,0));
    par[1][1]=0;
    dist[1][1]=0;

    while(!Q.empty())
    {
        top=Q.top();
        Q.pop();

        x=top.u;
        b=top.v;
        k=top.w;
        if(k>=t) continue;

        for(i=0; i<edges[x].size(); i++)
        {
            a=edges[x][i];
            if(dist[x][b]+cost[x][i]<dist[a][b+1] && dist[x][b]+cost[x][i]<=t)
            {
                dist[a][b+1]=dist[x][b]+cost[x][i];
                par[a][b+1]=x;
                Q.push(node(a,b+1,dist[a][b+1]));
            }
        }
    }
    return;
}

int main()
{
    int i,j,u,v;
    cin>>n>>m>>t;
    for(i=0; i<m; i++)
    {
        iin(u);
        iin(v);
        iin(a);
        edges[u].pb(v);
        cost[u].pb(a);
    }
    Dijkstra();
    for(i=n; i>=1; i--)
    {
        if(dist[n][i]==2e9) continue;
        u=n;
        v=i;
        while(u)
        {
            out.push_back(u);
            u=par[u][v];
            v--;
        }
        break;
    }
    reverse(out.begin(),out.end());
    pr1(out.size());
    for(i=0; i<out.size(); i++)
    {
        printf("%d ",out[i]);
    }
    nl;
    return 0;
}
