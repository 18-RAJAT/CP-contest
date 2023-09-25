#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[200005];
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    // sort(s.begin(),s.end());
    vector<int>arr;
    for(int i=0;i<n;++i)
    {
        if(s[i]!=s[i-1] || i==0)
        {
            arr.push_back(0);
        }
        arr.back()++;
    }
    int cnt1=0,cnt2=1;
    for(auto& it:arr)
    {
        if(it>=2)
        {
            cnt1+=it-1;
            cnt2*=it;
            cnt1%=998244353;
            cnt2%=998244353;
        }
    }
    int calc=cnt2*dp[cnt1]%998244353;
    cout<<cnt1%998244353<<" "<<calc%998244353<<"\n";
}
void chk()
{
    dp[0]=1;
    for(int i=1;i<200005;++i)
    {
        dp[i]=(dp[i-1]*i)%998244353;
    }
}
signed main()
{
	chk();
    int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    // assert(~dp[0]);
    return 0;
}