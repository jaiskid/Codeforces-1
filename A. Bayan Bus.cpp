#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int k,count,row,i,x,j,pass;
    char ch;
    while(cin>>k)
    {
        row=(k-4)/3;
        row++;
        if((k-4)%3!=0)
            row++;
        pass=0;
        printf("+------------------------+\n");
        for(i=1; i<=4; i++)
        {
            if(i==3)
            {
                printf("|");
                if(k>2)
                {
                    printf("O.");
                    pass++;
                }
                else if(k<=2)
                {
                    printf("#.");
                }
                printf("......................|\n");
                continue;
            }
            for(j=1; j<=11; j++)
            {
                if(j==1)
                {
                    printf("|");
                    if(pass<k)
                    {
                        printf("O.");
                        pass++;
                    }
                    else
                    {
                        printf("#.");
                    }
                    continue;
                }
                if(j==row)
                {
                    x=(k-4)%3;
                    if(x==1 && i==1)
                    {
                        printf("O.");
                        pass++;
                        //cout<<pass;
                    }
                    else if(x==2 && i<=2)
                    {
                        printf("O.");
                        pass++;
                    }
                    else if(x==0 && i<=4)
                    {
                        printf("O.");
                        pass++;
                    }
                    else
                        printf("#.");
                }
                else if(j<row)
                {
                    printf("O.");
                    pass++;
                    //cout<<pass;
                }
                else
                    printf("#.");
            }
            if(i==1)
            {
                printf("|D|)");
            }
            else if(i==2)
            {
                printf("|.|");
            }
            else
            {
                printf("|.|)");
            }
            printf("\n");
        }
        printf("+------------------------+\n");
    }
    return 0;
}
