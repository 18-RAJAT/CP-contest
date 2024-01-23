#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k;
    cin>>n>>k;
    int each=n/k;
    int rem=n%k;
    string ans="abcdefghijklmnopqrstuvwxyz";
    for(int i=0;i<k;++i)
    {
        for(int j=0;j<each;++j)
        {
            cout<<ans[i];
        }
    }
    for(int i=0;i<rem;++i)
    {
        cout<<ans[i];
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