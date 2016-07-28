#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int a[10],i,count,count_1,count_2,x,b[6],j;
    for(i=0;i<10;i++)
            a[i]=b[i]=0;
    while(scanf("%d",&x)!=EOF)
    {
        a[x]++;
        for(i=1;i<6;i++)
        {
            scanf("%d",&x);
            a[x]++;
        }
        count=j=count_1=count_2=0;
        for(i=1; i<10; i++)
        {
            if(a[i]>=4)
            {
                count=1;
                x=a[i];
            }
            else if(a[i]>0 && a[i]<4)
            {
                b[j++]=a[i];
            }
        }
        if(count==0)
        {
            printf("Alien\n");
        }
        else
        {
            if(b[0]==2 || x==6)
                printf("Elephant\n");
            else
                printf("Bear\n");
        }
        for(i=0;i<10;i++)
            a[i]=b[i]=0;

    }
    return 0;
}
