#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n),b;
    for(auto&it:a)cin>>it;
    sort(a.begin(),a.end());
    for(int i=0;i<n;++i)
    {
        bool ok=false;
        for(auto& it:b){if(a[i]%it==0)ok=true;}
        if(!ok)
        {
            b.push_back(a[i]);
            if(b.size()>=3){cout<<"No"<<endl;return;}
        }
    }
    cout<<"Yes"<<endl;
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