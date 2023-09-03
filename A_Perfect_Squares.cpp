#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    int n;
    cin>>n;
    set<int>st;
    st.insert(0);
    for(int i=0;i<n;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    for(int i=0;i*i<=10000000;++i)
    {
        st.erase(i*i);
    }
    cout<<*st.rbegin()<<endl;
    return 0;
}