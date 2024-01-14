#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n);
    for(int i=0;i<n;++i)
    {
        int b,x;
        cin>>b>>x;
        (b==1?a[i]=x:a[i]=a[x-1]);
    }
    vector<int>ans(q);
    for(auto& it:ans)
    {
        cin>>it;
    }
    for(auto& it:ans)
    {
        cout<<a[(it-1)%n]<<' ';
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