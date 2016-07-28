#include<stdio.h>
#include<string.h>
int main()
{
    char a[101];
    int i,n,count;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",a);
        count=0;
        for(i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
                count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
