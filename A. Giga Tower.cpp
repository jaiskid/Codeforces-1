#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
/* all c header files */

#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
#include<sstream>
/* all c++ header files */

#include<bits/stdc++.h>

/* all header files included */

#define pb(a) push_back(a)

/* defining macros */

using namespace std;

bool lucky(long long int n)
{
    if(n<0)
        n=n*(-1);
    while(n)
    {
        if(n%10==8)
            return true;
        n=n/10;
    }
    return false;
}

int main()
{
    long long int a,b,i;
    while(cin>>a)
    {
        for(i=1;i<=25;i++)
        {
            a=a+1;
            if(lucky(a))
            {
                break;
            }
        }
        cout<<i<<endl;
    }
    return 0;
}
