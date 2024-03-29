#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
vector<int>dp(N);
void sol()
{
    auto check=[&](int x)
    {
        string s=to_string(x);
        return *max_element(begin(s),end(s))<='1';
    };
    for(int i=1;i<N;++i)
    {
        dp[i]=check(i);
        for(int j=2;j*j<=i;++j)
        {
            if(i%j==0)
            {
                dp[i]|=(dp[j]&dp[i/j]);
            }
        }
    }
}
signed main()
{
    sol();
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<((dp[n])?"YES":"NO")<<endl;
    }
    return 0;
}