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

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

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
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
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
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declaration */

int main()
{
    int n,i,sum,cnt,qstn;
    string str,out;

    getline(cin,str);
    sum=1;
    i=2;
    qstn=1;
    while(str[i]!='=')
    {
        if(str[i]=='+') sum++;
        else if(str[i]=='-') sum--;
        qstn++;
        i+=4;
    }
    n=0;
    i+=2;
    while(i<str.size()) n=n*10+(str[i++]-'0');

    cnt=0;
    if(sum>n)
    {
        i=2;
        out+="1 ";
        while(i<str.size())
        {
            stringstream ss;
            string sss;
            cnt=sum-n;
            if(str[i]=='-')
            {
                if(sum>n)
                {
                    if(cnt>=n)
                    {
                        ss<<n;
                        ss>>sss;
                        sum-=n-1;
                    }
                    else
                    {
                        ss<<(cnt+1);
                        ss>>sss;
                        sum-=cnt;
                    }
                }
                else
                {
                    sss="1";
                }
                out+="- "+sss+" ";
                i+=4;
            }
            else if(str[i]=='+')
            {
                out+="+ 1 ";
                i+=4;
            }
            else if(str[i]=='=')
            {
                out+="= ";
                break;
            }
        }
    }
    else
    {
        i=2;
        out+="";
        stringstream one;
        string x;
        cnt=abs(n-sum);
        if(qstn>1)
        {
            if(cnt>=n)
            {
                one<<n;
                one>>x;
                sum+=n-1;
            }
            else if(cnt<n && cnt)
            {
                one<<cnt;
                one>>x;
                sum+=cnt-1;
            }
            else if(cnt==0)
            {
                x="1";
            }
        }
        else
        {
            one<<n;
            one>>x;
            sum=n;
        }
        out+=x+" ";

        while(i<str.size())
        {
            stringstream ss;
            string sss;
            cnt=abs(n-sum);
            if(str[i]=='+')
            {
                if(sum<n)
                {
                    if(cnt>=n)
                    {
                        ss<<n;
                        ss>>sss;
                        sum+=n-1;
                    }
                    else
                    {
                        ss<<(cnt+1);
                        ss>>sss;
                        sum+=cnt;
                    }
                }
                else
                {
                    sss="1";
                }
                out+="+ "+sss+" ";
                i+=4;
            }
            else if(str[i]=='-')
            {
                out+="- 1 ";
                i+=4;
            }
            else if(str[i]=='=')
            {
                out+="= ";
                break;
            }
        }
    }
    stringstream ss;
    string sss;
    ss<<n;
    ss>>sss;
    out+=sss;

    if(sum==n)
    {
        pr1("Possible");
        pr1(out);
    }
    else
    {
        pr1("Impossible");
    }

    return 0;
}
