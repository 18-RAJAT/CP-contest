#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int q;
    cin>>q;
    multiset<pair<int,int>>mp;
    multiset<int>m;
    char c;
    int a,b;
    while(q--)
    {
        cin>>c>>a>>b;
        if(c=='+')
        {
            mp.insert(make_pair(a,b));
            m.insert(b);
        }
        else
        {
            mp.erase(mp.find(make_pair(a,b)));
            m.erase(m.find(b));
        }
        if(mp.empty())
        {
            cout<<"NO\n";
        }
        else if(*m.begin()<mp.rbegin()->first)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
    }
}
signed main()
{
    sol();
    return 0;
}