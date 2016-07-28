#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n,m,a[100],i,j,x,max;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        max=-1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            if(x%m==0)
            {
                a[i]=x/m;
            }
            else
            {
                a[i]=(x/m)+1;
            }
            if(a[i]>=max)
            {
                max=a[i];
                j=i;
            }
        }
        printf("%d\n",j+1);
    }
    return 0;
}
