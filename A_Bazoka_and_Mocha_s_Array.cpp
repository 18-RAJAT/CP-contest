#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;
    cin>>n;
    vector<int>a(n);
    for(auto&it:a)cin>>it;
    for(int i=0;i<n;++i)
    {
        bool ok=true;
        for(int j=1;j<n;++j)
        {
            int x=(i+j-1)%n;
            int y=(i+j)%n;
            if(a[y]<a[x])ok=false;
        }
        if(ok){cout<<"Yes"<<endl;return;}
    }
    cout<<"No"<<endl;return;
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