#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int freq[1005]={0};
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        freq[x]++;
    }
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        freq[x]++;
    }
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        freq[x]++;
    }
    int ans=0;
    for(int i=1000;i>=1 && ~n;--i)
    {
        if(freq[i]==0)continue;
        int mn=min(freq[i],n);
        ans+=i*mn;
        n-=mn;
    }
    cout<<ans<<endl;
}
signed main()
{
    sol();
    return 0;
}