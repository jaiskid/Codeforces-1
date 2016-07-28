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
const long long int mx=100000;
const long long int mod=1000000007;
/* global declaration */

int main()
{
    int i,n,cnt[10],sum,a;
    while(cin>>n)
    {
        set0(cnt);
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            cnt[a]++;
            sum+=a;
        }
        if(cnt[0]==0)
        {
            pr1(-1);
            continue;
        }
        if(sum%3==2)
        {
            if(cnt[2]>0) cnt[2]--,sum-=2;
            else if(cnt[5]>0) cnt[5]--,sum-=5;
            else if(cnt[8]>0) cnt[8]--,sum-=8;
            else if(cnt[1]>1) cnt[1]-=2,sum-=2;
            else if(cnt[4]>0 && cnt[1]>0) cnt[4]--,cnt[1]--,sum-=5;
            else if(cnt[4]>1) cnt[4]-=2,sum-=8;
            else if(cnt[7]>0 && cnt[1]>0) cnt[7]--,cnt[1]--,sum-=8;
            else if(cnt[7]>0 && cnt[4]>0) cnt[7]--,cnt[4]--,sum-=11;
            else if(cnt[7]>1) cnt[7]-=2,sum-=14;
        }
        if(sum%3==1)
        {
            if(cnt[1]>0) cnt[1]--,sum-=1;
            else if(cnt[4]>0) cnt[4]--,sum-=4;
            else if(cnt[7]>0) cnt[7]--,sum-=7;
            else if(cnt[2]>1) cnt[2]-=2,sum-=4;
            else if(cnt[5]>0 && cnt[2]>0) cnt[5]--,cnt[2]--,sum-=7;
            else if(cnt[5]>1) cnt[5]-=2,sum-=10;
            else if(cnt[8]>0 && cnt[2]>0) cnt[8]--,cnt[2]--,sum-=10;
            else if(cnt[8]>0 && cnt[5]>0) cnt[8]--,cnt[5]--,sum-=13;
            else if(cnt[8]>1) cnt[8]-=2,sum-=16;
        }
        i=1;
        while(i<10)
        {
            if(cnt[i]) break;
            i++;
        }
        if(i==10)
        {
            if(cnt[0]) pr1(0);
            else pr1(-1);
            continue;
        }
        if(sum%3)
        {
            pr1(-1);
            continue;
        }
        i=9;
        while(i>=0)
        {
            while(cnt[i]) printf("%d",i),cnt[i]--;
            i--;
        }
        nl;
    }
    return 0;
}
