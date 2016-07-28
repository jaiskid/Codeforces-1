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

struct essay
{
    string str;
    int str_len,cntr;
};

int n,m,vis[mx+5];
vi nodes,edges[mx+5];
vector<essay>all_nodes;
map<string,int>mp;

essay reform(string str)
{
    int i,cnt;
    essay faul;
    cnt=0;
    for(i=0; i<str.size(); i++)
    {
        str[i]=tolower(str[i]);
        if(str[i]=='r') cnt++;
    }
    faul.cntr=cnt;
    faul.str=str;
    faul.str_len=str.size();

    return faul;
}

int dfs(int idx)
{
    int i,j,k;

    vis[idx]=idx;
    for(i=0; i<edges[idx].size(); i++)
    {
        j=edges[idx][i];
        if(vis[j]==0)
        {
            k=dfs(j);
            j=vis[idx];
        }
        else
        {
            k=vis[j];
            j=vis[idx];
        }

        if(all_nodes[k-1].cntr<all_nodes[j-1].cntr)
        {
            vis[idx]=k;
        }
        else if(all_nodes[k-1].cntr==all_nodes[j-1].cntr)
        {
            if(all_nodes[k-1].str_len<all_nodes[j-1].str_len)
            {
                vis[idx]=k;
            }
        }

    }
    return vis[idx];
}

int main()
{
    int pos,i,j,k,tot,sum;
    string x,y;
    essay dhur,bal;
    fast;
    cin>>m;
    pos=0;
    for(i=1; i<=m; i++)
    {
        cin>>x;
        dhur=reform(x);
        if(mp[dhur.str]==0)
        {
            pos++;
            mp[dhur.str]=pos;
            all_nodes.pb(dhur);
        }
        j=mp[dhur.str];
        nodes.pb(j);
    }
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>x>>y;
        dhur=reform(x);
        bal=reform(y);
        if(mp[dhur.str]==0)
        {
            pos++;
            mp[dhur.str]=pos;
            all_nodes.pb(dhur);
        }
        if(mp[bal.str]==0)
        {
            pos++;
            mp[bal.str]=pos;
            all_nodes.pb(bal);
        }
        j=mp[dhur.str];
        k=mp[bal.str];
        edges[j].pb(k);
    }
    for(i=0; i<m; i++)
    {
        j=nodes[i];
        if(vis[j]==0) nodes[i]=dfs(j);
        else nodes[i]=vis[j];
    }
    tot=sum=0;
    for(i=0; i<m; i++)
    {
        j=nodes[i];
        tot+=all_nodes[j-1].cntr;
        sum+=all_nodes[j-1].str_len;
    }
    pr2(tot,sum);
    return 0;
}
