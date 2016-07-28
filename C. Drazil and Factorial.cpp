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

vi factor;
int primes[10];

void factorial(string str)
{
    int i,j,x;

    for(i=0;i<str.size();i++)
    {
        x=str[i]-'0';
        for(j=2;j<=x;j++)
        {
            factor.pb(j);
        }
    }

    for(i=0;i<factor.size();i++)
    {
        x=factor[i];
        if(x==2 || x==3 || x==5 || x==7)
        {
            primes[x]++;
        }
        else if(x==4)
        {
            primes[2]+=2;
        }
        else if(x==6)
        {
            primes[2]++;
            primes[3]++;
        }
        else if(x==8)
        {
            primes[2]+=3;
        }
        else if(x==9)
        {
            primes[3]+=2;
        }
    }
}

string construct(int n, int a)
{
    string str;
    str="";
    for(int i=0;i<a;i++)
    {
        str+=n+48;
    }
    return str;
}

int main()
{
    int i,j,n;
    string inp,out;
    bool flag;

    cin>>n>>inp;
    factorial(inp);
    out="";
    if(primes[7])
    {
        out+=construct(7,primes[7]);
        primes[2]-=4*primes[7];
        primes[3]-=2*primes[7];
        primes[5]-=primes[7];
    }
    if(primes[5])
    {
        out+=construct(5,primes[5]);
        primes[2]-=3*primes[5];
        primes[3]-=primes[5];
    }
    if(primes[3])
    {
        out+=construct(3,primes[3]);
        primes[2]-=primes[3];
    }
    if(primes[2])
    {
        out+=construct(2,primes[2]);
    }
    pr1(out);
    return 0;
}
