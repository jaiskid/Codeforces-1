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

struct graph
{
    int u,v;
    graph(int a, int b)
    {
        u=a;
        v=b;
    }
};

vector<graph>edges_st;
bool visited[mx+5];
int color[mx+5];
vi edges[mx+5];
int n,m;
bool have[mx+5];

void dfs(int node, int flag)
{
    int i,x;
    visited[node]=1;
    color[node]=flag;
    for(i=0;i<edges[node].size();i++)
    {
        x=edges[node][i];
        if(!visited[x] && !color[x]) dfs(x,flag%2+1);
    }
    return;
}

int main()
{
    int i,a,b,j,cnt1,cnt2;
    set<int> set1,set2;
    bool flag;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        edges[a].pb(b);
        edges[b].pb(a);
        edges_st.pb(graph(a,b));
        have[a]=have[b]=1;
    }
    for(i=1;i<=n;i++)
    {
        if(have[i] && !visited[i]) dfs(i,1);
    }
    flag=true;
    cnt1=cnt2=0;
    for(i=0;i<m;i++)
    {
        a=edges_st[i].u;
        b=edges_st[i].v;
        if(color[a]==color[b]) flag=false;
        if(color[a]==1) set1.insert(a),cnt1++;
        if(color[b]==1) set1.insert(b),cnt1++;
        if(color[a]==2) set2.insert(a),cnt2++;
        if(color[b]==2) set2.insert(b),cnt2++;
    }
    if(cnt1==m && cnt2==m && flag)
    {
        pr1(set1.size());
        for(i=1;i<=n;i++)
        {
            if(color[i]==1) printf("%d ",i);
        }
        nl;
        pr1(set2.size());
        for(i=1;i<=n;i++)
        {
            if(color[i]==2) printf("%d ",i);
        }
        nl;
    }
    else
    {
        pr1(-1);
    }
    return 0;
}
