#include<stdio.h>
int main()
{
    int n,i,a[3],count,solve,j;
    while(scanf("%d",&n)!=EOF)
    {
        solve=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d %d",&a[0],&a[1],&a[2]);
            count=0;
            for(j=0;j<3;j++)
            {
                if(a[j]==1)
                    count++;
            }
            if(count>=2)
                solve++;
        }
        printf("%d\n",solve);
    }
    return 0;
}
