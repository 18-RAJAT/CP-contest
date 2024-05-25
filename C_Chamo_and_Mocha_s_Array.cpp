#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&it:a)cin>>it;
    int ok=0;
    for(int i=2;i<=10;++i)
    {
        for(int j=0;j+i<=n;++j)
        {
            vector<int>v;
            for(int k=0;k<i;++k)
            {
                v.push_back(a[j+k]);
            }
            sort(v.begin(),v.end());
            ok=max(ok,v[(v.size()+1)/2-1]);
        }
    }
    cout<<ok<<endl;
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