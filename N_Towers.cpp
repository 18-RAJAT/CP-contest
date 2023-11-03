#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,x;
    cin>>n;
    multiset<int>st;
    for(int i=0;i<n;++i)
    {
        cin>>x;
        auto it=st.upper_bound(x);
        if(it!=st.end())
        {
            st.erase(it);
        }
        st.insert(x);
    }
    cout<<st.size()<<"\n";
}
signed main()
{
    sol();
    return 0;
}