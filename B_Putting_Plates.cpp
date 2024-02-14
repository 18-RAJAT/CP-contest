#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    int grid[n][m];
    fill(&grid[0][0],&grid[0][0]+n*m,0);
    for(int i=0;i<m;i+=2)
    {
        grid[0][i]=1;
        grid[n-1][i]=1;
    }
    for(int i=2;i<n;i+=2)
    {
        for(int j=0;j<m;j+=2)
        {
            if(i+1<n && grid[i+1][0]==0)
            {
                grid[i][0]=1;
                grid[i][m-1]=1;
            }
        }
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}