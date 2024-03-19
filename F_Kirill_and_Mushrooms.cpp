#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int mn=1e9,ans=0,total=1e9;
    set<pair<int,int>>st;
    for(int i=n-1;~i;--i)
    {
        st.insert(make_pair(a[b[i]-1],i));
        while(i+1<st.size())
        {
            st.erase(st.begin());
        }
        if(ans<(*st.begin()).first*st.size())
        {
            ans=(*st.begin()).first*st.size(),total=st.size();
        }
        else if((*st.begin()).first*st.size()==ans)
        {
            total=min(total,(int)st.size());
        }
    }
    st.clear();
    cout<<ans<<" "<<total<<endl;
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