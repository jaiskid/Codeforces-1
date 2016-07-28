/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
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
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
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
const long long int mx=500;
/* global declaration */

int r1,r2,c1,c2,m,n;
char str[mx+5][mx+5];
bool visited[mx+5][mx+5];

int check(int x, int y)
{
    int i,nx,ny;
    int a=0;
    for(i=0; i<4; i++)
    {
        nx=x+dx4[i];
        ny=y+dy4[i];
        if(nx<m && ny<n && nx>=0 && ny>=0 && str[nx][ny]=='.')
        {
            a++;
        }
    }
    return a;
}

void dfs(int x, int y)
{
    int i,nx,ny;
    for(i=0; i<4; i++)
    {
        nx=x+dx4[i];
        ny=y+dy4[i];
        if(nx==r2 && ny==c2)
        {
            visited[nx][ny]=true;
            return;
        }
        if(nx<m && ny<n && nx>=0 && ny>=0 && str[nx][ny]=='.' && !visited[nx][ny])
        {
            visited[nx][ny]=true;
            dfs(nx,ny);
        }
    }
    return;

}

int main()
{
    int i,j;
    while(cin>>m>>n)
    {
        for(i=0; i<m; i++)
        {
            scanf("%s",str[i]);
        }
        cin>>r1>>c1>>r2>>c2;
        r1--;r2--;c1--;c2--;
        if(r1==r2 && c1==c2)
        {
            if(check(r2,c2))
                pr1("YES");
            else
                pr1("NO");
            return 0;
        }
        else if(r1==r2 || c1==c2)
        {
            if(c1-1==c2 || c1+1==c2 || r1-1==r2 || r1+1==r2)
            {
                if(str[r2][c2]=='.')
                {
                    if(check(r2,c2))
                        pr1("YES");
                    else
                        pr1("NO");
                }
                else
                    pr1("YES");
                return 0;
            }
        }
        dfs(r1,c1);
        if(visited[r2][c2])
        {
            if(str[r2][c2]=='.')
            {
                if(check(r2,c2)>=2)
                    pr1("YES");
                else
                    pr1("NO");
            }
            else
                pr1("YES");
        }
        else
        {
            pr1("NO");
        }

    }
    return 0;
}
