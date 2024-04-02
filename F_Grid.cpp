#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int grid[21][21];
    for(int i=0;i<21;++i)
    {
        string s;
        cin>>s;
        for(int j=0;j<21;++j)
        {
            grid[i][j]=s[j]-'0';
        }
    }
    int Maximum=INT_MIN;
    for(int i=0;i<=17;++i)
    {
        for(int j=0;j<=17;++j)
        {
            int Sum=0;
            for(int k=i;k<i+4;++k)
            {
                for(int l=j;l<j+4;++l)
                {
                    Sum+=grid[k][l];
                }
            }
            Maximum=max(Maximum,Sum);
        }
    }
    cout<<Maximum<<endl;
}
signed main()
{
    sol();
    return 0;
}