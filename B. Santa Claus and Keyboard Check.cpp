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
typedef pair<char, char>pcc;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
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

vi idx[26+5];
set<pcc>ss;
set<pcc>::iterator it;

int main()
{
    string s1,s2,s3;
    int i,j,x;
    bool flag;
    char ch,cc;
    map<char,bool>chck;
    cin>>s1>>s2;
    for(i=0; i<s1.size(); i++)
    {
        x=s1[i]-'a';
        idx[x].pb(i);
    }
    flag=true;
    s3=s2;
    for(ch='a'; ch<='z' && flag; ch++)
    {
        set<char>s;
        for(i=0; i<idx[ch-'a'].size(); i++)
        {
            x=idx[ch-'a'][i];
            s.insert(s2[x]);
        }
        if(s.size()>1) flag=false;
        if(s.size() && flag)
        {
            cc=*s.begin();
            for(i=0; i<s2.size(); i++)
            {
                if(s2[i]==cc) s3[i]=ch;
            }
            if(cc!=ch)
            {
                if(chck[cc]==chck[ch]) ss.insert(pcc(min(cc,ch),max(cc,ch)));
                else flag=false;
                chck[cc]=true;
                chck[ch]=true;
            }
        }
    }
    if(s3!=s1) flag=false;
    if(!flag)
    {
        pr1(-1);
    }
    else
    {
        x=ss.size();
        pr1(x);
        for(it=ss.begin(); it!=ss.end(); it++)
        {
            pr2(it->first,it->second);
        }
    }
    return 0;
}
