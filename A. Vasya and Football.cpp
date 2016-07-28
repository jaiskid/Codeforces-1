/* -------------------------------- */
/* Name: MD. Khairul Basar          */
/* Institute: HSTU                  */
/* Dept: CSE                        */
/* Email: khairul.basar93@gmail.com */
/* -------------------------------- */

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <utility>
#include <sstream>
#include <algorithm>

#include <bits/stdc++.h>
/* all header files included */

#define LL long long
#define pii pair<int,int>

#define mod 1000000007
#define pi acos(-1.0)

#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)

#define sp printf(" ")
#define nl printf("\n")

#define tc1(x) printf("Case %d: ",x)
#define tc2(x) printf("Case #%d: ",x)

#define pr1(x) cout<<x<<"\n"
#define pr2(x,y) cout<<x<<" "<<y<<"\n"
#define pr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<"\n"
/* defining macros */

using namespace std;

int dx4[]= {1,-1,0,0};
int dy4[]= {0,0,1,-1};
int dx8[]= {1,-1,0,0,-1,1,-1,1};
int dy8[]= {0,0,1,-1,1,1,-1,-1};
int dkx8[]= {-1,1,-1,1,-2,-2,2,2};
int dky8[]= {2,2,-2,-2,1,-1,1,-1};
/* direction array */

int main()
{
    string home,away;
    int h[101],a[101],i,j,k,n,x,y;
    char c,d;
    while(cin>>home>>away)
    {
        for(i=0; i<101; i++)
        {
            h[i]=a[i]=0;
        }
        cin>>n;
        for(i=0; i<n; i++)
        {
            cin>>x>>c>>y>>d;
            if(c=='h')
            {
                if(d=='y')
                {
                    h[y]++;
                    if(h[y]==2)
                    {
                        h[y]=4;
                        cout<<home;
                        sp;
                        cout<<y;
                        sp;
                        cout<<x;
                        nl;
                    }
                }
                else
                {
                    h[y]+=2;
                    if(h[y]<=3)
                    {
                        h[y]=4;
                        cout<<home;
                        sp;
                        cout<<y;
                        sp;
                        cout<<x;
                        nl;
                    }
                }
            }
            else
            {
                if(d=='y')
                {
                    a[y]++;
                    if(a[y]==2)
                    {
                        a[y]=4;
                        cout<<away;
                        sp;
                        cout<<y;
                        sp;
                        cout<<x;
                        nl;
                    }
                }
                else
                {
                    a[y]+=2;
                    if(a[y]<=3)
                    {
                        a[y]=4;
                        cout<<away;
                        sp;
                        cout<<y;
                        sp;
                        cout<<x;
                        nl;
                    }
                }
            }
        }
    }
    return 0;
}
