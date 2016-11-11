/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <iostream>
#include <algorithm>
#include <vector>
/* all header files */

#define fs            first
#define sc            second
#define sp            printf(" ")
#define nl            printf("\n")
#define pb(a)         push_back(a)

#define setzero(a)    memset(a,0,sizeof(a))
#define setneg(a)     memset(a,-1,sizeof(a))
#define setinf(a)     memset(a,126,sizeof(a))

#define tc1(x)        printf("Case %d: ",x)
#define tc2(x)        printf("Case #%d: ",x)
#define tc3(x)        printf("Case %d:\n",x)
#define tc4(x)        printf("Case #%d:\n",x)

#define iin(x)        scanf("%d",&x)
#define din(x)        scanf("%lf",&x)
#define lin(x)        scanf("%lld",&x)
#define clin(x)       scanf("%I64d",&x)

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
/* macro definitions */

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
/* type definitions */

LL MOD_EXPO(LL b, LL p, LL m)
{
    if(p==0) return 1;
    LL ret=MOD_EXPO(b,p/2,m)%m;
    ret=(ret*ret)%m;
    return ((p&1) ? (ret*b)%m : ret%m);
}
LL POWER(LL N, LL K)
{
    LL i,ans=1;
    for(i=1; i<=K; i++) ans*=N;
    return ans;
}
int SET(int N, int pos)
{
    return (N | (1<<pos));
}
int RESET(int N, int pos)
{
    return (N & !(1<<pos));
}
bool CHECK(int N, int pos)
{
    return (N & (1<<pos));
}
/* necessary functions */

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx6[]= {0,0,1,-1,0,0};
int dy6[]= {1,-1,0,0,0,0};
int dz6[]= {0,0,0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction arrays */

int tc=1;
const double eps=1e-9;
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

int a1,b1,x1,y1;
int a2,b2,x2,y2;
int a3,b3,x3,y3;
int a4,b4,x4,y4;

bool isSquare()
{
    int A,B,C,D,E,F;
    A=((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2));
    B=((x1-x3)*(x1-x3))+((y1-y3)*(y1-y3));
    C=((x1-x4)*(x1-x4))+((y1-y4)*(y1-y4));
    D=((x2-x3)*(x2-x3))+((y2-y3)*(y2-y3));
    E=((x2-x4)*(x2-x4))+((y2-y4)*(y2-y4));
    F=((x3-x4)*(x3-x4))+((y3-y4)*(y3-y4));

    if(!A || !B || !C|| !D|| !E|| !F) return 0;

    if(C==B)
    {
        if(E==D && B==E && A==F) return 1;
        return 0;
    }
    else if(B==A)
    {
        if(E==F && A==E && C==D) return 1;
        return 0;
    }
    else if(C==A)
    {
        if(D==F && A==D && B==E) return 1;
        return 0;
    }
    return 0;

}
int rotatex(int x, int y, int a,int b)
{
    int sx,sy;
    sx=0-a;
    sy=0-b;
    x+=sx;
    y+=sy;
    x=-y;
    x-=sx;
    return x;
}

int rotatey(int x, int y, int a,int b)
{
    int sx,sy;
    sx=0-a;
    sy=0-b;
    x+=sx;
    y+=sy;
    y=x;
    y-=sy;
    return y;
}


int main()
{

    int i,j,k,l,t,N,M,a,b,c,x;
    cin>>t;
    while(t--)
    {
        cin>>x1>>y1>>a1>>b1;
        cin>>x2>>y2>>a2>>b2;
        cin>>x3>>y3>>a3>>b3;
        cin>>x4>>y4>>a4>>b4;

        int mn=100;

        for(i=0; i<4; i++)
        {
            for(j=0; j<4; j++)
            {
                for(k=0; k<4; k++)
                {
                    for(l=0; l<4; l++)
                    {
                        if(isSquare())
                        {
                            mn=min(mn,i+j+k+l);
                        }
                        x=x4;
                        x4=rotatex(x4,y4,a4,b4);
                        y4=rotatey(x,y4,a4,b4);
                    }
                    x=x3;
                    x3=rotatex(x3,y3,a3,b3);
                    y3=rotatey(x,y3,a3,b3);
                }
                x=x2;
                x2=rotatex(x2,y2,a2,b2);
                y2=rotatey(x,y2,a2,b2);
            }
            x=x1;
            x1=rotatex(x1,y1,a1,b1);
            y1=rotatey(x,y1,a1,b1);
        }
        if(mn==100) pr1(-1);
        else pr1(mn);
    }
    return 0;
}
