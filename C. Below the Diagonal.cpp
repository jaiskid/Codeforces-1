/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <bits/stdc++.h>
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
typedef pair<int, int>pii;
typedef pair<LL, LL>pll;
typedef vector<int>vi;
typedef vector<LL>vll;
typedef vector<pii>vpii;
typedef vector<pll>vpll;
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
const double pi=acos(-1.0);
const long long int mx=1e5;
const long long int mod=1e9+7;
/* global declarations */

vector<int>vc[1001];
vector<pair<int,pair<int,int> > >vv;
int on[1001];
int col[1001];

int main()
{
    int a,b,c,d,e,f,g,h,x,y,z;
    cin>>a;
    for(x=2; x<=a; x++)
    {
        cin>>b>>c;
        vc[b].push_back(c);
        col[c]++;
    }
    memset(on,0,sizeof on);
    for(x=a; x>=1; x--)
    {
        d=0;
        e=0;
        for(y=1; y<=x; y++)
        {
            if(vc[y].size()>d)
            {
                d=vc[y].size();
                e=y;
            }
        }
        swap(vc[e],vc[x]);
        if(vc[x].size()!=0 && x!=e)vv.push_back(make_pair(1,make_pair(x,e)));
    }
    b=0;
    for(x=2; x<=a; x++)
    {
        if(vc[x].size()==0) continue;
        for(y=0; y<vc[x].size(); y++)
        {
            d=0;
            e=-1;
            for(z=y; z<vc[x].size(); z++)
            {
                if(on[vc[x][y]]==0 && col[vc[x][z]]>d)
                {
                    d=col[vc[x][z]];
                    e=z;
                }
            }
            if(e==-1) continue;
            swap(vc[x][y],vc[x][e]);
            if(b+1!=vc[x][y] && on[vc[x][y]]==0)
            {
                vv.push_back(make_pair(2,make_pair(b+1,vc[x][y])));
                on[b+1]=1;
                f=vc[x][y];
                for(z=x; z<=a; z++)
                {
                    for(h=0; h<vc[z].size(); h++)
                    {
                        if(vc[z][h]==f)
                        {
                            vc[z][h]=b+1;
                            col[b+1]++;
                            col[f]--;
                        }
                        else if(vc[z][h]==b+1)
                        {
                            vc[z][h]=f;
                            col[f]++;
                            col[b+1]--;
                        }
                    }
                }
                b++;
            }
            else if(b+1==vc[x][y])
            {
                on[b+1]=1;
                b++;
            }
        }
    }
    cout<<vv.size()<<endl;
    for(x=0; x<vv.size(); x++) cout<<vv[x].fs<<" "<<vv[x].sc.fs<<" "<<vv[x].sc.sc<<endl;
    return 0;
}
