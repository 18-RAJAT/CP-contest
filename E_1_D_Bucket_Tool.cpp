#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,q;
    cin>>n>>q;
    vector<int>a(n+1,1);
    set<tuple<int,int,int>>st;
    for(int i=1;i<=n;++i)st.insert(make_tuple(i,i,i));
    auto interval=[&](int x)
    {
        auto it=st.upper_bound(make_tuple(x,1e9,1e9));
        if(it==st.begin())return st.end();
        --it;
        int s=get<0>(*it),e=get<1>(*it);
        if(s<=x && e>=x)return it;
        return st.end();
    };
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int x,c;
            cin>>x>>c;
            auto it=interval(x);
            if(it==st.end())continue;
            int s=get<0>(*it),e=get<1>(*it),col=get<2>(*it);
            if(col==c)continue;
            a[col]-=(e-s+1),a[c]+=(e-s+1);
            st.erase(it);
            int ns=s,ne=e;
            if(ns>=2)
            {
                auto L=interval(ns-1);
                if(L!=st.end() && get<2>(*L)==c && get<1>(*L)==ns-1)
                {
                    ns=get<0>(*L);
                    st.erase(L);
                }
            }
            if(ne<n)
            {
                auto R=interval(ne+1);
                if(R!=st.end() && get<2>(*R)==c && get<0>(*R)==ne+1)
                {
                    ne=get<1>(*R);
                    st.erase(R);
                }
            }
            st.insert(make_tuple(ns,ne,c));
        }
        else if(t==2)
        {
            int c;
            cin>>c;
            cout<<a[c]<<endl;
        }
    }
}
signed main()
{
    sol();
    return 0;
}