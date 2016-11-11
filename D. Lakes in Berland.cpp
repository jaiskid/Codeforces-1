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
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

char matrix[53][53];
bool visited[53][53];
bool dip[53][53];
int n, m, k;
void makeland(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(visited[i][j] || matrix[i][j] == '*')
        return;
    visited[i][j] = true;
    dip[i][j] = true;
    makeland(i + 1, j);
    makeland(i - 1, j);
    makeland(i, j + 1);
    makeland(i, j - 1);
}
void makelandnow(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return;
    if(visited[i][j] || matrix[i][j] == '*')
        return;
    visited[i][j] = true;
    matrix[i][j] = '*';
    makelandnow(i + 1, j);
    makelandnow(i - 1, j);
    makelandnow(i, j + 1);
    makelandnow(i, j - 1);
}
struct lakeinfo
{
    int i, j, cnt;
    lakeinfo()
    {
        i = -1, j = -1, cnt = 0;
    }
    lakeinfo(int ii, int jj, int cc)
    {
        i = ii;
        j = jj;
        cnt = cc;
    }
    bool operator < (const lakeinfo& L) const
    {
        return cnt < L.cnt;
    }
};
vector < lakeinfo > lakes;
int calc(int i, int j)
{
    if(i < 0 || i >= n || j < 0 || j >= m)
        return 0;
    if(visited[i][j] || matrix[i][j] == '*')
        return 0;
    visited[i][j] = true;
    int ret = 1;
    ret += calc(i + 1, j);
    ret += calc(i - 1, j);
    ret += calc(i, j + 1);
    ret += calc(i, j - 1);
    return ret;
}
int main()
{
    int i,j;
    cin >> n >> m >> k;
    setzero(dip);
    for(i=0; i<n; i++)
    {
        scanf("%s", matrix[i]);
    }
    for(i=0; i<n; i++)
    {
        setzero(visited);
        makeland(i, 0);
        setzero(visited);
        makeland(i, m - 1);
    }
    for(j=0; j<m; j++)
    {
        setzero(visited);
        makeland(0, j);
        setzero(visited);
        makeland(n - 1, j);
    }
    setzero(visited);
    for(int i = 1; i < n - 1; ++i)
    {
        for(int j = 1; j < m - 1; ++j)
        {
            if(dip[i][j])
                continue;
            int w = calc(i, j);
            if(w > 0)
            {
                lakes.pb(lakeinfo(i, j, w));
            }
        }
    }
    sort(lakes.begin(),lakes.end());
    int len = lakes.size();
    int ans = 0;
    int still = len - k;
    setzero(visited);
    for(int i = 0; i < len && still > 0; ++i, still--)
    {
        ans += lakes[i].cnt;
        makelandnow(lakes[i].i, lakes[i].j);
    }
    cout << ans << '\n';
    for(i=0; i<n; i++)
    {
        puts(matrix[i]);
    }
    puts("");
    return 0;
}
