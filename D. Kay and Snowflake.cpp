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
const long long int mx=3e5;
const long long int mod=1e9+7;
/* global declaration */

vll vnode[mx+5];
LL sub_tree[mx+5],parent[mx+5],centroid[mx+5];

LL find_sub_tree_size(LL x)
{
    LL i,cnt;
    cnt=1;
    for(i=0; i<vnode[x].size(); i++)
    {
        cnt+=find_sub_tree_size(vnode[x][i]);
    }
    sub_tree[x]=cnt;
    return cnt;
}

void find_centroid(LL x)
{
    LL i,k,ans,j;
    centroid[x]=x;
    for(k=0; k<vnode[x].size(); k++)
    {
        i=vnode[x][k];
        find_centroid(i);
        if(sub_tree[i]*2>sub_tree[x])
        {
            centroid[x]=centroid[i];
            while(true)
            {
                j=sub_tree[x]-sub_tree[centroid[x]];
                if(j*2<=sub_tree[x]) break;
                centroid[x]=parent[centroid[x]];
                if(centroid[x]==x) break;
            }
        }
    }
    return;
}

int main()
{
    LL i,n,q,p,j;
    cin>>n>>q;
    for(i=2; i<=n; i++)
    {
        scanf("%lld",&p);
        parent[i]=p;
        vnode[p].pb(i);
    }
    find_sub_tree_size(1);
    find_centroid(1);
    while(q--)
    {
        scanf("%lld",&p);
        printf("%lld\n",centroid[p]);
    }
    return 0;
}
