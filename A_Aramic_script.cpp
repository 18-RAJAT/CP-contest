#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<set<char>>ans;
    while(n--)
    {
        string s;
        cin>>s;
        set<char>st;
        for(int i=0;i<s.size();++i)
        {
            st.insert(s[i]);
        }
        if(find(ans.begin(),ans.end(),st)==ans.end())
        {
            ans.push_back(st);
        }
    }
    cout<<ans.size();
}
signed main()
{
    sol();
    return 0;
}