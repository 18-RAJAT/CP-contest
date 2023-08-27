#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),chk;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    reverse(a.begin(),a.end());
    for(int i=1;i<=n;++i)
    {
        auto lb=lower_bound(a.begin(),a.end(),i);
        chk.push_back(a.end()-lb);
    }
    reverse(a.begin(),a.end());
    cout<<((a==chk)?"YES":"NO")<<endl;
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