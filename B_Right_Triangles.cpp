#include<bits/stdc++.h>
using namespace std;
#define int long long
char dp[1005][1005];
int row[1005][1005],col[1005][1005];
void sol()
{
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>dp[i][j];
        }
    }
    //for every row we will store the number of '*' before the current index
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            row[i][j]=row[i][j-1]+(dp[i][j]=='*');
        }
    }
    //vice versa for column
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
        {
            col[i][j]=col[i-1][j]+(dp[i][j]=='*');
        }
    }
    int ans=0;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            if(dp[i][j]=='*')
            {
                int dir1=row[i][m]-row[i][j];//left
                int dir2=row[i][j-1];//right
                int dir3=col[i-1][j];//down
                int dir4=col[n][j]-col[i][j];//up

                ans+=dir1*dir3;//left down
                ans+=dir1*dir4;//left up
                ans+=dir2*dir3;//right down
                ans+=dir2*dir4;//right up
            }
        }
    }
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}