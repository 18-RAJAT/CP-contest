#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    if(n==1 || n==3)
    {
        cout<<"-1"<<endl;
        return;
    }
    string ans;
    if(n&1)
    {
        ans="66363",n-=5;
        for(int i=0;i<n;++i)
        {
            ans.push_back('3');
        }
    }
    else
    {
        ans="66",n-=2;
        for(int i=0;i<n;++i)
        {
            ans.push_back('3');
        }
    }
    ans=string(ans.rbegin(),ans.rend());
    // string(ans.reserve(n));
    cout<<ans<<endl;
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