#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>>dp(n,vector<char>(m));//matrix(grid)
    // vector<vector<char>>ndp(n+1,vector<char>(m+1,'.'));
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cin>>dp[i][j];
        }
    }
    vector<char>matrix(n);
    vector<int>row(n,0),col(m,0);
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(dp[i][j]=='L' || dp[i][j]=='R')
            {
                col[j]++;
            }
            if(dp[i][j]=='U' || dp[i][j]=='D')
            {
                row[i]++;
            }
        }
    }
    int dir1=1;
    // int dir2=1;
    // int dir3=1;
    // int dir4=1;
    for(int i=0;i<n;++i)
    {
        // if(row[i]==0)
        // {
        //     dir1++;
        // }
        if(row[i]%2) dir1=0;
        // else if(row[i]==m)
        // {
        //     dir2++;
        // }
        row[i]=0;
    }
    for(int i=0;i<m;++i)
    {
        // if(col[i]==0)
        // {
        //     dir3++;
        // }
        if(col[i]%2)dir1=0;
        // else if(col[i]==n)
        // {
        //     dir4++;
        // }
        col[i]=0;
    }
    if(dir1==0)
    {
        cout<<"-1\n";
        return;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            //this case check for the last row
            if(dp[i][j]=='L')
            {
                if(col[j]==0)
                {
                    dp[i][j]='W';
                    dp[i][j+1]='B';
                    col[j]=1;
                }
                else
                {
                    dp[i][j]='B';
                    dp[i][j+1]='W';
                    col[j]=0;
                }
            }
            //this case check for the last column
            if(dp[i][j]=='U')
            {
                if(row[i]==0)
                {
                    dp[i][j]='W';
                    dp[i+1][j]='B';
                    row[i]=1;
                }
                else
                {
                    dp[i][j]='B';
                    dp[i+1][j]='W';
                    row[i]=0;
                }
            }
        }
    }
    // for(int i=0;i<n;++i)
    // {
    //     for(int j=0;j<m;++j)
    //     {
    //         if(dp[i][j]=='L')
    //         {
    //             if(col[i]==0)
    //             {
    //                 dp[i][j]='W';
    //                 dp[i][j+1]='B';
    //                 col[j]=1;
    //             }
    //             else
    //             {
    //                 dp[i][j]='B';
    //                 dp[i][j+1]='W';
    //                 col[j]=0;
    //             }
    //         }
    //     }
    // }
    // cout<<dp.size()<<" "<<dp[0].size()<<endl;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            cout<<dp[i][j];
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