#include<stdio.h>
int main()
{
    int m,n,r;
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        r=(m*n)/2;
        printf("%d\n",r);
    }
    return 0;
}
