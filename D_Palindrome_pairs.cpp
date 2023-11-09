#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2005][2005],cache_check[2005][2005],ndp[2005][2005];
string s;
bool palindrome(int i=0,int j=0)
{
    if(i>j)
    {
        return true;
    }
    int &ret=dp[i][j];
    if(~ret)
    {
        return ret;
    }
    int &check=ndp[i][j];
    int &ans=cache_check[i][j];
    if(check)
    {
        return ans;
    }
    check=1;
    if(s[i]!=s[j])
    {
        // return ret=false;
        return ans=false;
    }
    // return ret=palindrome(i+1,j-1);
    return ans=palindrome(i+1,j-1);
}

void sol()
{
    cin>>s;
    vector<pair<int,int>>hash;
    int pref[s.size()];
    memset(pref,0,sizeof(pref));
    memset(&dp[0][0],-1,sizeof(dp));

    int pairs=0;
    for(int i=0;i<s.size();++i)
    {
        for(int j=i;j<s.size();++j)
        {
            if(palindrome(i,j))
            {
                // hash.push_back(make_pair(i,j));
                pairs++;
                // pref[i]++;
            }
            // pref[i]=hash.size();//for each i, we have the number of palindromes ending at i
            pref[i]=pairs;
        }
    }
    int ans=0;
    for(int i=0;i<s.size();++i)
    {
        for(int j=i;j<s.size();++j)
        {
            if(palindrome(i,j) && j!=s.size()-1)
            {
                // ans+=(hash.size()-pref[j]);
                ans+=(pairs-pref[j]);
            }
        }
    }
    // for(int i=0;i<s.size();++i)
    // {
    //     for(int j=i;j<s.size();++j)
    //     {
    //         if(palindrome(i,j))
    //         {
    //             ans++;
    //         }
    //     }
    // }
    assert(~(dp[0][0]^cache_check[0][0] && dp[0][0]&cache_check[0][0]));
    cout<<ans;
}
signed main()
{
    sol();
    return 0;
}