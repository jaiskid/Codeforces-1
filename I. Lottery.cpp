#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,a[100+3],b,n,m,k,c;
    while(cin>>n>>k)
    {
        m=n/k;
        for(i=1;i<=100;i++) a[i]=0;
        for(i=1;i<=n;i++){
            cin>>b;
            a[b]++;
        }
        c=0;
        for(i=1;i<=k;i++)
        {
            if(a[i]<m)
            {
                c+=(m-a[i]);
            }
        }
        cout<<c<<endl;
    }
    return 0;
}
