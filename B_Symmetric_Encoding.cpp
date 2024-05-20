#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    set<char> st;
    for(auto& it:s)
    {
        st.insert(it);
    }
    vector<char>code(st.begin(),st.end());
    int sz=code.size();
    for(auto& it:s)
    {
        int temp;
        for(int j=0;j<sz;++j)
        {
            if(code[j]==it)temp=j;
        }
        cout<<code[sz-temp-1];
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