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
const long long int mx=100000;
const long long int mod=1000000007;
/* global declaration */

LL a[mx+5],prefix[mx+5],suffix[mx+5];

int main()
{
    LL i,j,n,k,pre_min,suf_min,pre_idx,suf_idx,ans,mn,mn_idx;
    while(cin>>n)
    {
        for(i=1;i<=n;i++) scanf("%lld",&a[i]);
        prefix[0]=0;
        suffix[n+1]=0;
        pre_min=suf_min=INT_MAX;
        for(i=1,j=n;i<=n && j>=1;i++,j--)
        {
            prefix[i]=prefix[i-1]+a[i];
            suffix[j]=suffix[j+1]+a[j];
            if(prefix[i]<pre_min)
            {
                pre_min=prefix[i];
                pre_idx=i;
            }
            if(suffix[j]<suf_min)
            {
                suf_min=suffix[j];
                suf_idx=j;
            }
        }
        ans=0;
        if(pre_min<0 && suf_min<0)
        {
            if(pre_idx<suf_idx)
            {
                ans=(-prefix[pre_idx])+(-suffix[suf_idx])+(prefix[suf_idx-1]-prefix[pre_idx]);
            }
            else
            {
                ans=(-prefix[n]);
            }
        }
        else if(pre_min<0)
        {
            ans=(-prefix[pre_idx]*2)+prefix[n];
        }
        else if(suf_min<0)
        {
            ans=(-suffix[suf_idx]*2)+suffix[1];
        }
        else
        {
            ans=prefix[n];
        }
        pr1(ans);
    }
    return 0;
}
