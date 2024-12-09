#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n,k,id=-1;
    cin>>n>>k;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    bool ok=false;
    for(int i=0;i<n;++i)
    {
        bool win=true;
        for(int j=0;j<n;++j)
        {
            if(i!=j && abs(a[i]-a[j])%k==0)
            {
                win=false;
                break;
            }
        }
        if(win)
        {
            ok=true;
            id=i+1;
            break;
        }
    }
    if(ok)cout<<"YES"<<endl<<id<<endl;
    else cout<<"NO"<<endl;
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