#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    map<int,int>mp,color;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        color[a[i]]++;
        if(k<color[a[i]])
        {
            cout<<"NO";
            return;
        }
    }
    vector<int>arr[5005];
    int ans=0;
    for(int i=0;i<n;++i)arr[a[i]].push_back(i);
    for(auto& it:arr)
    {
        for(auto& i:it)
        {
            color[i]=++ans,ans%=k;
        }
    }
    cout<<"YES"<<endl;
    for(int i=0;i<n;++i)cout<<color[i]<<" ";
}
signed main()
{
    sol();
    return 0;
}