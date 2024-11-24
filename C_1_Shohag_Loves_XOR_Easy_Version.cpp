#include<bits/stdc++.h>
using namespace std;
#define int long long

//Template Rajat-Joshi
vector<int>Divs(int x)
{
    vector<int>div;
    for(int d=1;d*d<=x;++d)
    {
        if(x%d==0)
        {
            div.push_back(d);
            if(d!=x/d)div.push_back(x/d);
        }
    }
    // sort(div.begin(),div.end());
    return div;
}
void sol()
{
    int x,m;
    cin>>x>>m;
    vector<int>div=Divs(x);
    unordered_set<int>st(div.begin(),div.end());
    int ans=0;
    // for(auto& it:div)
    // {
    //     int tmp=x^it;
    //     if(tmp>=1 && tmp<=m && tmp!=x)ans++;
    // }
    // int mn=min<int>(m,2000000LL);
    // for(int i=1;i<=mn;++i)
    // {
    //     if(i==x)continue;
    //     int tmp=x^i;
    //     if(tmp==0)continue;
    //     if(binary_search(div.begin(),div.end(),tmp))continue;
    //     if(i%tmp==0)ans++;
    // }
    // cout<<ans<<endl;
    for(auto& it:div)
    {
        int tmp=x^it;
        if(tmp>=1 && tmp<=m && tmp!=x)ans++;
    }
    for(int i=1;i<=x;++i)
    {
        // if(st.count(i))continue;
        if(st.find(i)==st.end())
        {
            int tmp=x^i;
            if(tmp>=1 && tmp<=m && tmp!=x && tmp%i==0)ans++;
        }
    }
    cout<<ans<<endl;
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