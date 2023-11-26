#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n>>x;
    vector<int>a(n),b(n),arr(n),brr(n),find(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        // arr[i]=a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
        // brr[i]=b[i];
    }
    iota(arr.begin(),arr.end(),0);
    iota(brr.begin(),brr.end(),0);
    sort(arr.begin(),arr.end(),[&](int i,int j){return a[i]<a[j];});
    // sort(brr.begin(),brr.end(),[&](int i,int j){return b[i]<b[j];});
    sort(b.begin(),b.end());
    int pos=0;
    for(int i=n-x;i<n;++i)
    {
        find[arr[i]]=b[pos++];
    }
    for(int i=0;i<n-x;++i)
    {
        find[arr[i]]=b[pos++];
    }
    int ans=0;
    for(int i=0;i<n;++i)
    {
        // ans+=a[i]*find[i];
        if(a[i]>find[i])
        // {
        //     ans+=a[i]-find[i];
        // }
        // else
        // {
        //     ans+=find[i]-a[i];
        // }
        ans++;
    }
    if(ans==x)
    {
        cout<<"YES"<<endl;
        for(auto& it:find)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
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