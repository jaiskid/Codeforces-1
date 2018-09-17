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
const long long int mx=2e5;
const long long int mod=1e9+7;
/* global declarations */

int arr[mx+5];

int main()
{
    int i,n,m,cnt1,cnt2,change,a,b;
    bool flag;
    while(cin>>n>>m)
    {
        set<int>odd,even;
        map<int,int>mp;
        for(i=1; i<=n; i++)
        {
            if(i%2) odd.insert(i);
            else even.insert(i);
        }
        cnt1=0;
        cnt2=0;
        for(i=1; i<=n; i++)
        {
            iin(arr[i]);
            if(!mp[arr[i]])
            {
                if(arr[i]%2) odd.erase(arr[i]);
                else even.erase(arr[i]);
            }
            mp[arr[i]]++;
            cnt1+=(arr[i]%2!=0);
            cnt2+=(arr[i]%2==0);
        }
        flag=true;
        change=0;
        for(i=1; i<=n; i++)
        {
            a=arr[i];
            if(mp[a]>1)
            {
                if(a%2)
                {
                    if(cnt1>cnt2)
                    {
                        b=(*even.begin());
                        even.erase(b);
                        cnt1--;
                        cnt2++;
                    }
                    else
                    {
                        b=(*odd.begin());
                        odd.erase(b);
                    }
                }
                else
                {
                    if(cnt1<cnt2)
                    {
                        b=(*odd.begin());
                        odd.erase(b);
                        cnt1++;
                        cnt2--;
                    }
                    else
                    {
                        b=(*even.begin());
                        even.erase(b);
                    }
                }

                change++;
                arr[i]=b;
                mp[b]++;
                mp[a]--;
                if(b>m) flag=false;
            }
        }
        for(i=1; i<=n && cnt1!=cnt2; i++)
        {
            a=arr[i];
            if(cnt1>cnt2 && a%2!=0)
            {
                b=(*even.begin());
                if(b<=m)
                {
                    even.erase(b);
                    cnt1--;
                    cnt2++;
                    change++;
                    arr[i]=b;
                }

            }
            if(cnt2>cnt1 && a%2==0)
            {
                b=(*odd.begin());
                if(b<=m)
                {
                    odd.erase(b);
                    cnt1++;
                    cnt2--;
                    change++;
                    arr[i]=b;
                }
            }
        }

        if(cnt1!=cnt2) flag=false;
        if(flag)
        {
            pr1(change);
            for(i=1; i<=n; i++) printf("%d ",arr[i]);
            nl;
        }
        else
        {
            pr1(-1);
        }
    }
    return 0;
}
