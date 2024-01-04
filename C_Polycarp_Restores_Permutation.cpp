#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n+1],b[n+1];
    for(int i=1;i<n;++i)
    {
        cin>>a[i];
    }
    int sum=0;
    for(int i=1;i<n;++i)
    {
        sum+=a[i];
        b[i]=sum;
    }
    int mn=INT_MAX;
    for(int i=1;i<n;++i)
    {
        mn=min<int>(mn,b[i]);
    }
    (mn>0)?b[0]=1:b[0]=1+abs<int>(mn);
    for(int i=1;i<n;++i)
    {
        b[i]=b[i-1]+a[i];
    }
    auto pnc=[&](int arr[],int n)->bool
    {
        set<int>st;
        st.clear();
        int mx=0;
        for(int i=0;i<n;++i)
        {
            mx=max<int>(mx,arr[i]);
            st.insert(arr[i]);
        }
        if(mx!=n)
        {
            return false;
        }
        if(st.size()!=n)
        {
            return false;
        }
        return true;
    };
    if(!pnc(b,n))
    {
        cout<<"-1"<<endl;
        return;
    }
    for(int i=0;i<n;++i)
    {
        cout<<b[i]<<" ";
    }
}
signed main()
{
    sol();
    return 0;
}