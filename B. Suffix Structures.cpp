#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    char s[101],t[101];
    int n1,n2,i,j,x1[26],x2[26],a,temp,count;
    while(scanf("%s %s",s,t)!=EOF)
    {
        for(i=0;i<26;i++)
        {
            x1[i]=x2[i]=0;
        }
        n1=strlen(s);
        n2=strlen(t);
        a=0;
        if(n1<n2)
        {
            printf("need tree");
        }
        else if(n1==n2)
        {
            for(i=0;i<n1;i++)
            {
                j=s[i]-97;
                x1[j]++;
                j=t[i]-97;
                x2[j]++;
            }
            for(i=0;i<26;i++)
            {
                if(x2[i]>0 && x2[i]>x1[i])
                {
                    a=1;
                    break;
                }
            }
            if(a==0)
            {
                printf("array");
            }
            else
            {
                printf("need tree");
            }
        }
        else
        {
            for(i=0;i<n1;i++)
            {
                j=s[i]-97;
                x1[j]++;
            }
            for(i=0;i<n2;i++)
            {
                j=t[i]-97;
                x2[j]++;
            }
            for(i=0;i<26;i++)
            {
                if(x2[i]>0 && x2[i]>x1[i])
                {
                    a=1;
                    break;
                }
            }
            if(a==1)
            {
                printf("need tree");
            }
            else
            {
                temp=-1;
                count=0;
                for(i=0;i<n2;i++)
                {
                    for(j=temp+1;j<n1;j++)
                    {
                        if(t[i]==s[j])
                        {
                            temp=j;
                            count++;
                            break;
                        }
                    }
                }
                if(count==n2)
                {
                    printf("automaton");
                }
                else if(count<n2)
                {
                    printf("both");
                }
            }
        }
        printf("\n");
    }
    return 0;
}
