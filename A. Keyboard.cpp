#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
char L(char c)
{
    if(c=='q')
        c='w';
    else if(c=='w')
        c='e';
    else if(c=='e')
        c='r';
    else if(c=='r')
        c='t';
    else if(c=='t')
        c='y';
    else if(c=='y')
        c='u';
    else if(c=='u')
        c='i';
    else if(c=='i')
        c='o';
    else if(c=='o')
        c='p';
    else if(c=='a')
        c='s';
    else if(c=='s')
        c='d';
    else if(c=='d')
        c='f';
    else if(c=='f')
        c='g';
    else if(c=='g')
        c='h';
    else if(c=='h')
        c='j';
    else if(c=='j')
        c='k';
    else if(c=='k')
        c='l';
    else if(c=='l')
        c=';';
    else if(c=='z')
        c='x';
    else if(c=='x')
        c='c';
    else if(c=='c')
        c='v';
    else if(c=='v')
        c='b';
    else if(c=='b')
        c='n';
    else if(c=='n')
        c='m';
    else if(c=='m')
        c=',';
    else if(c==',')
        c='.';
    else if(c=='.')
        c='/';
    else if(c=='p')
        c='[';
    else if(c==';')
        c='\'';

    return c;
}
char R(char c)
{
    if(c=='q')
        c='\t';
    else if(c=='w')
        c='q';
    else if(c=='e')
        c='w';
    else if(c=='r')
        c='e';
    else if(c=='t')
        c='r';
    else if(c=='y')
        c='t';
    else if(c=='u')
        c='y';
    else if(c=='i')
        c='u';
    else if(c=='o')
        c='i';
    else if(c=='s')
        c='a';
    else if(c=='d')
        c='s';
    else if(c=='f')
        c='d';
    else if(c=='g')
        c='f';
    else if(c=='h')
        c='g';
    else if(c=='j')
        c='h';
    else if(c=='k')
        c='j';
    else if(c=='l')
        c='k';
    else if(c=='x')
        c='z';
    else if(c=='c')
        c='x';
    else if(c=='v')
        c='c';
    else if(c=='b')
        c='v';
    else if(c=='n')
        c='b';
    else if(c=='m')
        c='n';
    else if(c==',')
        c='m';
    else if(c=='.')
        c=',';
    else if(c=='p')
        c='o';
    else if(c==';')
        c='l';
    else if(c=='/')
        c='.';

    return c;
}
int main()
{
    int i,j,n;
    char ch, str[101];
    while(cin>>ch)
    {
        scanf("%s",str);
        n=strlen(str);
        for(i=0;i<n;i++)
        {
            if(ch=='L')
                str[i]=L(str[i]);
            else
                str[i]=R(str[i]);
            printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
