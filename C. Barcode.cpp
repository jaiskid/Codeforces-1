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
const long long int mx=1000;
const long long int mod=1e9+7;
/* global declaration */

string str[mx+5];
LL cnt[5][mx+5],black[mx+5][mx+5],white[mx+5][mx+5],dp[5][mx+5];
LL n,m,x,y;

LL unknown_type(LL i, bool flag)
{
    if(i>=m) return 0;

    LL &ret=dp[flag][i];
    if(ret!=-1) return ret;

    LL ans=INT_MAX;
    LL a;
    for(a=x;a<=y;a++)
    {
        if(flag==0 && i+a<=m) ans=min(ans,unknown_type(i+a,!flag)+white[i][a]);
        if(flag==1 && i+a<=m) ans=min(ans,unknown_type(i+a,!flag)+black[i][a]);
    }
    ret=ans;
    return ans;
}

int main()
{
    LL i,j,cnt1,cnt2,k;
    fast;
    cin>>n>>m>>x>>y;
    for(i=0;i<n;i++) cin>>str[i];
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cnt[0][i]+=(str[j][i]=='#');
            cnt[1][i]+=(str[j][i]=='.');
        }
    }
    for(i=0;i<m-x+1;i++)
    {
        cnt1=cnt2=0;
        for(j=i;j<i+x && j<m;j++)
        {
            cnt1+=cnt[0][j];
            cnt2+=cnt[1][j];
        }
        white[i][x]=cnt1;
        black[i][x]=cnt2;
        for(j=i+x,k=x;j<i+y && j<m;j++,k++)
        {
            cnt1+=cnt[0][j];
            cnt2+=cnt[1][j];
            white[i][k+1]=cnt1;
            black[i][k+1]=cnt2;
        }
    }
    setneg(dp);
    pr1(min(unknown_type(0,0),unknown_type(0,1)));
    return 0;
}
