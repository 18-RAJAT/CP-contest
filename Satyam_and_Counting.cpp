#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x,y;
        cin>>x>>y;
        if(y==1)ans++;
    }
    cout<<2*ans<<endl;
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