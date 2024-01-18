#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    vector<vector<array<int,3>>>dp(n+4,vector<array<int,3>>(3,{0,0,0}));
    int ans=0;
    for(auto& it:a)
    {
        cin>>it;
        //dp[i][j][k] denotes the number of subsequences of length i ending at index j with k as the last element
        (dp[it][2][0]+=dp[it][2][0]+dp[it+2][0][0])%=1000000007;
        //vice versa
        (dp[it][2][1]+=dp[it][2][1]+dp[it+2][0][1])%=1000000007;
        (dp[it][2][2]+=dp[it][2][2]+dp[it+2][0][2])%=1000000007;
        if(it==0)
        {
            (dp[0][1][0]+=1+dp[0][1][0])%=1000000007;
            (dp[0][1][1]+=dp[0][1][1])%=1000000007;
            (dp[0][1][2]+=dp[0][1][2])%=1000000007;
        }
        else if(it==1)
        {
            //dp[1][1][0] denotes the number of subsequences of length 1 ending at index 1 with 0 as the last element
            (dp[1][1][0]+=dp[0][1][0]+dp[1][1][0])%=1000000007;
            //vice versa
            (dp[1][1][1]+=dp[0][1][1]+dp[1][1][1])%=1000000007;
            (dp[1][1][2]+=dp[0][1][2]+dp[1][1][2])%=1000000007;
            (dp[1][0][0]+=1+dp[1][0][0])%=1000000007;
            (dp[1][0][1]+=dp[1][0][1])%=1000000007;
            (dp[1][0][2]+=dp[1][0][2])%=1000000007;
        }
        else if(it==2)
        {
            //dp[2][1][0] denotes the number of subsequences of length 2 ending at index 2 with 0 as the last element
            (dp[2][1][0]+=dp[1][1][0]+dp[2][1][0])%=1000000007;
            //vice versa
            (dp[2][1][1]+=dp[1][1][1]+dp[2][1][1])%=1000000007;
            (dp[2][1][2]+=dp[1][1][2]+dp[2][1][2])%=1000000007;
            (dp[2][0][0]+=dp[1][0][0]+dp[2][0][0])%=1000000007;
            (dp[2][0][1]+=dp[2][0][1])%=1000000007;
            (dp[2][0][2]+=dp[2][0][2])%=1000000007;
        }
        else if(it==3)
        {
            //dp[3][1][0] denotes the number of subsequences of length 3 ending at index 3 with 0 as the last element
            (dp[3][1][0]+=dp[2][1][0]+dp[3][1][0])%=1000000007;
            //vice versa
            (dp[3][1][1]+=dp[2][1][1]+dp[3][1][1])%=1000000007;
            (dp[3][1][2]+=dp[2][1][2]+dp[3][1][2])%=1000000007;
            (dp[3][0][0]+=dp[2][0][0]+dp[3][0][0])%=1000000007;
            (dp[3][0][1]+=dp[2][0][1]+dp[3][0][1])%=1000000007;
            (dp[3][0][2]+=dp[3][0][2])%=1000000007;
        }
        else
        {
            //dp[it][0][0] denotes the number of subsequences of length it ending at index it with 0 as the last element
            (dp[it][0][0]+=dp[it-2][1][0]+dp[it][0][0])%=1000000007;
            //vice versa
            (dp[it][0][1]+=dp[it-2][1][1]+dp[it][0][1])%=1000000007;
            (dp[it][0][2]+=dp[it-2][1][2]+dp[it][0][2])%=1000000007;
            (dp[it][1][0]+=dp[it-1][1][0]+dp[it][1][0])%=1000000007;
            (dp[it][1][1]+=dp[it-1][1][1]+dp[it][1][1])%=1000000007;
            (dp[it][1][2]+=dp[it-1][1][2]+dp[it][1][2])%=1000000007;
        }
        // cout<<"dp["<<it<<"][0][0] = "<<dp[it][0][0]<<"\n";
        // cout<<"dp["<<it<<"][0][1] = "<<dp[it][0][1]<<"\n";
        // cout<<"dp["<<it<<"][0][2] = "<<dp[it][0][2]<<"\n";
    }
    for(int i=0;i<=n;++i)
    {
        //for computing the answer we need to add all the possible combinations of the dp array elements for each index
        (ans+=dp[i][0][0]+dp[i][0][1]+dp[i][0][2]+dp[i][1][0]+dp[i][1][1]+dp[i][1][2]+dp[i][2][0]+dp[i][2][1]+dp[i][2][2])%=1000000007;
    }
    cout<<((ans==3)?ans+1:ans)<<endl;
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