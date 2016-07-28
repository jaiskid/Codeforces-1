/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
/* all header files included */

#define mod         1000000007
#define pi          acos(-1.0)
#define eps         1e-9

#define fs          first
#define sc          second
#define pb(a)       push_back(a)
#define mp(a,b)     make_pair(a,b)
#define sp          printf(" ")
#define nl          printf("\n")

#define set0(a)     memset(a,0,sizeof(a))
#define setneg(a)   memset(a,-1,sizeof(a))
#define setinf(a)   memset(a,126,sizeof(a))

#define tc1(x)      printf("Case %d: ",x)
#define tc2(x)      printf("Case #%d: ",x)
#define tc3(x)      printf("Case %d:\n",x)
#define tc4(x)      printf("Case #%d:\n",x)

#define pr1(x)      cout<<x<<"\n"
#define pr2(x,y)    cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z)  cout<<x<<" "<<y<<" "<<z<<"\n"
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
template <class T> inline T _sqrt(T a)
{
    return (T)sqrt((double)a);
}
template <class T, class X> inline T _pow(T a, X b)
{
    T res=1;
    for(int i=1; i<=b; i++)
        res*=a;
    return res;
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
const long long int mx=100000;
/* global declaration */

int main()
{
    int i,n,s_capital[26],s_small[26],t_capital[26],t_small[26],yay,whoops,x;
    string s,t;
    while(cin>>s>>t)
    {
        for(i=0;i<26;i++)
        {
            s_capital[i]=s_small[i]=t_capital[i]=t_small[i]=0;
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]>='A' && s[i]<='Z')
                s_capital[s[i]-'A']++;
            else if(s[i]>='a' && s[i]<='z')
                s_small[s[i]-'a']++;
        }
        for(i=0;i<t.size();i++)
        {
            if(t[i]>='A' && t[i]<='Z')
                t_capital[t[i]-'A']++;
            else if(t[i]>='a' && t[i]<='z')
                t_small[t[i]-'a']++;
        }
        yay=whoops=0;
        for(i=0;i<26;i++)
        {
            if(s_small[i])
            {
                x=min(s_small[i],t_small[i]);
                yay+=x;
                s_small[i]=s_small[i]-x;
                t_small[i]=t_small[i]-x;
            }
            if(s_capital[i])
            {
                x=min(s_capital[i],t_capital[i]);
                yay+=x;
                s_capital[i]=s_capital[i]-x;
                t_capital[i]=t_capital[i]-x;
            }
        }
        for(i=0;i<26;i++)
        {
            if(s_small[i] && !t_small[i] && t_capital[i])
            {
                x=min(s_small[i],t_capital[i]);
                whoops+=x;
                s_small[i]=s_small[i]-x;
                t_capital[i]=t_capital[i]-x;
            }
            if(s_capital[i] && !t_capital[i] && t_small[i])
            {
                x=min(s_capital[i],t_small[i]);
                whoops+=x;
                s_capital[i]=s_capital[i]-x;
                t_small[i]=t_small[i]-x;
            }
        }
        pr2(yay,whoops);
    }
    return 0;
}

