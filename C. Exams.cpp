#include<iostream>
#include<algorithm>
#include<cstdio>
#include<utility>
#define x first
#define y second
using namespace std;
int main()
{
    long int max,i,n,x,y;
    pair<long int, long int>p[5000];
    while(cin>>n)
    {
        for(i=0;i<n;i++)
        {
            scanf(" %ld %ld",&p[i].x,&p[i].y);
        }
        sort(p,p+n);
        max=0;
        for(i=0;i<n;i++)
        {
            if(p[i].y>=max)
                max=p[i].y;
            else
                max=p[i].x;
        }
        cout<<max<<endl;
    }
    return 0;
}
