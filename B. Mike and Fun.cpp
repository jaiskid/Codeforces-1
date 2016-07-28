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
const long long int mx=500;
/* global declaration */

int main()
{
    int n,m,q,max_score,new_max,a[mx+5][mx+5],i,j,b[mx+5];
    bool flag,res;
    while(scanf("%d %d %d",&n,&m,&q)!=EOF)
    {
        max_score=0;
        for(i=1; i<=n; i++)
        {
            new_max=0;
            max_score=0;
            flag=false;
            for(j=1; j<=m; j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j])
                    flag=true;
                if(a[i][j] && a[i][j-1]==a[i][j] && j>1)
                    new_max++;
                else
                {
                    if(new_max>max_score)
                        max_score=new_max;
                    new_max=0;
                }
                if(j==m)
                {
                    if(new_max>max_score)
                        max_score=new_max;
                }
            }
            if(flag)
                b[i]=max_score+1;
            else
                b[i]=0;
        }
        while(q--)
        {
            scanf("%d %d",&i,&j);
            if(a[i][j])
            {
                a[i][j]=0;
            }
            else
            {
                a[i][j]=1;
            }
            max_score=0;
            new_max=0;
            flag=false;
            res=false;
            for(j=1; j<=m; j++)
            {
                // cout<<a[i][j];
                if(a[i][j])
                    flag=true;
                if(!a[i][j])
                    res=true;
                if(a[i][j] && a[i][j-1]==a[i][j] && j>1)
                    new_max++;
                else
                {
                    if(new_max>max_score)
                        max_score=new_max;
                    new_max=0;
                }
                if(j==m)
                {
                    if(new_max>max_score)
                        max_score=new_max;
                }
            }
            if(flag && res)
                b[i]=max_score+1;
            else if(flag && !res)
                b[i]=m;
            else if(!flag && res)
                b[i]=0;
            max_score=0;
            for(i=1; i<=n; i++)
            {
                //cout<<b[i];
               // sp;
                if(b[i]>max_score)
                    max_score=b[i];
            }
            printf("%d\n",max_score);
        }
    }
    return 0;
}
