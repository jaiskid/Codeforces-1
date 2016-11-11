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
const long long int mx=100;
const long long int mod=1e9+7;
/* global declarations */

bool x[mx+5];

string to_lower(string str)
{
    int i;
    for(i=0; i<str.size(); i++)
    {
        if(str[i]>='A' && str[i]<='Z') str[i]+=32;
    }
    return str;
}

char to_lower(char str)
{
    if(str>='A' && str<='Z') str+=32;
    return str;
}

char match_case(char ch1, char ch2)
{
    if(ch1>='A' && ch1<='Z') ch2-=32;
    return ch2;
}

int main()
{
    int i,j,k,n;
    char ch;
    string str,subss;
    while(cin>>n)
    {
        vector<string>vs;
        for(i=0; i<n; i++)
        {
            cin>>str;
            vs.pb(str);
        }
        cin>>str>>ch;
        setzero(x);
        for(i=0; i<n; i++)
        {
            for(j=0; j<str.size()-vs[i].size()+1 && str.size()>=vs[i].size(); j++)
            {
                subss=str.substr(j,vs[i].size());
                if(to_lower(subss)==to_lower(vs[i]))
                {
                    for(k=j; k<j+vs[i].size(); k++) x[k]=true;
                }
            }
        }
        for(i=0; i<str.size(); i++)
        {
            if(x[i])
            {
                if(to_lower(str[i])==ch && ch!='a') str[i]=match_case(str[i],'a');
                else if(to_lower(str[i])==ch && ch=='a') str[i]=match_case(str[i],'b');
                else if(to_lower(str[i])!=ch) str[i]=match_case(str[i],ch);
            }
        }
        pr1(str);
    }
    return 0;
}
