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

char ar[100][100];
long n,m,fl,fl1,tfl;
long lx,ly,rx,ry,qx,qy;

int main()
{
    ios_base::sync_with_stdio(0);

    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>ar[i][j];
    }

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            for (int i1=i; i1<=n; i1++)
            {
                for (int j1=1; j1<=m; j1++)
                {
                    if (ar[i][j]=='B' && ar[i1][j1]=='B')
                    {
                        lx=i;
                        rx=i1;
                        ly=j;
                        ry=j1;
                        fl=0;
                        fl1=0;
                        long dx,dy;

                        if (ry>ly)dy=1;
                        else dy=-1;

                        if (rx>lx)dx=1;
                        else dx=-1;

                        qx=lx;
                        qy=ly;

                        while (qx!=rx)
                        {
                            qx+=dx;
                            if (ar[qx][qy]=='W') fl=1;
                        }
                        while (qy!=ry)
                        {
                            qy+=dy;
                            if (ar[qx][qy]=='W') fl=1;
                        }

                        qx=lx;
                        qy=ly;
                        while (qy!=ry)
                        {
                            qy+=dy;
                            if (ar[qx][qy]=='W') fl1=1;
                        }
                        while (qx!=rx)
                        {
                            qx+=dx;
                            if (ar[qx][qy]=='W') fl1=1;
                        }

                        if (fl>0 && fl1>0)
                        {
                            tfl=1;
                            break;
                        }
                    }
                }
            }
        }
    }

    if (tfl) pr1("NO");
    else pr1("YES");

    cin.get();
    return 0;
}
