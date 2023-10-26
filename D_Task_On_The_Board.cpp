#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    int dp[26];
    memset(dp,0,sizeof(dp));
    auto convert=[&](char c)->int
    {
        return c-'a';
    };
    for(int i=0;i<n;++i)
    {
        dp[convert(s[i])]++;
    }
    int m;
    cin>>m;
    int b[m];
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    int ndp[m];
    memset(ndp,0,sizeof(ndp));
    int last_element=25;
    while(dp[last_element]==0)
    {
        last_element--;
    }
    char ans[m];
    for(int i=0;i<n;++i)
    {
        if(b[i]==0)
        {
            // ans[i]=last_element+'a';
            // dp[last_element]--;
            ans[i]=last_element;//+'a';
            // ans[i]+='a';
            // last_element--;
            // while(dp[last_element]==0)
            // {
            //     last_element--;
            // }
            // ndp[i]=last_element;
            ndp[i]=1;
        }
    }
    int precompute[m];
    memset(precompute,0,sizeof(precompute));
    while(true)
    {
        for(int i=0;i<m;++i)
        {
            if(ndp[i]==1)
            {
                precompute[i]=-1;
            }
            else
            {
                int sum=0;
                for(int j=0;j<m;++j)
                {
                    if(ndp[j]==1)
                    {
                        sum+=abs<int>(i-j);
                    }
                }
                precompute[i]=sum;
            }
        }
        int count=0;
        for(int i=0;i<m;++i)
        {
            if(b[i]==precompute[i])
            {
                count++;
            }
            last_element--;
            while(dp[last_element]==0)
            {
                last_element--;
            }
            // while(ndp[i]==1)
            // {
            //     i++;
            // }

            
            //changing the value of ndp[i] to last_element by using the fact that ndp[i] is 0 and ndp[i+1] is 0
            // int &val=ndp[i],&val2=ndp[i+1],&val3=ndp[i+2],&val4=ndp[i+3],&val5=ndp[i+4];
            // if(~val && ~val2 && ~val3 && ~val4 && ~val5)
            // {
            //     val=last_element;
            //     val2=last_element;
            //     val3=last_element;
            //     val4=last_element;
            //     val5=last_element;
            // }

            int vals_count=0;
            for(int i=0;i<m;++i)
            {
                // if(ndp[i]==1)
                // {
                //     vals_count++;
                // }
                if(b[i]==precompute[i])
                {
                    // vals_count++;
                    ans[i]=last_element;
                    ndp[i]=1;
                }
                //for the case when b[i]==precompute[i] and ndp[i]==1 then we have to check for the next value of i
                // else if(dp[last_element]==dp[i] && ndp[i]==0)
                // {
                //     ans[i]=last_element;
                //     ndp[i]=1;
                // }
                else if(ndp[i]==0)
                {
                    vals_count++;
                }
            }
            if(vals_count==0)
            {
                break;
            }
        }
    }
        // for(int i=0;i<m;++i)
        // {
        //     cout<<ans[i]-'a';
        // }
        // cout<<"\n";
    for(int i=0;i<m;++i)
    {
        cout<<ans[i]-'a';
    }
    cout<<"\n";
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