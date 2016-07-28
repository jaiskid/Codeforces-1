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

LL x[mx+5],y[mx+5];

double distance_(LL x1, LL y1, LL x2, LL y2)
{
    return sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));
}

int main()
{
    LL ax,ay,bx,by,tx,ty,i,n,aidx,bidx;
    double ans,walk,cnt1,cnt2,cnt3,cnt4;
    while(cin>>ax>>ay>>bx>>by>>tx>>ty>>n)
    {
        ans=0.0;
        for(i=0; i<n; i++)
        {
            scanf("%lld %lld",&x[i],&y[i]);
            ans+=distance_(x[i],y[i],tx,ty)*2.0;
        }
        cnt1=INT_MAX;
        cnt2=INT_MAX;
        for(i=0; i<n; i++)
        {
            walk=distance_(x[i],y[i],ax,ay)-distance_(x[i],y[i],tx,ty);
            if(walk<cnt1) cnt1=walk,aidx=i;

            walk=distance_(x[i],y[i],bx,by)-distance_(x[i],y[i],tx,ty);
            if(walk<cnt2) cnt2=walk,bidx=i;
        }
        cnt3=INT_MAX;
        cnt4=INT_MAX;
        for(i=0; i<n && aidx==bidx; i++)
        {
            walk=distance_(x[i],y[i],bx,by)-distance_(x[i],y[i],tx,ty);
            if(walk<cnt3 && i!=bidx) cnt3=walk;

            walk=distance_(x[i],y[i],ax,ay)-distance_(x[i],y[i],tx,ty);
            if(walk<cnt4 && i!=aidx) cnt4=walk;
        }
        walk=ans;
        ans=INT_MAX;

        if(aidx==bidx) ans=min(walk+cnt1+cnt3,walk+cnt2+cnt4);
        else ans=walk+cnt1+cnt2;

        if(walk+cnt1<ans) ans=walk+cnt1;
        if(walk+cnt2<ans) ans=walk+cnt2;

        printf("%.12lf\n",ans);
    }
    return 0;
}
