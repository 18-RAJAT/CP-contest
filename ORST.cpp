#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<m;++i)
    {
        cin>>b[i];
    }
    int order=0;
    auto valid=[&]()->void
    {
        for(int i=0;i<m;++i)
        {
            order=max<int>(order,b[i]);
        }
        // cout<<order<<endl;
    };
    valid();
    vector<int>ans;
    for(int i=0;i<n;++i)
    {
        int orst=n-order;
        // cout<<"orst: "<<orst<<endl;
        if(i<orst)
        {
            cout<<a[i]<<" ";
        }
        else
        {
            ans.push_back(a[i]);
        }
    }
    sort(ans.begin(),ans.end());
    for(auto& it:ans)
    {
        cout<<it<<" ";
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