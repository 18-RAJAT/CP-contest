#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    vector<int>a(n);
    set<int>st;
    multiset<int>ans;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        st.insert(a[i]%k);
        ans.insert(a[i]/k);
    }
    if(st.size()>=2)
    {
        cout<<"-1";
        return;
    }
    int res=0;
    for(auto&it:ans)
    {
        res+=it-*ans.begin();
    }
    cout<<res;
}
signed main()
{
    sol();
    return 0;
}