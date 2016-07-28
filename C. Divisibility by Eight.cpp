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

vi divisible,divisib;
void sieve(void)
{
    for(int i=16; i<=99; i+=8)
    {
        divisib.pb(i);
    }
    for(int i=104; i<=999; i+=8)
    {
        divisible.pb(i);
    }
}

int main()
{
    string str,s;
    int i,j,k,num,n,a,b,c;
    bool flag_a,flag_b,flag_c;
    sieve();
    while(cin>>str)
    {
        if(str.size()<3)
        {
            num=0;
            if(str.size()==1)
            {
                num=str[0]-48;
            }
            else
            {
                num=str[0]-48;
                num=(num*10)+str[1]-48;
            }
            if(num%8==0)
            {
                pr1("YES");
                pr1(num);
                return 0;
            }
        }
        for(i=0; i<str.size(); i++)
        {
            if(str[i]=='0')
            {
                pr1("YES");
                pr1(0);
                return 0;
            }
            if(str[i]=='8')
            {
                pr1("YES");
                pr1(8);
                return 0;
            }
        }
        for(i=0; i<divisib.size(); i++)
        {
            a=divisib[i];
            b=a%10;
            a=a/10;
            flag_a=flag_b=false;
            //pr1(divisible[i]);
            for(j=0; j<str.size(); j++)
            {
                n=str[j]-48;
                //pr1(n);
                if(!flag_a && n==a)
                {
                    flag_a=true;
                    //cout<<a;sp;
                }
                else if(flag_a && !flag_b && n==b)
                {
                    flag_b=true;
                    //cout<<b;sp;
                }
            }
            //pr3(flag_a,flag_b,flag_c);
            if(flag_a && flag_b)
            {
                pr1("YES");
                pr1(divisib[i]);
                return 0;
            }
        }
        for(i=0; i<divisible.size(); i++)
        {
            a=divisible[i];
            c=a%10;
            a=a/10;
            b=a%10;
            a=a/10;
            flag_a=flag_b=flag_c=false;
            //pr1(divisible[i]);
            for(j=0; j<str.size(); j++)
            {
                n=str[j]-48;
                //pr1(n);
                if(!flag_a && n==a)
                {
                    flag_a=true;
                    //cout<<a;sp;
                }
                else if(flag_a && !flag_b && n==b)
                {
                    flag_b=true;
                    //cout<<b;sp;
                }
                else if(flag_a && flag_b && !flag_c && n==c)
                {
                    flag_c=true;
                    //cout<<c;sp;
                }
            }
            //pr3(flag_a,flag_b,flag_c);
            if(flag_a && flag_b && flag_c)
            {
                pr1("YES");
                pr1(divisible[i]);
                return 0;
            }
        }
        pr1("NO");
    }
    return 0;
}
