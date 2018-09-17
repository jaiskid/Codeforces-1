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
const long long int mx=1e2;
const long long int mod=1e9+7;
/* global declarations */

int arr[mx+5][mx+5];
int bal[mx+5][mx+5];
int n,m;

bool check_zero(void)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            if(arr[i][j]) return false;
        }
    }
    return true;
}

string to_str(int val)
{
    stringstream ss;
    string str;
    ss<<val;
    ss>>str;
    return str;
}

vector<string> check_row(void)
{
    int i,j,val;
    vector<string>output;
    if(!check_zero())
    {
        for(i=1; i<=n; i++)
        {
            val = INT_MAX;
            for(j=1; j<=m; j++) val=min(val,arr[i][j]);
            for(j=1; j<=m; j++) arr[i][j]-=val;
            for(j=1; j<=val; j++)
            {
                string str = to_str(i);
                output.push_back("row " + str);
            }
        }
    }
    return output;
}

vector<string> check_col(void)
{
    int i,j,val;
    vector<string>output;
    if(!check_zero())
    {
        for(i=1; i<=m; i++)
        {
            val = INT_MAX;
            for(j=1; j<=n; j++) val=min(val,arr[j][i]);
            for(j=1; j<=n; j++) arr[j][i]-=val;
            for(j=1; j<=val; j++)
            {
                string str = to_str(i);
                output.push_back("col " + str);
            }
        }
    }
    return output;
}

void putit(void)
{
    int i,j;
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=m; j++)
        {
            arr[i][j]=bal[i][j];
        }
    }
    return;
}

int main()
{
    int i,j,val;
    while(cin>>n>>m)
    {
        vector<string>output,outrow,outcol,temp1,temp2;
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=m; j++)
            {
                iin(arr[i][j]);
                bal[i][j]=arr[i][j];
            }
        }
        temp1 = check_row();
        temp2 = check_col();
        if(check_zero())
        {
            for(i=0; i<temp1.size(); i++) outrow.push_back(temp1[i]);
            for(i=0; i<temp2.size(); i++) outrow.push_back(temp2[i]);
        }

        putit();

        temp1 = check_col();
        temp2 = check_row();
        if(check_zero())
        {
            for(i=0; i<temp1.size(); i++) outcol.push_back(temp1[i]);
            for(i=0; i<temp2.size(); i++) outcol.push_back(temp2[i]);
        }

        putit();

        if(outrow.size() or outcol.size() or check_zero())
        {
            if(outrow.size() <= outcol.size()) output = outrow;
            if(outcol.size() <= outrow.size()) output = outcol;
            pr1(output.size());
            for(i=0; i<output.size(); i++) printf("%s\n",output[i].c_str());
        }
        else
        {
            pr1(-1);
        }
    }
    return 0;
}
