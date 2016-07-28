#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str1[1001],str2[1001];
    int i,n,j;
    while(scanf("%s",str1)!=EOF)
    {
        for(i=0;i<1001;i++)
        {
            str2[i]='\0';
        }
        n=strlen(str1);
        j=0;
        for(i=0;i<n;i++)
        {
            if(str1[i]=='A' || str1[i]=='E' || str1[i]=='I' || str1[i]=='O' || str1[i]=='U' || str1[i]=='Y')
                continue;
            else if(str1[i]=='a' || str1[i]=='e' || str1[i]=='i' || str1[i]=='o' || str1[i]=='u' || str1[i]=='y')
                continue;
            else
            {
                str2[j++]='.';
                str2[j++]=tolower(str1[i]);
            }
        }
        printf("%s\n",str2);
    }
    return 0;
}
