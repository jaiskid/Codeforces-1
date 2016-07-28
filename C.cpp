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

int dx4[]={1,-1,0,0};
int dy4[]={0,0,1,-1};
int dx8[]={1,-1,0,0,-1,1,-1,1};
int dy8[]={0,0,1,-1,1,1,-1,-1};
int dkx8[]={-1,1,-1,1,-2,-2,2,2};
int dky8[]={2,2,-2,-2,1,-1,1,-1};
/* direction array */

class grade
{
public:
    LL a,b;
    grade(LL x, LL y)
    {
        a=x;
        b=y;
    }
    grade()
    {

    }
};
bool operator<(grade A, grade B)
{
    return A.b<B.b;
}
int main()
{
    LL i,j,k;
    LL n,r,avg,total,need,got,essay;
    grade obj[100000];
    while(cin>>n>>r>>avg)
    {
        total=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld %lld",&obj[i].a,&obj[i].b);
            total+=obj[i].a;
        }
        need=(avg*n)-total;
        if(need>0)
        {
            j=n;
            sort(obj,obj+j);
            essay=0;
            i=0;
            while(i<n)
            {
                if(need>=(r-obj[i].a))
                {
                    need-=(r-obj[i].a);
                    essay+=(r-obj[i].a)*(obj[i].b);
                }
                else if(need>0)
                {
                    essay+=need*obj[i].b;
                    need=0;
                }
                else
                    break;
                i++;
            }
            printf("%lld",essay);
        }
        else
        {
            cout<<"0";
        }
        nl;
    }
    return 0;
}
