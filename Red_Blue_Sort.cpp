#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int f=1,ans=0;
    for(int i=0;i<n;++i)
    {
        (a[i]!=i+1)?f=0:ans++;
    }
    if(f)cout<<n<<endl;
    else if(n==2)cout<<ans<<endl;
    else
    {
        cout<<(ans>=1?n-1:n-2)<<endl;
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