#include<stdio.h>
#include<math.h>
int main()
{
    int n,m,x;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n<m)
        {
            x=n;
        }
        else
        {
            x=m;
        }
        if(x%2==0)
        {
            printf("Malvika\n");
        }
        else
        {
            printf("Akshat\n");
        }
    }
    return 0;
}
