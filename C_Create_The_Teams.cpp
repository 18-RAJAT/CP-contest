#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>array(n);
    for(int i=0;i<n;++i)
    {
        cin>>array[i];
    }
    sort(array.rbegin(),array.rend());
    int ans=0,minimum=1e18,sum=0;
    for(int i=0;i<n;++i)
    {
        minimum=min(minimum,array[i]);
        sum++;
        if(minimum*sum>=x)
        {
            minimum=1e18;
            sum=0;
            ans++;
        }
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