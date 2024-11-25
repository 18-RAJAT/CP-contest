#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;++i)cin>>a[i];
    int ans=0;
    for(int i=1;i<n;++i)if(a[i]>a[ans])ans=i;
    for(int i=ans-1;i>=0;--i)
    {
        if(a[i]>a[i+1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=ans+1;i<n;++i)
    {
        if(a[i]>a[i-1])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}
signed main()
{
    sol();
    return 0;
}