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

bool check(string str)
{
    int i;
    for(i=0;i<10;i++)
    {
        if((i==2 || i==5) && (str[i]!='-')) return false;
        if(i!=2 && i!=5 && !isdigit(str[i])) return false;
    }
    return true;
}

int stoi(string str)
{
    int i,n=0;
    for(i=0;i<str.size();i++) n=n*10+str[i]-'0';
    return n;
}

int main()
{
    string str,ss,ans;
    char arr[mx+5];
    int i,cnt=0,dd,mm,yy;
    map<string,int>mp;
    int month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

    scanf("%s",arr);
    str=arr;
    for(i=0;i<=str.size()-9;i++)
    {
        if(str[i]!='-')
        {
            ss=str.substr(i,10);
            if(check(ss))
            {
                dd=stoi(ss.substr(0,2));
                mm=stoi(ss.substr(3,2));
                yy=stoi(ss.substr(6,4));
                if(yy>=2013 && yy<=2015 && mm>=1 && mm<=12 && dd>=1 && dd<=month[mm]) mp[ss]++;
                if(mp[ss]>cnt)
                {
                    cnt=mp[ss];
                    ans=ss;
                }
            }
        }
    }
    pr1(ans);
    return 0;
}
