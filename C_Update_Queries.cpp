#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    string s,t;
    cin>>s;
    set<int>st;
    int j=0;
    for(int i=0;i<m;++i)
    {
        int x;
        cin>>x;
        st.insert(x);
    }
    cin>>t;
    sort(t.begin(),t.end());
    for(auto it=st.begin();it!=st.end();++it)
    {
        s[*it-1]=t[j++];
    }
    cout<<s<<endl;
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