#include<bits/stdc++.h>
using namespace std;
#define int long long
void sol()
{
    int a[2],b[2];
    cin>>a[0]>>a[1]>>b[0]>>b[1];
    int ans=0;
    for(int i=0;i<2;++i)
    {
        for(int j=0;j<2;++j)
        {
            ans+=((a[i]>b[j])+(a[1-i]>b[1-j])>(a[i]<b[j])+(a[1-i]<b[1-j]));
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