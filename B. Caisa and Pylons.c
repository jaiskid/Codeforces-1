#include<stdio.h>
#include<math.h>
int main()
{
    int n,h[100000],max,sum,i;
    while(scanf("%d",&n)!=EOF)
    {
        max=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&h[i]);
            if(h[i]>max)
                max=h[i];
        }
            printf("%d\n",max);
    }
    return 0;
}
