#include<bits/stdc++.h>
using namespace std;
#define int long long
int grid[1005][1005];
int nums[100005];
void sol()
{
    int n;
    cin>>n;
    int cnt=0,val=0;

    for(int i=0;i<n;++i)
    {
        cin>>nums[i];
    }
    function<void(int,int)>dfs=[&](int i,int j)->void
    {
        if(j<0 || i>=n)
        {
            return;
        }
        if(grid[i][j] || !cnt)
        {
            return;
        }
        grid[i][j]=val,cnt--;
        dfs(i+1,j);
        dfs(i,j-1);
    };
    for(int j=n-1;j>=0;--j)
    {
        cnt=nums[j];
        val=nums[j];
        dfs(j,j);
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<=i;++j)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}