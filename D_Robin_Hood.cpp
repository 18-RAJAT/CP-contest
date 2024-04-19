#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>citizens(n);
    for(int i=0;i<n;++i)
    {
        cin>>citizens[i];
    }
    sort(citizens.begin(),citizens.end());
    int ans=0;
    for(int i=0;i<n;++i)
    {
        int x=min(k,citizens[i]);
        ans+=x;
        k-=x;
    }
    cout<<citizens[n-1]-ans-1;
}
signed main()
{
    sol();
    return 0;
}