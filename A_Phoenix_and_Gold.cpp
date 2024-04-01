#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n);
    int Sum=0;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        Sum+=a[i];
    }
    if(Sum==x)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    Sum=0;
    for(int i=0;i<n;++i)
    {
        if(Sum+a[i]==x)
        {
            swap(a[i],a[i+1]);
        }
        cout<<a[i]<<" ";
        Sum+=a[i];
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