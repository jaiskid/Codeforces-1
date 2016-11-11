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
const long long int mx=5e4;
const long long int mod=1e9+7;
/* global declarations */

LL val[mx+5];
LL a,b,c,d;

void calc(void)
{
    LL i;
    for(i=0; i<=mx; i++)
    {
        val[i]=i*(i-1)/2;
    }
    return;
}

LL check(LL x)
{
    LL i;
    for(i=0; i<=mx; i++)
    {
        if(val[i]==x) return i;
    }
    return -1;
}

int main()
{
    LL i,j,have,zeroes,ones;
    string str;
    bool flag;
    calc();
    while(cin>>a>>b>>c>>d)
    {
        zeroes=check(a);
        ones=check(d);
        flag=true;
        flag&=(zeroes>=0 && ones>=0);
        flag&=((zeroes*ones==b+c) || (zeroes==b+c && !ones) || (ones==b+c && !zeroes));
        if(!zeroes && !ones && b==1 && c==0)
        {
            pr1("01");
            continue;
        }
        if(!zeroes && !ones && b==0 && c==1)
        {
            pr1("10");
            continue;
        }
        if(zeroes*ones==b+c)
        {
            str="";
            for(i=0; i<zeroes; i++) str+="0";
            for(i=0; i<ones; i++) str+="1";
            have=0;
            i=zeroes-1;
            while(have<c && flag)
            {
                j=i+ones;
                if(c-have<ones) j=i+(c-have);
                swap(str[i],str[j]);
                have+=ones;
                i--;
            }
        }
        else if(zeroes==b+c)
        {
            str="1";
            for(i=0; i<zeroes; i++) str+="0";
            swap(str[0],str[b]);
        }
        else if(ones==b+c)
        {
            str="0";
            for(i=0; i<ones; i++) str+="1";
            swap(str[0],str[c]);
        }
        if(!flag) str="Impossible";
        if(a+b+c+d==0) str="0";
        pr1(str);
    }
    return 0;
}
