#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    vector<array<int,2>>a(4);
    for(int i=0;i<4;++i)
    {
        cin>>a[i][0]>>a[i][1];
    }
    sort(a.begin(),a.end());
    int f=a[0][0],s=a[0][1];
    int ans=max(a[3][0]-f,a[3][1]-s);
    cout<<ans*ans<<endl;
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