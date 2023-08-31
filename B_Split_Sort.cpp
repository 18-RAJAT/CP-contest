#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200001],b[200001];
int n;
void sol()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        b[a[i]]=i;
    }
    int ans=0;
    for(int i=1;i<n;++i)
    {
        if(b[i]>b[i+1])
        {
            // continue;
            ans++;
        }
    }
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