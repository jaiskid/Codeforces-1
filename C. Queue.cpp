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
typedef pair<int, string>pis;
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
    for(i=1; i<=K; i++) ans*=N;
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

struct node
{
    string name;
    int height;
    int taller;
    node(string ss, int tt)
    {
        name=ss;
        taller=tt;
    }
    node()
    {

    }
};

bool operator<(node A, node B)
{
    return A.taller<B.taller;
}

int main()
{
    char str[100+5];
    string ss;
    int i,k,n,a,b,j,idx,cnt,c;
    bool flag;
    while(cin>>n)
    {
        vector<node>vps;
        for(i=0; i<n; i++)
        {
            scanf("%s %d",str,&a);
            ss=str;
            vps.pb(node(ss,a));
        }
        sort(vps.begin(),vps.end());
        flag=true;
        for(i=0; i<n; i++)
        {
            k=vps[i].taller;
            if(k>i)
            {
                flag=false;
                break;
            }
        }
        if(!flag)
        {
            pr1(-1);
            continue;
        }
        for(i=0; i<n; i++) vps[i].height=n-i;
        for(i=1; i<n; i++)
        {
            cnt=0;
            for(j=0; j<i; j++)
            {
                if(vps[j].height>vps[i].height) cnt++;
            }
            cnt-=vps[i].taller;
            vi index;
            b=vps[i].height;
            c=b;
            for(j=0;j<i;j++)
            {
                a=vps[j].height;
                if(a>b && a<=b+cnt) vps[j].height=c++;
            }
            vps[i].height=c;
        }
        for(i=0;i<n;i++)
        {
            printf("%s %d\n",vps[i].name.c_str(),vps[i].height);
        }
    }
    return 0;
}
