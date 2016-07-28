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
    int n,m,a[100],b[100],i,j,count,x;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(a,a+n);
        sort(b,b+m);
        count=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                x=fabs(a[i]-b[j]);
                if(x>1 && b[j]>a[i])
                    break;
                else if(x<2 && b[j]>0)
                {
                    count++;
                    b[j]=0;
                    break;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
