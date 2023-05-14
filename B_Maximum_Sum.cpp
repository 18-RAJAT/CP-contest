#include<bits/stdc++.h>
using namespace std;

void sol()
{
    long long int n,k;
    cin>>n>>k;
    vector<long long int>arr(n,0);

    arr.resize(n+1);
    for(long long int i=1;i<=n;++i)
    {
        cin>>arr[i];
    }
    sort(arr.begin()+1,arr.end());
    for(long long int i=1;i<=n;++i)
    {
        arr[i]+=arr[i-1];
    }

    auto query=[&](long long int left,long long int right)->long long int
    {
        if(right<left)
        {
            return 0;
        }
        return arr[right]-arr[left-1];
    };
    long long int ans=0;
    
    for(long long int i=0;i<=k;++i)
    {
        long long int init=arr[n];
        init-=query(n-(k-i)+1,n);
        init-=arr[i*2];
        ans=max(ans,init);
    }
    cout<<ans<<'\n';
}
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        sol();
    }
    return 0;
}