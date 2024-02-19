#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>arr(n),ans(n);
    for(int i=0;i<n;++i)
    {
        cin>>arr[i];
    }
    string s;
    cin>>s;
    int left=0,right=n-1;
    for(int i=0;i<n;++i)
    {
        (s[i]=='L')?(ans[i]=arr[left],left++):(ans[i]=arr[right],right--);
    }
    int res=1;
    for(int i=n-1;~i;--i)
    {
        res=(res*ans[i]);
        res%=m;
        ans.push_back(res);
    }
    reverse(ans.begin(),ans.end());
    for(int i=0;i<n;++i)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
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