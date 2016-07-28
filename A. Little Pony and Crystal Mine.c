#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main()
{
    int n,i,j,k,a,b,c;
    while(scanf("%d",&n)!=EOF)
    {
        a=n/2;
        b=n-a;
        c=b;
        for(i=1;i<=n/2;i++)
        {
            for(j=1;j<=n;j++)
            {
                if(j>=b && j<=c)
                    printf("D");
                else
                    printf("*");
            }
            printf("\n");
            b--;
            c++;
        }
        for(j=1;j<=n;j++)
            printf("D");

        printf("\n");

        for(i=1;i<=n/2;i++)
        {
            b++;
            c--;
            for(j=1;j<=n;j++)
            {
                if(j>=b && j<=c)
                    printf("D");
                else
                    printf("*");
            }
            printf("\n");

        }
    }
    return 0;
}
