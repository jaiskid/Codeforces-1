#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,x,a,j;
    char s[100][101];
    while(scanf("%d",&n)!=EOF)
    {
        a=0;
        for(i=0;i<n;i++)
        {
            scanf("%s",s[i]);
        }
        for(i=0;i<n;i++)
        {
            x=0;
            for(j=0;j<n;j++)
            {
                if(s[i-1][j]=='o' && i>0)
                    x++;
                if(s[i][j-1]=='o' && j>0)
                    x++;
                if(s[i][j+1]=='o' && j<n-1)
                    x++;
                if(s[i+1][j]=='o' && i<n-1)
                    x++;
                if(x%2!=0)
                    a=1;
            }
        }
        if(a==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
