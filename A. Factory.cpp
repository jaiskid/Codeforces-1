#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{
    int a,x,m,i;
    bool res;
    while(scanf("%d %d",&a,&m)!=EOF)
    {
        res=false;
        for(i=0;i<=20;i++)
        {
            x=a*pow(2,i);
            if(x%m==0)
            {
                res=true;
                break;
            }
        }
        if(res)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
