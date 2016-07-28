#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,i,x[10],a,b,c,j;
    while(cin>>a>>b>>c)
    {
        x[0]=a+b+c;
        x[1]=a*b*c;
        x[2]=a+(b*c);
        x[3]=(a+b)*c;
        x[4]=a*(b+c);
        x[5]=(a*b)+c;
        x[6]=a+b*c;
        x[7]=a*b+c;
        n=0;
        j=8;
        for(i=0;i<j;i++)
        {
            if(x[i]>n)
            {
                n=x[i];
            }
        }
        cout<<n<<endl;
    }
    return 0;
}
