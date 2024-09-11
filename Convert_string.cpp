#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    string s;
    cin>>n>>s;
    set<int>st;
    int zero=0,one=0;
    for(int i=0;i<n;++i)
    {
        if(s[i]=='0')zero++;
    }
    one=n-zero;
    for(int i=1;i<=n;++i)   
    {
        if(((i>=zero)&((i-zero)&1)==0) | ((i>=one)&((i-one)&1)==0))st.insert(i);
    }
    cout<<st.size()<<endl;
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