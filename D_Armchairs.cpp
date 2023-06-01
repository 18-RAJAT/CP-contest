#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>ar(50001);
    for(auto&it:ar)
    {
        cin>>it;
    }
    vector<int>dp(n+1,0);
    for(int i=0;i<n;++i)
    {
        if(ar[i]==0)
        {
            continue;
        }
        vector<int>dp2(n+1,10000001);
        for(int j=1;j<n+1;++j)
        {
            if(ar[j-1]!=1)
            {
                dp2[j]=dp[j-1]+abs(i-(j-1));
            }
            // else
            // {
            //     dp2[j]=dp[j-1];
            // }
            dp2[j]=min(dp2[j],dp2[j-1]);
        }
        swap(dp,dp2);
    }
    cout<<*min_element(dp.begin(),dp.end());
}