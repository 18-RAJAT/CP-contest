#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    set<string>st;
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        st.insert(s);
    }
    for(int i=0;i<m;++i)
    {
        cin>>s;
        st.insert(s);
    }
    int cnt=0;
    for(int i=0;i<st.size();++i)
    {
        if(st.find(s)!=st.end())
        {
            cnt++;
        }
    }
    cout<<((n>m)?"YES":((n<m)?"NO":((cnt%2)?"YES":"NO")));
}
signed main()
{
    sol();
    return 0;
}