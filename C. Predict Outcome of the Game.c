#include<stdio.h>
int main()
{
    long int n,k,r,d1,d2,t,team1,team2,team3,x;
    scanf("%ld",&t);
    while(t--)
    {
        scanf("%ld %ld %ld %ld",&n,&k,&d1,&d2);
        r=n-k;
        if(n%3==0)
        {
            if(r==0)
            {
                if(d1==d2)
                    printf("yes");
                else
                    printf("no");
            }
            else if(k==0)
            {
                printf("yes");
            }
            else
            {
                if(d1==d2)
                {
                    if(r%3==0 || r%2==0)
                        printf("yes");
                    else
                        printf("no");
                }
                else
                {
                    x=2*d1+d2;
                    if(r==x || ((r-x)%3==0 && x<=r))
                        printf("yes");
                    else
                        printf("no");
                }
            }
        }
        else
        {
            printf("no");
        }
        printf("\n");
    }
    return 0;
}
