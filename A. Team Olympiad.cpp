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

int main()
{
    int i,j,n,x,prog[5001],math[5001],phys[5001],w,p,m,e;
    while(cin>>n)
    {
        p=m=e=0;
        for(i=1;i<=n;i++)
        {
            cin>>x;
            if(x==1)
            {
                prog[p++]=i;
            }
            else if(x==2)
            {
                math[m++]=i;
            }
            else if(x==3)
            {
                phys[e++]=i;
            }
        }
        w=10000;
        if(p && m && e)
        {
            if(p<w)
                w=p;
            if(m<w)
                w=m;
            if(e<w)
                w=e;
            printf("%d\n",w);
            for(i=0;i<w;i++)
            {
                printf("%d %d %d\n",prog[i],math[i],phys[i]);
            }
        }
        else
        {
            printf("0\n");
        }
    }
    return 0;
}

