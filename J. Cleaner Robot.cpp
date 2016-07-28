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

int dx4[]= {-1,0,1,0};
int dy4[]= {0,1,0,-1};
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
const long long int mx=10;
const long long int mod=1000000007;
/* global declaration */

string str[mx+5];
bool visited[mx+5][mx+5],flag;
int n,m;

bool valid(int a, int b)
{
    return (a>=0 && a<n && b>=0 && b<m && str[a][b]=='.');
}

int main()
{
    int i,j,k,a,b,cnt,dir,nx,ny;
    while(cin>>n>>m)
    {
        flag=true;
        for(i=0; i<n; i++)
        {
            cin>>str[i];
            if(flag)
            {
                for(j=0; j<m; j++)
                {
                    if(str[i][j]=='U') dir=0,flag=false,a=i,b=j;
                    if(str[i][j]=='R') dir=1,flag=false,a=i,b=j;
                    if(str[i][j]=='D') dir=2,flag=false,a=i,b=j;
                    if(str[i][j]=='L') dir=3,flag=false,a=i,b=j;
                }
            }
        }
        set0(visited);
        cnt=1;
        visited[a][b]=true;
        str[a][b]='.';
        i=0;
        while(i<10000)
        {
            nx=a+dx4[dir];
            ny=b+dy4[dir];
            if(valid(nx,ny))
            {
                if(!visited[nx][ny]) cnt++;
                a=nx;
                b=ny;
                visited[nx][ny]=true;
            }
            else
            {
                dir++;
                if(dir==4) dir=0;
            }
            i++;
        }
        pr1(cnt);
    }
    return 0;
}
