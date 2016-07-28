#include<cstdio>
#include<cmath>
#include<cctype>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<utility>
using namespace std;
int main()
{
    long long int n;
    while(scanf("%lld",&n)!=EOF)
    {
        if(n%2==0)
        {
            printf("%lld\n",n/2);
        }
        else
        {
            printf("%lld\n",((n-1)/2)-n);
        }
    }
    return 0;
}
