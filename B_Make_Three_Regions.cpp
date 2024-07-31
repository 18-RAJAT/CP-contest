#include<bits/stdc++.h>
using namespace std;
#define int long long
int recur(vector<vector<char>>& grid,int r,int c)
{
    if(grid[r][c]!='.')return 0;
    int tog=r^1;
    return c-1>=1 && grid[tog][c-1]=='x' && grid[r][c-1]=='.' && c+1<grid[0].size() && grid[tog][c+1]=='x' && grid[r][c+1]=='.';
}
void sol()
{
    int n;
    cin>>n;
    vector<vector<char>>grid(2,vector<char>(n));
    int ans=0;
    for(auto& i:grid)
    {
        for(auto& j:i)cin>>j;
    }
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<n;++j)
        {
            if(recur(grid,i,j))ans++;
        }
    }
    cout<<ans<<endl;
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