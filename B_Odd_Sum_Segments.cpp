#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>ans;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        sum+=x;
        if(sum&1)
        {
            sum=0,ans.push_back(i);
        }
    }
    if(sum>=1 && !ans.empty())
    {
        ans.pop_back();
        ans.push_back(n);
    }
    if(((ans.size()<k) || (ans.size()-k)&1))
    {
        cout<<"NO"<<endl;
        return;
    }
    else
    {
        cout<<"YES"<<endl;
        for(int i=0;i<k-1;++i)
        {
            cout<<ans[i]<<" ";
        }
        cout<<n<<endl;
    }
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