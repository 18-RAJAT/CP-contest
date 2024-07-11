#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    string s;
    cin>>s;
    int n=s.size();
    deque<char>d;
    set<string>st;
    for(auto& it:s)d.push_back(it);
    while(n--)
    {
        auto last=d.back();
        d.pop_back();
        d.push_front(last);
        string t;
        for(auto& it:d)t+=it;
        st.insert(t);
    }
    cout<<st.size();
}
signed main()
{
    sol();
    return 0;
}