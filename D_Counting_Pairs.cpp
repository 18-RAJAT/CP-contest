#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x,y;
    cin>>n>>x>>y;
    vector<int>a(n);
    int sum=0;
    for(auto &it:a)
    {
        cin>>it;
        sum+=it;
    }
    int A=sum-y,B=sum-x,ans=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n-1;++i)
    {
        int L=A-a[i],R=B-a[i];
        int LB=lower_bound(a.begin()+i+1,a.end(),L)-a.begin();
        int UB=upper_bound(a.begin()+i+1,a.end(),R)-a.begin();
        ans+=(UB-LB);
    }
    cout<<ans<<endl;
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