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
const long long int mx=1e7;
const long long int mod=1e9+7;
/* global declaration */

int a[mx+5],b[mx+5];
int cnta[mx+5],cntb[mx+5],newa[mx+5],newb[mx+5];
bool x[mx+5];
vi primes;

void sieve(void)
{
    int i,j,s;
    x[1]=true;
    for(i=4;i<=mx;i+=2) x[i]=true;
    s=sqrt(mx);
    for(i=3;i<=s;i+=2)
    {
        if(!x[i])
        {
            for(j=i+i;j<=mx;j+=i) x[j]=true;
        }
    }
    primes.pb(2);
    for(i=3;i<=mx;i+=2)
    {
        if(!x[i]) primes.pb(i);
    }
}

int main()
{
    int i,j,n,m,k,tmp;
    bool flag;

    sieve();

    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=m;i++) scanf("%d",&b[i]);

    for(i=1;i<=n;i++)
    {
        j=0;
        k=sqrt(a[i]);
        tmp=a[i];
        while(primes[j]<=k)
        {
            while(a[i]%primes[j]==0) a[i]/=primes[j],cnta[primes[j]]++;
            j++;
        }
        if(a[i]>1) cnta[a[i]]++;
        a[i]=tmp;
    }
    for(i=1;i<=m;i++)
    {
        j=0;
        k=sqrt(b[i]);
        tmp=b[i];
        while(primes[j]<=k)
        {
            while(b[i]%primes[j]==0) b[i]/=primes[j],cntb[primes[j]]++;
            j++;
        }
        if(b[i]>1) cntb[b[i]]++;
        b[i]=tmp;
    }

    for(i=0;i<primes.size();i++)
    {
        j=primes[i];
        newa[j]=cnta[j];
        newb[j]=cntb[j];
        k=min(cnta[j],cntb[j]);
        cnta[j]-=k;
        cntb[j]-=k;
    }

    for(i=1;i<=n;i++)
    {
        vi store;
        j=0;
        k=sqrt(a[i]);
        while(primes[j]<=k)
        {
            tmp=primes[j];
            while(a[i]%tmp==0) a[i]/=tmp,store.pb(tmp);
            j++;
        }
        j=a[i];
        if(j>1) store.pb(a[i]),a[i]=1;

        for(j=0;j<store.size();j++)
        {
            tmp=store[j];
            if(newa[tmp]>cnta[tmp]) newa[tmp]--;
            else a[i]*=tmp;
        }
    }
    for(i=1;i<=m;i++)
    {
        vi store;
        j=0;
        k=sqrt(b[i]);
        while(primes[j]<=k)
        {
            tmp=primes[j];
            while(b[i]%tmp==0) b[i]/=tmp,store.pb(tmp);
            j++;
        }
        j=b[i];
        if(j>1) store.pb(b[i]),b[i]=1;

        for(j=0;j<store.size();j++)
        {
            tmp=store[j];
            if(newb[tmp]>cntb[tmp]) newb[tmp]--;
            else b[i]*=tmp;
        }
    }

    printf("%d %d\n",n,m);
    for(i=1;i<=n;i++) printf("%d ",a[i]);
    nl;

    for(i=1;i<=m;i++) printf("%d ",b[i]);
    nl;

    return 0;
}
