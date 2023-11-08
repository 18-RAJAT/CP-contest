#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    // sort(a.begin(),a.end(),[&](int x,int y){return x>y;});
    sort(b.begin(),b.end(),[&](int x,int y){return x>y;});
    int ans=0;
    // assert(n<=m);
    for(int i=0;i<n;++i)
    {
        while(a[i]<=b[ans] && ans<m)
        {
            cout<<b[ans]<<" ";
            ans++;
        }
        cout<<a[i]<<" ";
    }
    // while(ans<m)
    // {
    //     cout<<b[ans]<<" ";
    //     ans++;
    // }
    // assert(ans==m);
    for(int i=ans;i<m;++i)
    {
        cout<<b[i]<<" ";
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