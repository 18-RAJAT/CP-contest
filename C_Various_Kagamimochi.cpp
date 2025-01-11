#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int j=0;j<n;++j)
    {
        int UB=upper_bound(a.begin(),a.end(),a[j]/2)-a.begin();
        ans+=UB;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol(); 
    return 0;
}