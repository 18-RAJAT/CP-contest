#include<bits/stdc++.h>
using namespace std;
#define int long long
int mod=998244353;
void sol()
{
    int n,k;
    cin>>n>>k;
    int first=n,second=k;
    int ans=0;
    set<int>st;
    while(second--)
    {
        ans+=first;
        st.insert(first);
        // first=n-ans;
        first-=1;
    }
    vector<int>a(n),chkIdx;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        if(st.find(a[i])!=st.end())
        {
            chkIdx.push_back(i);
        }
    }
    function<int(int,int,int&)>mul=[&](int x,int y,int& mod)->int
    {
        return((x%mod)*(y%mod))%mod;
    };
    int cnt=1;
    for(int i=0;i<chkIdx.size()-1;++i)
    {
        cnt=mul(cnt,chkIdx[i+1]-chkIdx[i],mod);
    }
    cout<<ans<<" "<<cnt<<"\n";
}
signed main()
{
    sol();
    return 0;
}