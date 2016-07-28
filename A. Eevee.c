#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,a;
    char s[10];
    while(scanf("%d %s",&n,s)!=EOF)
    {
        if(n==6)
        {
            printf("espeon");
        }
        else if(n==8)
        {
            printf("vaporeon");
        }
        else
        {
            if(s[1]=='l')
            {
                if(s[0]=='f' || s[3]=='r')
                {
                    printf("flareon");
                }
                else
                {
                    printf("glaceon");
                }
            }
            else if(s[2]=='a')
            {
                if(s[0]=='l' || s[1]=='e' || s[3]=='f')
                {
                    printf("leafeon");
                }
                else if(s[0]=='g' || s[1]=='l' || s[3]=='c')
                {
                    printf("glaceon");
                }
                else
                {
                    printf("flareon");
                }
            }
            else if(s[2]=='l')
            {
                if(s[0]=='j' || s[1]=='o' || s[3]=='t')
                {
                    printf("jolteon");
                }
                else
                {
                    printf("sylveon");
                }
            }
            else if(s[3]=='r')
            {
                if(s[0]=='f' || s[1]=='l' || s[2]=='a')
                {
                    printf("flareon");
                }
                else
                {
                    printf("umbreon");
                }
            }
            else if(s[0]=='j' || s[1]=='o' || s[2]=='l' || s[3]=='t')
            {
                printf("jolteon");
            }
            else if(s[0]=='s' || s[1]=='y' || s[2]=='l' || s[3]=='v')
            {
                printf("sylveon");
            }
            else if(s[0]=='u' || s[1]=='m' || s[2]=='b' || s[3]=='r')
            {
                printf("umbreon");
            }
            else if(s[0]=='f' || s[1]=='l' || s[2]=='a' || s[3]=='r')
            {
                printf("flareon");
            }
            else if(s[0]=='g' || s[1]=='l' || s[2]=='a' || s[3]=='c')
            {
                printf("glaceon");
            }
            else if(s[0]=='l' || s[1]=='e' || s[2]=='a' || s[3]=='f')
            {
                printf("leafeon");
            }
        }
        printf("\n");
    }
    return 0;
}
