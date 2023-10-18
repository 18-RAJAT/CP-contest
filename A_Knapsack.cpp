#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,w;
    cin>>n>>w;
    pair<int,int>weight[n];
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        cin>>weight[i].first;
        weight[i].second=i+1;
    }
    sort(weight,weight+n);
    reverse(weight,weight+n);
    // ans.push_back(weight[0].second);
    int calc=0;
    for(int i=0;i<n;++i)
    {
        if(calc+weight[i].first<=w)
        {
            calc+=weight[i].first;
            ans.push_back(weight[i].second);
        }
    }
    if(w<=calc*2)
    {
        cout<<ans.size()<<endl;
        for(auto& it:ans)
        {
            cout<<it<<" ";
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
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