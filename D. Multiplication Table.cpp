#include<cstdio>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
    int n,m,k,i,j;
    vector <int> x;
    while(scanf("%d %d %d",&n,&m,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                x.push_back(i*j);
            }
        }
        sort(x.begin(),x.end());
        printf("%d\n",x[k-1]);
        x.clear();
    }
    return 0;
}
