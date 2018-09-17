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

struct fountain
{
    int beauty,cost;
};

bool operator<(fountain A, fountain B)
{
    return A.cost<B.cost;
}

vector<fountain>store[2];
int n,c,d,n1,n2;
int table[2][20][mx+5];

void build_table(void)
{
    int i,j,x,y;
    for(i=0; i<n1; i++) table[0][0][i]=store[0][i].beauty;
    for(i=0; i<n2; i++) table[1][0][i]=store[1][i].beauty;

    for(i=1; (1<<i)<n1; i++)
    {
        for(j=0; j+(1<<i)-1<n1; j++)
        {
            x=table[0][i-1][j];
            y=table[0][i-1][j+(1<<(i-1))];
            table[0][i][j]=max(x,y);
        }
    }
    for(i=1; (1<<i)<n2; i++)
    {
        for(j=0; j+(1<<i)-1<n2; j++)
        {
            x=table[1][i-1][j];
            y=table[1][i-1][j+(1<<(i-1))];
            table[1][i][j]=max(x,y);
        }
    }
}

int get_length(int x)
{
    int ans;
    ans=0;
    while(x>1)
    {
        ans++;
        x/=2;
    }
    return ans;
}

int query(int l, int r, int idx)
{
    if(l>r) return INT_MIN;
    int k=get_length(r-l);
    int x=table[idx][k][l];
    int y=table[idx][k][r-(1<<k)+1];
    return max(x,y);
}

int BS(int val, int low, int high, int idx)
{
    int mid,ans;
    ans=-1;
    while(low<=high)
    {
        mid=(high+low)/2;
        if(store[idx][mid].cost<=val)
        {
            ans=mid;
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    return ans;
}

int main()
{
    int i,ans,b,x;
    char str[10+5];
    fountain tmp;
    cin>>n>>c>>d;
    for(i=0; i<n; i++)
    {
        scanf("%d %d %s",&b,&x,str);
        tmp.cost=x;
        tmp.beauty=b;
        if(x<=c and str[0]=='C') store[0].push_back(tmp);
        if(x<=d and str[0]=='D') store[1].push_back(tmp);
    }
    sort(store[0].begin(),store[0].end());
    sort(store[1].begin(),store[1].end());

    ans=0;
    n1=store[0].size();
    n2=store[1].size();

    build_table();

    if(n1 and n2)
    {
        ans=max(ans,query(0,n1-1,0)+query(0,n2-1,1));
    }
    if(n1>1)
    {
        for(i=0; i<n1; i++)
        {
            x=BS(c-store[0][i].cost,i+1,n1-1,0);
            ans=max(ans,store[0][i].beauty+query(i+1,x,0));
        }
    }
    if(n2>1)
    {
        for(i=0; i<n2; i++)
        {
            x=BS(d-store[1][i].cost,i+1,n2-1,1);
            ans=max(ans,store[1][i].beauty+query(i+1,x,1));
        }
    }
    pr1(ans);
    return 0;
}
