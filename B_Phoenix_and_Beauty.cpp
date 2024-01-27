#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    set<int>st;
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    int sz=st.size();
    if(k<sz)
    {
        cout<<-1<<endl;
        return;
    }
    cout<<n*k<<endl;
    for(int i=0;i<n;++i)
    {
        for(auto it:st)
        {
            cout<<it<<" ";
        }
        for(int j=0;j<k-sz;++j)
        {
            cout<<1<<" ";
        }
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