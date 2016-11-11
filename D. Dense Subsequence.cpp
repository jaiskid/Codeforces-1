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
const long long int mx=3e5;
const long long int mod=1e9+7;
/* global declarations */

string outs;
char str[mx+5];
int sum[mx+5];
map<char,int>mp;
set<int>s;
set<int>::iterator it;

void build(int node, int beg, int end)
{
    if(beg==end)
    {
        sum[node]=1;
        return;
    }
    int mid=(beg+end)/2;
    int l=2*node;
    int r=2*node+1;
    build(l,beg,mid);
    build(r,mid+1,end);
    sum[node]=sum[l]+sum[r];
    return;
}

void update(int node, int beg, int end, int i)
{
    if(i>end || i<beg) return;
    if(beg==end)
    {
        sum[node]=0;
        return;
    }
    int mid=(beg+end)/2;
    int l=2*node;
    int r=2*node+1;
    update(l,beg,mid,i);
    update(r,mid+1,end,i);
    sum[node]=sum[l]+sum[r];
    return;
}

int query(int node, int beg, int end, int i, int j)
{
    if(i>end || j<beg) return 0;
    if(beg>=i && end<=j) return sum[node];
    int mid=(beg+end)/2;
    int l=2*node;
    int r=2*node+1;
    return query(l,beg,mid,i,j)+query(r,mid+1,end,i,j);
}

int main()
{
    int i,n,k,a,b,c,d;
    char ch;
    bool flag;
    while(scanf("%d %s",&k,str+1)!=EOF)
    {
        n=strlen(str+1);
        build(1,1,n);
        flag=true;
        for(i=1; i<=n; i++) mp[str[i]]++,s.insert(i);
        s.insert(0);
        s.insert(n+1);
        for(ch='z'; ch>='a'; ch--)
        {
            for(i=1; i<=n; i++)
            {
                if(str[i]!=ch) continue;
                if(i+k-1>n) a=n-k+1,b=n;
                else a=i,b=i+k-1;
                c=query(1,1,n,a,b);
                if(i-k+1<1) a=1,b=k;
                else a=i-k+1,b=i;
                d=query(1,1,n,a,b);
                it=s.find(i);
                it--;
                a=*it;
                it=s.find(i);
                it++;
                b=*it;
                if(c>1 && d>1 && b-a<=k)
                {
                    update(1,1,n,i);
                    mp[ch]--;
                    s.erase(s.find(i));
                }
                else
                {
                    flag=false;
                }
            }
            if(!flag) break;
        }
        outs="";
        for(i=0; i+'a'<=ch; i++)
        {
            while(mp[i+'a']>0)
            {
                outs+=(i+'a');
                mp[i+'a']--;
            }
        }
        pr1(outs);
    }

    return 0;
}
