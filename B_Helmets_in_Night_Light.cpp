#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,p;
    cin>>n>>p;
    vector<pair<int,int>>vp(n);
    for(auto&it:vp)
    {
        //first->cost of helmet
        cin>>it.second;
    }
    for(auto&it:vp)
    {
        //second->cost of sharing the announcement
        cin>>it.first;
    }
    sort(vp.begin(),vp.end());
    int calc=n-1;//announcements...
    int ans=p;
    for(auto&it:vp)
    {
        if(p<it.first)//not enough(guess)
        {
            break;
        }
        int minimum_cost=min(calc,it.second);//cost of helmet or cost of sharing the announcement
        calc-=minimum_cost;
        ans+=minimum_cost*it.first;//cost of sharing the announcement
    }
    cout<<ans+p*calc<<"\n";//ans+p->cost of sharing the announcement and calc->cost of helmet.
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