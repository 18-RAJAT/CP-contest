#include<bits/stdc++.h>
using namespace std;
#define int long long
int check[200001];
void sol()
{
    
    int n,k;
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;++i)
    {
        cin>>b[i];
    }
    int ans=0,ans1=0,ans2=0;
    for(int i=0;i<n;++i)
    {
        if(i==k)
        {
            break;
        }
        ans+=a[i];
        ans1=max(ans1,b[i]);
        ans2=max(ans2,ans+(k-i-1)*ans1);
    }
    cout<<ans2<<endl;
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