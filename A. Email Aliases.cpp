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
const long long int mx=20000;
const long long int mod=1000000007;
/* global declaration */

string process(string str)
{
    string login,sample,domain;
    int i;

    i=0;
    sample=login=domain="";
    while(str[i]!='@' && i<str.size())
    {
        sample+=str[i];
        i++;
    }
    i++;
    while(i<str.size())
    {
        domain+=str[i];
        i++;
    }

    for(i=0; i<sample.size(); i++) sample[i]=tolower(sample[i]);
    for(i=0; i<domain.size(); i++) domain[i]=tolower(domain[i]);

    login="";
    if(domain=="bmail.com")
    {
        for(i=0; i<sample.size(); i++)
        {
            if(sample[i]=='.') continue;
            if(sample[i]=='+') break;
            login+=sample[i];
        }
    }
    else
    {
        login=sample;
    }
    return login+"@"+domain;
}

map<string,int>mp;
vector<string> vs[mx+5];

int main()
{
    int i,n,j,ass;
    string str,ss;
    while(cin>>n)
    {
        ass=0;
        for(i=1; i<=n; i++)
        {
            cin>>str;
            ss=process(str);
            if(mp[ss]==0) mp[ss]=++ass;
            j=mp[ss];
            vs[j].pb(str);
        }
        pr1(ass);
        for(i=0; i<=mx; i++)
        {
            if(vs[i].size()==0) continue;
            cout<<vs[i].size();
            for(j=0; j<vs[i].size(); j++)
            {
                sp;cout<<vs[i][j];
            }
            nl;
            vs[i].clear();
        }
        mp.clear();
    }
    return 0;
}
