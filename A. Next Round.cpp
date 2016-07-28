#include<stdio.h>
int main()
{
    int i,n,k,a[100],x,sum;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i==k-1)
                x=a[i];
        }
        sum=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>=x && a[i]>0)
                sum++;
        }
        printf("%d\n",sum);
    }
    return 0;
}
