#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;cin>>n;
    vector<pair<int,int>>c(n);
    for(int i=0;i<n;++i)cin>>c[i].first>>c[i].second;
    int q;
    cin>>q;
    while(q--)
    {
        int x;cin>>x;
        for(int i=0;i<n;++i)
        {
            if(x>=c[i].first && x<=c[i].second)++x;
        }
        cout<<x<<endl;
    }
}
signed main()
{
    sol();
    return 0;
}