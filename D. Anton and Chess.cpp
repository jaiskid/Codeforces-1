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
    for(i=1;i<=K;i++) ans*=N;
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
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

LL up,down,_left,_right;
LL up_left,up_right,down_left,down_right;

string up_s,down_s,left_s,right_s;
string up_left_s,up_right_s,down_left_s,down_right_s;


int main()
{
    LL x,y,i,n,nx,ny,king_x,king_y;
    char str[100];
    while(cin>>n>>king_x>>king_y)
    {
        up_left=up_right=INT_MAX;
        down_left=down_right=INT_MAX;
        up=down=_left=_right=INT_MAX;
        for(i=0;i<n;i++)
        {
            scanf("%s",str);
            lin(x);
            lin(y);
            nx=king_x-x;
            ny=king_y-y;
            if(nx==0)
            {
                if(ny>0 && ny<_right)
                {
                    _right=ny;
                    right_s=str;
                }
                if(ny<0 && abs(ny)<_left)
                {
                    _left=abs(ny);
                    left_s=str;
                }
            }
            if(ny==0)
            {
                if(nx>0 && nx<up)
                {
                    up=nx;
                    up_s=str;
                }
                if(nx<0 && abs(nx)<down)
                {
                    down=abs(nx);
                    down_s=str;
                }
            }
            if(abs(nx)==abs(ny))
            {
                if(nx>0 && ny>0 && abs(nx)<up_right)
                {
                    up_right=abs(nx);
                    up_right_s=str;
                }
                if(nx>0 && ny<0 && abs(nx)<up_left)
                {
                    up_left=abs(nx);
                    up_left_s=str;
                }
                if(nx<0 && ny>0 && abs(nx)<down_right)
                {
                    down_right=abs(nx);
                    down_right_s=str;
                }
                if(nx<0 && ny<0 && abs(nx)<down_left)
                {
                    down_left=abs(nx);
                    down_left_s=str;
                }
            }
        }
        if(up_s=="B") up=INT_MAX;
        if(down_s=="B") down=INT_MAX;
        if(left_s=="B") _left=INT_MAX;
        if(right_s=="B") _right=INT_MAX;
        if(up_left_s=="R") up_left=INT_MAX;
        if(up_right_s=="R") up_right=INT_MAX;
        if(down_left_s=="R") down_left=INT_MAX;
        if(down_right_s=="R") down_right=INT_MAX;
        prflag1(up!=INT_MAX || down!=INT_MAX || _left!=INT_MAX || _right!=INT_MAX || up_left!=INT_MAX || up_right!=INT_MAX || down_left!=INT_MAX || down_right!=INT_MAX);
    }
    return 0;
}
