#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    vector<int>sa=a;
    sort(sa.begin(),sa.end());
    sa.erase(unique(sa.begin(),sa.end()),sa.end());
    int X=0;
    for(int i=0;i<n;++i)X^=a[i];
    if(!binary_search(sa.begin(),sa.end(),X))
    {
        sa.push_back(X);
        sort(sa.begin(),sa.end());
    }
    int ans=0;
    for(auto& it:sa)
    {
        int x=it,res=0;
        for(int i=0;i<n;++i)
        {
            (x==a[i])?res+=a[i]:x^=a[i];
        }
        ans=max(ans,res);
    }
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