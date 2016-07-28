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
const long long int mx=5e5;
const long long int mod=1e9+7;
/* global declaration */

int pairs[mx+5],lefts[mx+5],rights[mx+5];
bool del[mx+5];
char seq[mx+5];
char str[mx+5];

int main()
{
    int n,m,p,i,j,k;
    while(scanf("%d %d %d",&n,&m,&p)!=EOF)
    {
        scanf("%s %s",str+1,seq+1);
        stack<int>st;

        for(i=1; i<=n; i++)
        {
            del[i]=1;
            lefts[i]=i-1;
            rights[i]=i+1;
            if(i==1) lefts[i]=-1;
            if(i==n) rights[i]=-1;
            if(str[i]=='(')
            {
                st.push(i);
            }
            else
            {
                k=st.top();
                st.pop();
                pairs[i]=k;
                pairs[k]=i;
            }
        }
        for(i=1; i<=m; i++)
        {
            if(seq[i]=='L')
            {
                p=lefts[p];
            }
            else if(seq[i]=='R')
            {
                p=rights[p];
            }
            else
            {
                del[p]=0;
                del[pairs[p]]=0;
                j=p;
                k=pairs[p];
                if(j>k) swap(j,k);

                if(rights[k]==-1)
                {
                    p=lefts[j];
                    rights[p]=-1;
                }
                else
                {
                    p=rights[k];
                    if(lefts[j]==-1)
                    {
                        lefts[p]=-1;
                    }
                    else
                    {
                        lefts[p]=lefts[j];
                        rights[lefts[j]]=p;
                    }
                }
            }
        }
        for(i=1; i<=n; i++)
        {
            if(del[i]) printf("%c",str[i]);
            else if(!del[i] && i<pairs[i]) i=pairs[i];
        }
        nl;
    }
    return 0;
}
