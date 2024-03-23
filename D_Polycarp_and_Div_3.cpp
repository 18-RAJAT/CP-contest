#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int ans=0;
    array<bool,3>dp={false,false,false};
    auto state=[&]()
    {
        dp[0]=dp[1]=dp[2]=false;
    };
    for(auto& it:s)
    {
        int val=(it-'0')%3;
        if(val%3==0)
        {
            state();
            ans++;
        }
        else
        {
            if(dp[3-val]==true)
            {
                state();
                ans++;
            }
            else
            {
                vector<int>ndp;
                for(int i=1;i<=2;++i)
                {
                    if(dp[i])
                    {
                        ndp.push_back((i+val)%3);
                    }
                }
                for(int i=0;i<ndp.size();++i)
                {
                    dp[ndp[i]]=true;
                }
                dp[val]=true;
            }
        }
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}