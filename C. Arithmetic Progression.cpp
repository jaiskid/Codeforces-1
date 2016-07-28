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

int main()
{
    int x[mx+5],n,a,b,ans,idx,i,k;
    while(cin>>n)
    {
        map<int,int>mp;
        map<int,int>::iterator it;
        for(i=0; i<n; i++) scanf("%d",&x[i]);

        sort(x,x+n);
        for(i=1; i<n; i++)
        {
            k=x[i]-x[i-1];
            mp[k]++;
        }
        if(mp.size()>2)
        {
            ans=0;
        }
        else if(mp.size()==2)
        {
            it=mp.begin();
            a=it->fs;
            it++;
            b=it->fs;
            if(a<b && a*2==b && mp[a]==n-2 && mp[b]==1) ans=1;
            else if(a>b && b*2==a && mp[b]==n-2 && mp[a]==1) ans=1;
            else ans=0;
        }
        else
        {
            ans=mp.size()*2;
            it=mp.begin();
            a=it->fs;
            b=a;
            if(a==0) ans--;
        }

        if(n==1)
        {
            ans=-1;
        }
        else if(n==2)
        {
            it=mp.begin();
            a=it->fs;
            if(a && a%2==0) ans++;
        }

        pr1(ans);
        if(ans==1)
        {
            a=min(a,b);
            for(i=1; i<n; i++)
            {
                if(x[i]-x[i-1]==2*a)
                {
                    pr1(x[i-1]+a);
                    break;
                }
            }
        }
        else if(ans==2)
        {
            it=mp.begin();
            a=it->fs;
            pr2(x[0]-a,x[n-1]+a);
        }
        else if(ans==3)
        {
            it=mp.begin();
            a=it->fs;
            pr3(x[0]-a,x[0]+a/2,x[1]+a);
        }
    }
    return 0;
}
