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
const long long int mx=100000;
const long long int mod=1000000007;
/* global declaration */

int inversion(vector<string> lesha, vector<string> ss)
{
    int a,b,c,d,inv=0,best=100;
    if(ss.size()==4)
    {
        for(a=0; a<ss.size(); a++)
        {
            for(b=0; b<ss.size(); b++)
            {
                for(c=0; c<ss.size(); c++)
                {
                    for(d=0; d<ss.size(); d++)
                    {
                        if(ss[a]==lesha[0] && ss[b]==lesha[1] && ss[c]==lesha[2] && ss[d]==lesha[3])
                        {
                            inv=0;
                            if(a>b) inv++;
                            if(a>c) inv++;
                            if(a>d) inv++;
                            if(b>c) inv++;
                            if(b>d) inv++;
                            if(c>d) inv++;
                            best=min(best,inv);
                        }
                    }

                }

            }
        }
        return best;
    }
    if(ss.size()==3)
    {
        for(a=0; a<ss.size(); a++)
        {
            for(b=0; b<ss.size(); b++)
            {
                for(c=0; c<ss.size(); c++)
                {
                    if(ss[a]==lesha[0] && ss[b]==lesha[1] && ss[c]==lesha[2])
                    {
                        inv=0;
                        if(a>b) inv++;
                        if(a>c) inv++;
                        if(b>c) inv++;
                        best=min(best,inv);
                    }
                }

            }
        }
        return best;
    }
    if(ss.size()==2)
    {
        for(a=0; a<ss.size(); a++)
        {
            for(b=0; b<ss.size(); b++)
            {
                if(ss[a]==lesha[0] && ss[b]==lesha[1])
                {
                    inv=0;
                    if(a>b) inv++;
                    best=min(best,inv);
                }
            }
        }
        return best;
    }
    return 0;
}

int main()
{
    int i,j,k,n,m,x,p,cur,N,idx;
    while(cin>>n)
    {
        vector<string>lesha;
        map<string,bool>mp;
        string ss,str;
        for(i=0; i<n; i++)
        {
            cin>>str;
            lesha.pb(str);
            mp[str]=true;
        }
        cin>>m;
        x=INT_MAX;
        for(i=0; i<m; i++)
        {
            cin>>k;
            vector<string>problems;
            for(j=0; j<k; j++)
            {
                cin>>str;
                problems.pb(str);
            }
            N=problems.size();
            for(j=0; j<(1<<N); j++)
            {
                if(__builtin_popcount(j)!=n) continue;
                map<string,bool>mpp;
                vector<string>ss;
                for(k=0; k<N; k++)
                {
                    if(j & (1<<k))
                    {
                        if(!mp[problems[k]] || mpp[problems[k]]) break;
                        else mpp[problems[k]]=true,ss.pb(problems[k]);
                    }
                }
                if(k<N) continue;
                cur=inversion(lesha,ss);
                if(cur<x)
                {
                    x=cur;
                    idx=i+1;
                }
            }
        }
        p=(n*(n-1)/2)-x+1;
        if(x==INT_MAX)
        {
            pr1("Brand new problem!");
        }
        else
        {
            pr1(idx);
            printf("[:");
            for(i=0; i<p; i++) printf("|");
            printf(":]");
            nl;
        }
    }
    return 0;
}
