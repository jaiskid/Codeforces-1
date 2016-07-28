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
const long long int mx=2e5;
const long long int mod=1e9+7;
/* global declaration */

int parent[mx+5],roots[mx+5];
int compid[mx+5],represent[mx+5];
int n,root,check[mx+5];
bool visited[mx+5],cycles[mx+5];
vi edges[mx+5];

void dfs(int node, int id)
{
    int i,k;
    visited[node]=true;
    compid[node]=id;

    for(i=0; i<edges[node].size(); i++)
    {
        k=edges[node][i];
        if(!visited[k]) dfs(k,id);
    }
    return;
}

bool find_root(int node)
{
    check[node]=1;
    if(parent[node]==node)
    {
        roots[compid[node]]=node;
        check[node]=2;
        return false;
    }
    if(check[parent[node]]==1)
    {
        check[node]=2;
        return true;
    }
    if(check[parent[node]]==2)
    {
        check[node]=2;
        return false;
    }
    bool flag=find_root(parent[node]);
    if(flag)
    {
        cycles[compid[node]]=true;
        roots[compid[node]]=node;
        flag=false;
    }
    check[node]=2;
    return flag;
}

int main()
{
    int i,cnt,component,k;
    cin>>n;

    for(i=1; i<=n; i++)
    {
        scanf("%d",&parent[i]);
        edges[i].pb(parent[i]);
        edges[parent[i]].pb(i);
    }
    component=0;
    for(i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            component++;
            represent[component]=i;
            dfs(i,component);
        }
    }
    root=0;
    for(i=1; i<=component; i++)
    {
        find_root(represent[i]);
        if(!cycles[i] && !root) root=roots[i];
    }
    if(!root) root=roots[1];
    cnt=0;
    for(i=1; i<=component; i++)
    {
        k=roots[i];
        if(cycles[i]) cnt++;
        else if(!cycles[i] && k!=root) cnt++;
        parent[k]=root;
    }
    pr1(cnt);
    for(i=1; i<=n; i++)
    {
        printf("%d ",parent[i]);
    }
    nl;

    return 0;
}
