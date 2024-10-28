#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    //0=dp,1=ndp
    vector<int>dp(0),ndp(0);
    for(int i=0;i<n-1;++i)
    {
        if(s[i]=='0')dp.push_back(i);
        else ndp.push_back(i);
    }
    sort(ndp.begin(),ndp.end());
    reverse(ndp.begin(),ndp.end());
    int x=dp.size(),y=ndp.size();
    x--,y--;
    int precompute=n*(n+1)/2;
    for(int i=n-1;~i;--i)
    {
        for(;x>=0 && dp[x]>=i;--x);
        for(;y>=0 && ndp[y]>=i;--y);
        if(s[i]=='1')
        {
            // precompute-=(x>=0?i+1:0)+(y>=0?i+1:0),x-=(x>=0),y-=(y>=0);
            if(x>=0)precompute-=i+1,x--;
            // else precompute-=i+1;
            else if(y>=0)precompute-=i+1,y--;
            // (x>=0)?precompute-=i+1,x--:precompute-=i+1,y--;
            // precompute-=i+1,x>=0?x--:y--;
        }
    }
    cout<<precompute<<endl;
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