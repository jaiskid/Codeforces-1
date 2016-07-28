#include<stdio.h>
int main()
{
    int n,i,x[100],y[100],max,a;
    double total,s;
    while(scanf("%d %lf",&n,&s)!=EOF)
    {
        max=a=0;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            total=((x[i]*100.00)+y[i])/100.00;
            if(total<=s)
            {
                if(y[i]>max)
                    max=y[i];
                a=1;
            }
        }
        if(max==0 && a==1)
            printf("0\n");
        else if(max==0 && a==0)
            printf("-1\n",max);
        else if(max>0 && a==1)
        {
            max=0;
            for(i=0;i<n;i++)
            {
                if(x[i]<s && y[i]>0 && 100-y[i]>max)
                    max=100-y[i];
            }
            printf("%d\n",max);
        }
    }
    return 0;
}
