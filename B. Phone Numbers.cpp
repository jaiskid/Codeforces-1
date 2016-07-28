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

struct friends
{
    int taxi;
    int pizza;
    int girl;
};

bool istaxi(string str)
{
    int i;
    for(i=0; i<str.size(); i++)
    {
        if(str[i]=='-')
            continue;
        if(str[i]!=str[0])
            return false;
    }
    return true;
}

bool ispizza(string str)
{
    int i,last,x;
    map<int,int>mp;

    for(i=0;i<str.size();i++)
    {
        if(str[i]=='-')
            continue;
        if(mp[str[i]])
            return false;
        x=str[i]-48;
        if(i && x>=last)
            return false;
        last=x;

    }
    return true;
}

int main()
{
    int n,i,s,j,max_taxi,max_pizza,max_girl;
    friends x[101];
    string str;
    bool flag;
    while(cin>>n)
    {
        map<int,string>mp2;
        max_taxi=max_pizza=max_girl=0;
        for(i=1; i<=n; i++)
        {
            cin>>s>>str;
            mp2[i]=str;
            x[i].taxi=x[i].pizza=x[i].girl=0;
            for(j=1; j<=s; j++)
            {
                cin>>str;
                if(istaxi(str))
                    x[i].taxi++;
                else if(ispizza(str))
                    x[i].pizza++;
                else
                    x[i].girl++;
            }
            if(x[i].taxi>max_taxi)
                max_taxi=x[i].taxi;
            if(x[i].pizza>max_pizza)
                max_pizza=x[i].pizza;
            if(x[i].girl>max_girl)
                max_girl=x[i].girl;
        }
        flag=false;
        cout<<"If you want to call a taxi, you should call:";
        for(i=1; i<=n; i++)
        {
            if(x[i].taxi==max_taxi)
            {
                if(flag)
                    cout<<",";
                cout<<" "<<mp2[i];
                flag=true;
            }
        }
        pr1(".");
        flag=false;
        cout<<"If you want to order a pizza, you should call:";
        for(i=1; i<=n; i++)
        {
            if(x[i].pizza==max_pizza)
            {
                if(flag)
                    cout<<",";
                cout<<" "<<mp2[i];
                flag=true;
            }
        }
        pr1(".");
        flag=false;
        cout<<"If you want to go to a cafe with a wonderful girl, you should call:";
        for(i=1; i<=n; i++)
        {
            if(x[i].girl==max_girl)
            {
                if(flag)
                    cout<<",";
                cout<<" "<<mp2[i];
                flag=true;
            }
        }
        pr1(".");
    }
    return 0;
}
