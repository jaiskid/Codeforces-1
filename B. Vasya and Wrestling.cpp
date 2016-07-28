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
LL a[200000],b[200000];
int main()
{
    LL first,second,ftech,stech,i,j,n,x,k,l;
    bool flast,slast,ffirst,sfirst;
    while(cin>>n)
    {
        first=second=ftech=stech=0;
        flast=slast=false;
        ffirst=sfirst=false;
        j=k=0;
        for(i=0; i<n; i++)
        {
            cin>>x;
            if(x<0)
            {
                x=x*(-1);
                second+=x;
                stech++;
                a[j++]=x;
                if(i==n-1)
                {
                    slast=true;
                }
            }
            else
            {
                first+=x;
                ftech++;
                b[k++]=x;
                if(i==n-1)
                {
                    flast=true;
                }
            }
        }
        if(first>second)
        {
            printf("first");
        }
        else if(second>first)
        {
            printf("second");
        }
        else
        {
            for(i=0; i<j; i++)
            {
                if(i==k)
                {
                    ffirst=true;
                    break;
                }
                if(a[i]>b[i])
                {
                    sfirst=true;
                    break;
                }
                else if(b[i]>a[i])
                {
                    ffirst=true;
                    break;
                }
            }
            if(!ffirst && !sfirst && k<j)
            {
                sfirst=true;
            }
            if((ffirst && ffirst!=sfirst))
            {
                printf("first");
            }
            else if((sfirst && ffirst!=sfirst))
            {
                printf("second");
            }
            else
            {
                if(flast)
                    printf("first");
                else
                    printf("second");
            }
        }
        nl;
    }
    return 0;
}
