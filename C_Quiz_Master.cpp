#include<bits/stdc++.h>
using namespace std;
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<int>a(n),check(m+1,-1);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=1e9;
    multiset<int>ms;
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        for(int j=1;j*j<=a[i];++j)
        if(a[i]%j==0)
        {
            for(auto& k:{j,a[i]/j})
            {
                if(m<k)continue;
                if(~check[k])ms.erase(ms.find(check[k]));
                check[k]=i;
                ms.insert(check[k]);
            }
        }
        if(ms.size()==m)
        {
            ans=min(ans,a[*ms.rbegin()]-a[*ms.begin()]);
        }
    }
    if(ans==1e9)ans=-1;
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