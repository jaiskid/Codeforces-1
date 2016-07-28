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

#define set0(a)       memset(a,0,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define pr1(x)        cout<<x<<"\n"
#define pr2(x,y)      cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)    cout<<x<<" "<<y<<" "<<z<<"\n"
#define pr4(w,x,y,z)  cout<<w<<" "<<x<<" "<<y<<" "<<z<<"\n"
#define prflag1(flag) printf("%s\n",(flag)?"YES":"NO")
#define prflag2(flag) printf("%s\n",(flag)?"Yes":"No")
#define prflag3(flag) printf("%s\n",(flag)?"First":"Second")
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
typedef pair<double, double>pdd;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<double>vd;
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
const long long int mx=500;
const long long int mod=1000000007;
/* global declaration */

char str[mx+5][mx+5];
bool visited[mx+5][mx+5];
LL level[mx+5][mx+5],n,m;

bool valid(int x, int y)
{
    return (x>=0 && x<m && y>=0 && y<n && str[x][y]=='.');
}

int main()
{
    LL i,j,ans,nx,ny,a,b,u,v;
    while(cin>>n>>m>>a>>b)
    {
        queue<pll>q;
        for(i=0;i<m;i++)
        {
            scanf("%s",str[i]);
        }
        visited[0][0]=true;
        level[0][0]=0;
        q.push(pll(0ll,0ll));
        ans=0;
        while(!q.empty())
        {
            pll top=q.front();
            q.pop();
            for(i=0;i<4;i++)
            {
                nx=top.first+dx4[i];
                ny=top.second+dy4[i];
                if(valid(nx,ny) && !visited[nx][ny])
                {
                    visited[nx][ny]=true;
                    level[nx][ny]=level[top.first][top.second]+1;
                    if(visited[m-1][n-1]) break;
                    q.push(pll(nx,ny));
                }
            }
            if(visited[m-1][n-1]) break;
        }
        u=level[m-1][n-1]/2;
        v=level[m-1][n-1]-u;
        ans=u*a+v*b;
        if(visited[m-1][n-1]) pr1(ans);
        else pr1("IMPOSSIBLE");
    }
    return 0;
}
