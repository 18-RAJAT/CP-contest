#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<vector<int>>dp(26,vector<int>(26,0));
    vector<int>pref(26,0);
    for(int i=n-1;~i;--i)
    {
        pref[s[i]-'a']++;
        for(int j=0;j<26;++j)
        {
            dp[s[i]-'a'][j]+=pref[j];
        }
    }
    int q;
    cin>>q;
    while(q--)
    {
        char a,b;
        cin>>a>>b;
        cout<<dp[a-'a'][b-'a']<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}