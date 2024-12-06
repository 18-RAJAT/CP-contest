#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,m;
    cin>>n>>m;
    vector<string>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int tot=0,count=0;
    for(int i=0;i<n;++i)
    {
        if(tot+a[i].size()<=m)
        {
            tot+=a[i].size();
            count++;
        }
        else break;
    }
    cout<<count<<endl;
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