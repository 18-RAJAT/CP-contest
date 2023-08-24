#include<bits/stdc++.h>
using namespace std;
#define int long long
void recur(vector<string>&grid,int& ans,int count,int n,int m,int i,int j)
{
    if(i==n || j==m)
    {
        return;
    }
    if(grid[i][j]=='*')
    {
        count++;
    }
    ans=max<int>(ans,count);
    int R=n,C=m;
    for(int row=i;row<n;++row)
    {
        for(int col=j;col<m;++col)
        {
            if(grid[row][col]=='*')
            {
                // R=min<int>(R,row);
                // C=min<int>(C,col);
                if(row!=i || col!=j)
                {
                    if(grid[row][col]=='*')
                    {
                        if(row-i+col-j<R-i+C-j)
                        {
                            R=row;
                            C=col;
                        }
                    }
                }
                // R=0,C=0;
            }
        }
    }
    // if(k==0)
    // {
    //     recur(grid,ans,count,n,m,i+1,j,1);
    // }
    // else
    // {
    //     recur(grid,ans,count,n,m,i,j+1,0);
    // }
    recur(grid,ans,count,n,m,R,C);
    // else
    // {
    //     recur(grid,ans,count,n,m,i-1,j,0);
    //     recur(grid,ans,count,n,m,i,j-1,1);
    // }
    // cout<<ans<<" "<<count<<" "<<i<<" "<<j<<"\n";
}
signed main()
{
    int n,m;
    cin>>n>>m;
    vector<string> grid(n);
    for(int i=0;i<n;++i)
    {
        cin>>grid[i];
    }
    // recur(grid,ans,count,n,m,0,0,0);
    int ans=0;
    recur(grid,ans,0,n,m,0,0);
    // recur(grid,ans,count,n,m,0,0,1);
    // if(ans==2)
    // {
    //     cout<<1<<"\n";
    //     return 0;
    // }
    cout<<ans<<"\n";
    return 0;
}